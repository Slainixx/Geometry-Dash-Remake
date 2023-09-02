#include <iostream>
#include <string>

class RewardObject {
public:
    RewardObject(const std::string& type, int value)
        : type(type), value(value) {}

    void collect() {
        std::cout << "Collected " << value << " " << type << std::endl;
        // Add logic to handle the reward collection, such as updating player stats.
    }

private:
    std::string type;
    int value;
};

int main() {
    // Create a reward object
    RewardObject reward("Coins", 100);

    // Simulate collecting the reward
    reward.collect();

    return 0;
}
