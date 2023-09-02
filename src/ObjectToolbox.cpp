#include <iostream>
#include <vector>

class GameObject {
public:
    GameObject(int id) : id(id) {}

    void display() const {
        std::cout << "Object ID: " << id << std::endl;
    }

private:
    int id;
};

class ObjectToolbox {
public:
    void createObject(int id) {
        // Create a new game object and add it to the toolbox (simplified)
        GameObject object(id);
        objects.push_back(object);
    }

    void listObjects() const {
        // List all objects in the toolbox (simplified)
        std::cout << "Objects in the toolbox:" << std::endl;
        for (const auto& object : objects) {
            object.display();
        }
    }

private:
    std::vector<GameObject> objects;
};

int main() {
    // Create an ObjectToolbox instance
    ObjectToolbox toolbox;

    // Create and add objects to the toolbox
    toolbox.createObject(1);
    toolbox.createObject(2);
    toolbox.createObject(3);

    // List objects in the toolbox
    toolbox.listObjects();

    return 0;
}
