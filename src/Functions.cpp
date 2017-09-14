#include "Functions.h"
#include <cmath>
#include <vector>
#include <iostream>

double Functions::sigmoid(double x){
  return 1 / (1 + exp(-x));
}

double Functions::sigmoidDerivative(double x){
  return this->sigmoid(x) * (1 - this->sigmoid(x));
}

std::vector<double> Functions::minMax(std::vector<double> in, int length, double min, double max){
  std::vector<double> res;
  double den = max - min;
  for(int i = 0; i < length; i++){
    res.push_back((in[i] - min) / den);
  }
  return res;
}

double Functions::networkError(std::vector<double> out, std::vector<double> target){
  double sum = 0.0;
  for (int i = 0; i < out.size(); i++){
    sum += pow(target[i] - out[i], 2);
  }
  return 0.5 * sum;
}

void Functions::printVector(std::vector<double> v){
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}
