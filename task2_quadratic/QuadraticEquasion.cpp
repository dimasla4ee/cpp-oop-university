#include "QuadraticEquasion.h"

QuadraticEquasion::QuadraticEquasion(double a, double b, double c)
    : a(a), b(b), c(c) {}

double QuadraticEquasion::getDiscriminant() const { return b * b - 4 * a * c; }

std::vector<double> QuadraticEquasion::findRoots() const {
        std::vector<double> roots;
        double discriminant = getDiscriminant();

        if (discriminant == 0) {
            double root = -b / (2 * a);
            roots.push_back(root);
        } else if (discriminant > 0) {
            double root = (-b + sqrt(discriminant)) / (2 * a);
            roots.push_back(root);
            root = (-b - sqrt(discriminant)) / (2 * a);
            roots.push_back(root);
        }

        return roots;
}
