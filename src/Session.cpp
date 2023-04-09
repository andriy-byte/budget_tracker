

#include <boost/lexical_cast.hpp>
#include "Session.h"

const std::string session_info::help(
        "List of commands:\n"
        "sign-in   ------ register new user\n"
        "sign-up   ------ login with exists user\n"
        "income    ------ add money to budget\n"
        "costs     ------ subtract money from budget\n"
        "show      ------ show current budget balance\n"
        "report    ------ show budget history between two dates\n"
        "exit      ------ exit from program\n"
        "clear     ------ clear console\n"
);

const std::string session_info::input_line(">>> ");
const std::string session_info::start_message("Chose option, and write it in terminal\nsign-in\nsing-up\n");

void Session::run() {
    using sql_user = SqliteDataBaseService<User, std::size_t>;
    using sql_permission = SqliteDataBaseService<Permission, std::size_t>;
    using sql_budget_group = SqliteDataBaseService<BudgetGroup, std::size_t>;
    using sql_budget_info = SqliteDataBaseService<BudgetInfo, std::size_t>;

    sql_budget_info::getInstance().connect();
    sql_user::getInstance().connect();
    sql_permission::getInstance().connect();
    sql_budget_group::getInstance().connect();

    sql_budget_info::getInstance().create();
    sql_user::getInstance().create();
    sql_permission::getInstance().create();
    sql_budget_group::getInstance().create();

    std::string command;
    std::string user_name;
    bool passed;
    auto input_style = fmt::fg(fmt::color::white) | fmt::emphasis::bold;
    auto wrong_input_style = fmt::fg(fmt::color::red) | fmt::emphasis::bold;
    fmt::print(input_style, session_info::start_message);


    fmt::print(input_style, session_info::input_line);
    std::cin >> command;

    Attempt attempt(3);

    auto tryAttempts = [&]() {
        attempt--;
        if (attempt.isExhausted()) {
            fmt::print(input_style, "\nYou have exhausted all attempts. Program will bee exit in 5 seconds");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::terminate();
        }
    };
    if (boost::regex_match(command, commands::sign_in)) {
        PasswordInput password_input;
        std::string user_name, password;
        fmt::print(input_style, "\nInput user name: ");
        std::cin >> user_name;
        fmt::print(input_style, "\nInput password: ");
        password_input.input();
        password = password_input.getPassword();
        Login login(user_name, password);


        while (login.isUserNameCorrect()) {
            fmt::print(wrong_input_style,
                       "\nWrong user name dont exists user: {}\nRe-input user_name (attempts - {}) :",
                       user_name, attempt.getAttempt());
            tryAttempts();
            std::cin >> user_name;
        }
        while (login.isPasswordCorrect()) {
            fmt::print(wrong_input_style, "\nWrong password for user {} : {}\nRe-input password (attempts - {}) :",
                       user_name, attempt.getAttempt());
            tryAttempts();
            password_input.input();
        }
        passed = true;
    }

    attempt.reset();
    if (boost::regex_match(command, commands::sign_up)) {
        [[maybe_unused]] std::string password, check_password;
        fmt::print(input_style, "\nCreate user name: ");
        std::cin >> user_name;
        fmt::print("\n");
        while (SignUp::isUserNameAlreadyExists(user_name)) {
            fmt::print(wrong_input_style, "\nSorry, user with name {} already exists, try another name: ", user_name);
            tryAttempts();
            std::cin >> user_name;
        }
        attempt.reset();
        PasswordInput password_input, check_password_input;

        fmt::print(input_style, "\nCreate password : ");
        password_input.input();
        password = password_input.getPassword();
        fmt::print(input_style, "\nRepeat password : ");
        check_password_input.input();
        check_password = check_password_input.getPassword();
        while (password != check_password) {
            fmt::print(wrong_input_style, "\nPasswords do not match, re-input password: ");
            tryAttempts();
            check_password_input.input();
            check_password = check_password_input.getPassword();
        }
        sql_user::getInstance().insert(User{.name=user_name});
        sql_permission::getInstance().insert(
                Permission{
                        .user_id = sql_user::getInstance().getId(user_name),
                        .password = password,
                });
        passed = true;
    }


    if (passed) {
        std::size_t current_user_id = sql_user::getInstance().getId(user_name);

        while (!boost::regex_match(command, commands::exit)) {
            fmt::print(input_style, session_info::input_line);
            std::cin >> command;
            if (boost::regex_match(command, commands::income)) {
                fmt::print(input_style, "\nInput money quantity :");
                double money;
                std::cin >> money;
                Datetime datetime;
                sql_budget_info::getInstance().insert(
                        BudgetInfo{
                                .id=current_user_id,
                                .money=money,
                                .date_time=datetime.now()
                        });

            } else if (boost::regex_match(command, commands::show)) {
                BudgetInfo budget_info = sql_budget_info::getInstance().get(current_user_id);
                fmt::print(input_style, "\nMoney quantity : {}", budget_info.money);
                fmt::print(input_style, "\nLatest modification : {}", budget_info.date_time);
            } else if (boost::regex_match(command, commands::report)) {
                std::string from, to;
                fmt::print(input_style, "\nFrom date time (yyyy-mm-dd) : ");
                std::cin >> from;
                fmt::print(input_style, "\nTo date time (yyyy-mm-dd) : ");
                std::cin >> to;

                boost::gregorian::date from_date, to_date;
                try {
                    from_date = boost::gregorian::date_from_iso_string(boost::replace_all_copy(from, "-", ""));
                    to_date = boost::gregorian::date_from_iso_string(boost::replace_all_copy(to, "-", ""));
                } catch (std::out_of_range &e) {
                    fmt::print("{}", e.what());
                    break;
                }

                for (auto &i: sql_budget_info::getInstance().getBetweenDatesById(current_user_id,
                                                                                 to_sql_string(from_date),
                                                                                 to_sql_string(to_date))) {
                    fmt::print(input_style, "Money status : {}\n", i.money);
                    fmt::print(input_style, "Date of modification : {}\n", i.date_time);

                }

            } else if (boost::regex_match(command, commands::help)) {
                fmt::print("{}", session_info::help);
            } else if (boost::regex_match(command, commands::costs)) {
                BudgetInfo budget_info = sql_budget_info::getInstance().get(current_user_id);
                double costs;
                Datetime datetime;
                fmt::print(input_style, "\nInput costs : ");
                std::cin >> costs;
                sql_budget_info::getInstance().insert(
                        BudgetInfo{.money = budget_info.money - costs, .date_time=datetime.now()});

            }else if(boost::regex_match(command, commands::clear)) {
#if BOOST_OS_WINDOWS
                std::system("cls");
#else
                std::system("clear");
#endif
            }
            else {
                fmt::print(input_style, "\nDon't exists command {}", command);
            }
        }
    } else{
        fmt::print(input_style,"\nYou need to Sign-in or Sign-up ");
    }


}