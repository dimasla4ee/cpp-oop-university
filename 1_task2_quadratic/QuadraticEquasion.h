#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include <vector>

class QuadraticEquasion {
   private:
    double a;
    double b;
    double c;

   public:
    QuadraticEquasion(double a, double b, double c);

    double getDiscriminant() const;
    std::vector<double> findRoots() const;
};

#endif