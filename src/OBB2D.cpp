#include <iostream>
#include <cmath>

class OBB2D {
public:
    OBB2D(float x, float y, float width, float height, float angle)
        : x(x), y(y), width(width), height(height), angle(angle) {}

    bool isColliding(const OBB2D& other) const {
        // Check for collision between two OBBs (simplified)
        // This is a basic example and doesn't replicate the complex collision detection used in Geometry Dash.
        return std::abs(x - other.x) < (width + other.width) / 2 &&
            std::abs(y - other.y) < (height + other.height) / 2;
    }

private:
    float x, y;       // Position of the OBB
    float width, height;  // Dimensions of the OBB
    float angle;      // Rotation angle of the OBB
};

int main() {
    // Create two OBBs (simplified)
    OBB2D obb1(0, 0, 2, 2, 45.0f);
    OBB2D obb2(1, 1, 2, 2, 30.0f);

    // Check for collision (simplified)
    if (obb1.isColliding(obb2)) {
        std::cout << "Collision detected!" << std::endl;
    }
    else {
        std::cout << "No collision detected." << std::endl;
    }

    return 0;
}
