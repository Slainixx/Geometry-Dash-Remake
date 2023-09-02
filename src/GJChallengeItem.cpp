#include <iostream>
#include <string>

class ChallengeItem {
public:
    ChallengeItem(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    void display() const {
        std::cout << "Challenge Name: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
    }

private:
    std::string name;
    std::string description;
};

int main() {
    // Create a challenge item
    ChallengeItem challenge("My Challenge", "Complete a difficult level!");

    // Display the challenge item
    challenge.display();

    return 0;
}
s