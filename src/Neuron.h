#ifndef NEURON_H
#define NEURON_H

#include "Functions.h"
#include <memory>

class Neuron{
private:
  double bias, wBias; //The bias and the weight of the bias
  int inputs; //The amount of inputs the neuron takes
  std::unique_ptr<double[]> weights; //The weights of the neuron for each input

public:
  Neuron(int);  //The constructor that takes the inputs as an argument
  double feedNeuron(double *);  //Returns the result of the neuron
  //The training function. It takes the expected result and the inputs given and
  //it minimizes the error function.
  void train(double, double *);

};

#endif
