#ifndef NEURON_H
#define NEURON_H

#include "Functions.h"

class Neuron{
private:
  double bias, wBias; //The bias and the weight of the bias
  int inputs; //The amount of inputs the neuron takes
  double *weights; //The weights of the neuron for each input
  Functions f;

public:
  Neuron(int);
  double feedNeuron(double *);
  void train(double, double *);

};

#endif
