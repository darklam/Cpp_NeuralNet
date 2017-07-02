#ifndef NETOPTS_H
#define NETOPTS_H

#include <string>

class NetworkOptions{
public:
  NetworkOptions(int, int, int, int *); // The constructor which initializes the values
  NetworkOptions(NetworkOptions *);
  NetworkOptions(int, int);
  NetworkOptions(); // constructor for default values
  ~NetworkOptions();
  void setMinMax(double, double); // You need to run this if you use the minmax function
  // The number of hidden layers in the network
  // and the input and output layer size
  int hiddenCount, inputSize, outputSize;
  double min, max;
  std::string normalizationFunction; // The normalization function used
  int *hiddenLength; // The number of neurons in each layer
  //TODO add more options
};

#endif
