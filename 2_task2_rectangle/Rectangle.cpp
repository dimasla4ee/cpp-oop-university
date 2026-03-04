#include <iostream>

class Point {
   private:
    int x = 0;
    int y = 0;

   public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
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

class Rectangle {
   private:
    Point bottomLeft;
    Point topRight;

   public:
    Rectangle(int x1, int y1, int x2, int y2) {
        bottomLeft.setX(std::min(x1, x2));
        bottomLeft.setY(std::min(y1, y2));
        topRight.setX(std::max(x1, x2));
        topRight.setY(std::max(y1, y2));
    };

    void setBottomLeft(const Point& bottomLeft) {
        this->bottomLeft = bottomLeft;
    }
    Point getBottomLeft() { return bottomLeft; }

    void setTopRight(const Point& topRight) { this->topRight = topRight; }
    Point getTopRight() { return topRight; }

    int getWidth() { return topRight.getX() - bottomLeft.getX(); }
    int getHeight() { return topRight.getY() - bottomLeft.getY(); }

    int calculateArea() { return getWidth() * getHeight(); }
    int calculatePerimeter() { return 2 * (getWidth() + getHeight()); }

    void print() {
        std::cout << "Bottom left point: ";
        bottomLeft.print();

        std::cout << "Top right point: ";
        topRight.print();
    }
};
