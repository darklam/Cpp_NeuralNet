#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Functions{  // A class for the mathematical functions used
public:
  double sigmoid(double);  // The sigmoid function
  double quadraticCost(double *, double *, int);  // The quadratic cost function
  double sigmoidDerivative(double);   // The sigmoid function derivative
  double networkError(double *, double *, int); //Calculates the error of the network
  double *minMax(double *, int, double, double);
};

#endif
