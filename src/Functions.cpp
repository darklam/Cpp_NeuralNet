#include "Functions.h"
#include <cmath>

double Functions::sigmoid(double x){  //The sigmoid function implementation
  return 1 / (1 + exp(-x));
}
