#include "Functions.h"
#include <cmath>

double Functions::sigmoid(double x){
  return 1 / (1 + exp(-x));
}

double Functions::sigmoidDerivative(double x){
  return sigmoid(x) * (1 - sigmoid(x));
}

double Functions::networkError(double *out, double *target, int count){
  double sum = 0.0;
  for (int i = 0; i < count; i++){
    sum += pow(target[i] - out[i], 2);
  }
  return 0.5 * sum;
}
