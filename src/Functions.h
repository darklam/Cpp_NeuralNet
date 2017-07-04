#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>

class Functions{  // A class for the mathematical functions used
public:
  double sigmoid(double);  // The sigmoid function
  double quadraticCost(std::vector<double>, double *, int);  // The quadratic cost function
  double sigmoidDerivative(double);   // The sigmoid function derivative
  double networkError(std::vector<double>, std::vector<double>, int); //Calculates the error of the network
  std::vector<double> minMax(std::vector<double>, int, double, double);
};

#endif
