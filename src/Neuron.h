#ifndef NEURON_H
#define NEURON_H

#include "Functions.h"

class Neuron{
private:
  double bias, wBias, momentum; // The bias and the weight of the bias
  std::vector<double> lastDeltas;
  int inputs; // The amount of inputs the neuron takes
  std::vector<double> weights; // The weights of the neuron for each input
  double learningConstant; // Defines how fast or slow the network will train

public:
  Neuron(int);  // The constructor that takes the inputs as an argument
  std::vector<double> getWeights();
  double feed(std::vector<double>);  // Returns the result of the neuron
  // The training function. It takes the expected result and the inputs given and
  // it minimizes the error function.
  void train(std::vector<double>);

};

#endif
