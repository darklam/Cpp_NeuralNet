#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Functions{  // A class for the mathematical functions used
public:
  double sigmoid(double);  // The sigmoid function
  double quadraticCost(double *, double *, int);  // The quadratic cost function  
  double sigmoidDerivative(double);   // The sigmoid function derivative
};

#endif
