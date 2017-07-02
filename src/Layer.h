#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"

class Layer{
public:
  // Initializes the layer
  Layer(int, int, bool);
  Layer();
  // Feeds the values to the layer and returns the outputs
  double *feed(double *);
  // trains the layer - not finished yet
  void train();
  // the destructor
  ~Layer();

private:
  // The layer's neurons
  Neuron *neurons;
  // Number of neurons in the layer and the inputs each neuron will take
  int count, inputs;
  // true if the layer is the input layer
  bool isInput;
};

#endif
