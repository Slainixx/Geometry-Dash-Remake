#include <iostream>
#include <string>

class RewardItem {
public:
    RewardItem(const std::string& name, int coins)
        : name(name), coins(coins) {}

    void display() const {
        std::cout << "Reward Name: " << name << std::endl;
        std::cout << "Coins: " << coins << std::endl;
    }

private:
    std::string name;
    int coins;
};

int main() {
    // Create a reward item
    RewardItem reward("Golden Chest", 100);

    // Display the reward item
    reward.display();

    return 0;
}
