

#include <boost/lexical_cast.hpp>
#include "Session.h"

const std::string session_info::help(
        "\nList of commands:\n"
        "income    ------ add money to budget\n"
        "costs     ------ subtract money from budget\n"
        "show      ------ show current budget balance\n"
        "exit      ------ exit from program\n"
        "clear     ------ clear console\n"
);


const std::string session_info::input_line("\n\n>>> ");
const std::string session_info::start_message("\nChose option, and write it in terminal\n"
                                              "sign-in   ------ register new user\n"
                                              "sign-up   ------ login with exists user\n");


void Session::dataBaseConnect() {
    sql_budget_info::getInstance().connect();
    sql_user::getInstance().connect();
    sql_permission::getInstance().connect();
    sql_budget_group::getInstance().connect();

    sql_budget_info::getInstance().create();
    sql_user::getInstance().create();
    sql_permission::getInstance().create();
    sql_budget_group::getInstance().create();
}


void Session::run() {

    this->dataBaseConnect();


    std::string command;
    std::string user_name;
    bool passed = false;

    auto input_style = fmt::fg(fmt::color::white) | fmt::emphasis::bold;
    auto wrong_input_style = fmt::fg(fmt::color::red) | fmt::emphasis::bold;
    auto success_operation = fmt::fg(fmt::color::green) | fmt::emphasis::bold;

    fmt::print(input_style, session_info::start_message);


    Attempt attempt(3);
    auto tryAttempts = [&]() {
        attempt--;
        if (attempt.isExhausted()) {
            fmt::print(input_style, "\nYou have exhausted all attempts. The program terminates.\n");
            std::exit(0);
        }
    };
    auto cls = []() {
#if BOOST_OS_WINDOWS
        std::system("cls");
#else
        std::system("clear");
#endif
    };

    while (!passed) {
        fmt::print(input_style, session_info::input_line);
        std::cin >> command;

        if (boost::regex_match(command, commands::sign_in)) {
            PasswordInput password_input;
            std::string password;
            fmt::print(input_style, "\nInput user name: ");
            std::cin >> user_name;
            fmt::print(input_style, "\nInput password: ");
            password_input.input();
            password = password_input.getPassword();
            Login login(user_name, password);


            while (!login.isUserNameCorrect()) {
                tryAttempts();
                fmt::print(wrong_input_style,
                           "\nWrong user name don't exists user: {}\nRe-input user_name (attempts - {}) :",
                           user_name, attempt.getAttempt());
                std::cin >> user_name;
            }
            attempt.reset();
            while (!login.isPasswordCorrect()) {
                tryAttempts();
                fmt::print(wrong_input_style, "\nWrong password for user {} : {}\nRe-input password (attempts - {}) :",
                           user_name, attempt.getAttempt());
                password_input.input();
            }
            passed = true;
            attempt.reset();

        } else if (boost::regex_match(command, commands::sign_up)) {
            [[maybe_unused]] std::string password, check_password;
            fmt::print(input_style, "\nCreate user name: ");
            std::cin >> user_name;
            fmt::print("\n");
            while (SignUp::isUserNameAlreadyExists(user_name)) {
                tryAttempts();
                fmt::print(wrong_input_style, "\nSorry, user with name {} already exists, try another name: ",
                           user_name);
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
                tryAttempts();
                fmt::print(wrong_input_style, "\nPasswords do not match, re-input password (attempts - {}): ",
                           attempt.getAttempt());
                check_password_input.input();
                check_password = check_password_input.getPassword();
            }
            sql_user::getInstance().insert(User{.name=user_name});
            sql_permission::getInstance().insert(
                    Permission{
                            .user_id = sql_user::getInstance().getId(user_name),
                            .password = Authorization::encrypt(password),
                    });
            passed = true;
            attempt.reset();

        } else if (boost::regex_match(command, commands::clear)) {
            cls();
            fmt::print(input_style, session_info::start_message);
        } else {
            fmt::print(input_style, "\nYou need to Sign-in or Sign-up \n");
        }
    }

    if (passed) {
        std::size_t current_user_id = sql_user::getInstance().getId(user_name);
        cls();
        fmt::print(input_style, "\n\n Welcome {}\n\n", user_name);
        fmt::print(input_style, session_info::help);
        while (true) {
            fmt::print(input_style, session_info::input_line);
            std::cin >> command;
            if (boost::regex_match(command, commands::income)) {
                fmt::print(input_style, "\nInput money quantity : ");
                double money;
                std::cin >> money;
                Datetime datetime;
                sql_budget_info::getInstance().insert(
                        BudgetInfo{
                                .id=current_user_id,
                                .money =money + sql_budget_info::getInstance().get(current_user_id).money,
                                .date_time=datetime.now()
                        });
                fmt::print(success_operation, "\nThe operation was successful.\n");
            } else if (boost::regex_match(command, commands::show)) {
                if (sql_budget_info::getInstance().exists(current_user_id)) {
                    BudgetInfo budget_info = sql_budget_info::getInstance().get(current_user_id);
                    fmt::print(input_style, "\nMoney quantity : {}", budget_info.money);
                    fmt::print(input_style, "\nLatest modification : {}", budget_info.date_time);
                } else {
                    fmt::print(wrong_input_style, "\nDoesn't exists any information\n");
                }
            } else if (boost::regex_match(command, commands::help)) {
                fmt::print(input_style, "{}", session_info::help);
            } else if (boost::regex_match(command, commands::costs)) {
                if (sql_budget_info::getInstance().exists(current_user_id)) {
                    BudgetInfo budget_info = sql_budget_info::getInstance().get(current_user_id);
                    double costs, total;
                    fmt::print(input_style, "\nInput costs : ");
                    std::cin >> costs;
                    total = sql_budget_info::getInstance().get(current_user_id).money - costs;
                    if (total >= 0) {
                        Datetime datetime;
                        sql_budget_info::getInstance().insert(
                                BudgetInfo{
                                        .id=current_user_id,
                                        .money = total,
                                        .date_time=datetime.now()
                                });
                        fmt::print(success_operation, "\nThe operation was successful.\n");
                    } else {
                        fmt::print(wrong_input_style, "\nThere is not enough money in the budget.\n");
                    }
                } else {
                    fmt::print(wrong_input_style, "\nDoesn't exists any information\n");
                }
            } else if (boost::regex_match(command, commands::clear)) {
                cls();
            } else if (boost::regex_match(command, commands::exit)) {
                fmt::print(input_style, "\nExit from program.\n");
                std::exit(0);
            } else {
                fmt::print(input_style, "\nDon't exists command {}\n", command);
            }
        }

    }
}

