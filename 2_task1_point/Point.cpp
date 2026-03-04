#include <iostream>

class Point {
   private:
    int x = 0;
    int y = 0;

   public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };
    Point() = default;

    void setX(int x) { this->x = x; }
    int getX() { return x; }

    void setY(int y) { this->y = y; }
    int getY() { return y; }

    double distanceTo(const Point& other) {
        int xOperand = pow((other.x - x), 2);
        int yOperand = pow((other.y - y), 2);
        return sqrt(xOperand + yOperand);
    }

    void print() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};