#include <iostream>
#include <string>
#include <vector>

class User {
public:
    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

    const std::string& getUsername() const { return username; }
    bool checkPassword(const std::string& inputPassword) const { return password == inputPassword; }

private:
    std::string username;
    std::string password;
};

class AccountManager {
public:
    bool registerUser() {
        std::string username, password;

        std::cout << "Enter a username: ";
        std::cin >> username;

        for (const User& user : users) {
            if (user.getUsername() == username) {
                std::cout << "Username already exists. Please choose another one." << std::endl;
                return false;
            }
        }

        std::cout << "Enter a password: ";
        std::cin >> password;

        users.emplace_back(username, password);
        std::cout << "User registered successfully." << std::endl;
        return true;
    }

    bool login() {
        std::string username, password;

        std::cout << "Enter your username: ";
        std::cin >> username;

        std::cout << "Enter your password: ";
        std::cin >> password;

        for (const User& user : users) {
            if (user.getUsername() == username && user.checkPassword(password)) {
                std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
                return true;
            }
        }

        std::cout << "Invalid username or password. Please try again." << std::endl;
        return false;
    }

private:
    std::vector<User> users;
};

int main() {
    AccountManager accountManager;

    char choice;
    bool loggedIn = false;

    while (!loggedIn) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case '1':
            accountManager.registerUser();
            break;
        case '2':
            loggedIn = accountManager.login();
            break;
        case '3':
            return 0;
        default:
            std::cout << "Invalid. Please try again." << std::endl;
            break;
        }
    }

    // Perform actions for a logged-in user here

    return 0;
}
