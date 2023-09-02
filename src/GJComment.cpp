#include <iostream>
#include <string>

class Comment {
public:
    Comment(const std::string& username, const std::string& content)
        : username(username), content(content) {}

    void display() const {
        std::cout << username << std::endl;
        std::cout << content << std::endl;
    }
};

int main() {
    std::string customUsername, customComment;

    // Input custom username
    std::cout << "Enter your username: ";
    std::cin >> customUsername;

    // Input custom comment
    std::cout << "Enter your comment: ";
    std::cin.ignore();  // Clear newline from previous input
    std::getline(std::cin, customComment);

    // Create a comment with custom input
    Comment comment(customUsername, customComment);

    // Display the custom comment
    comment.display();

    return 0;
}
