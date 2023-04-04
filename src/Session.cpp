

#include "Session.h"

const std::string session_info::help(
        "List of commands:"
        "sign-in   ------"
        "sign-up   ------"
        "income    ------"
        "costs     ------"
        "show      ------"
        "report    ------"
        "logout    ------"
        "exit      ------"
);

const std::string session_info::input_line(">>>");
const std::string session_info::start_message("Chose option, and write it in terminal\nsign-in\nsing-up\n");

void Session::run() {
    using sql_user = SqliteDataBaseService<User, std::size_t>;
    using sql_permission = SqliteDataBaseService<Permission, std::size_t>;
    using sql_budget_group = SqliteDataBaseService<BudgetGroup, std::size_t>;
    using sql_budget_info = SqliteDataBaseService<BudgetInfo, std::size_t>;

    std::string command;
    std::string user_name;

    auto input_style = fmt::fg(fmt::color::white) | fmt::emphasis::bold;
    auto wrong_input_style = fmt::fg(fmt::color::red) | fmt::emphasis::bold;
    fmt::print(input_style, session_info::start_message);


    fmt::print(input_style, session_info::input_line);

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
        fmt::print(input_style, "Input user name: ");
        std::cin >> user_name;
        fmt::print(input_style, "Input password: ");
        password_input.input();
        password = password_input.getPassword();
        Login login(user_name, password);


        while (!login.isUserNameCorrect()) {
            fmt::print(wrong_input_style, "Wrong user name dont exists user: {}\nRe-input user_name (attempts - {}) :",
                       user_name, attempt.getAttempt());
            tryAttempts();
            std::cin >> user_name;
        }
        while (!login.isPasswordCorrect()) {
            fmt::print(wrong_input_style, "Wrong password for user {} : {}\nRe-input password (attempts - {}) :",
                       user_name, attempt.getAttempt());
            tryAttempts();
            password_input.input();
        }


    }

    attempt.reset();
    if (boost::regex_match(command, commands::sign_up)) {
        [[maybe_unused]] std::string password, check_password;
        fmt::print(input_style, "Create user name: ");
        std::cin >> user_name;
        fmt::print("\n");
        while (SignUp::isUserNameAlreadyExists(user_name)) {
            fmt::print(wrong_input_style, "Sorry, user with name {} already exists, try another name: ", user_name);
            tryAttempts();
            std::cin >> user_name;
        }
        attempt.reset();
        PasswordInput password_input, check_password_input;

        fmt::print(input_style, "Create password : ");
        password_input.input();
        password = password_input.getPassword();
        fmt::print("Repeat password : ");
        check_password_input.input();
        check_password = check_password_input.getPassword();
        while (password != check_password) {
            fmt::print(wrong_input_style, "Passwords do not match, re-input password: ");
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
    }

    std::size_t current_user_id = sql_user::getInstance().getId(user_name);

    fmt::print(fmt::runtime(session_info::help));

    while (!boost::regex_match(command, commands::exit)) {
        if (boost::regex_match(command, commands::income)) {

        } else if (boost::regex_match(command, commands::show)) {

        } else if (boost::regex_match(command, commands::report)) {

        } else if (boost::regex_match(command, commands::logout)) {

        } else if (boost::regex_match(command, commands::help)) {

        } else if (boost::regex_match(command, commands::costs)) {

        }
    }

}