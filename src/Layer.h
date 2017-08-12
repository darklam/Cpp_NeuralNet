#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <vector>

class Layer{
public:
  // Initializes the layer
  Layer(int, int, bool);
  // Feeds the values to the layer and returns the outputs
  std::vector<double> feed(std::vector<double>);
  // returns the number of neurons in the layer
  int getNeurons();
  // This function trains the layer and returns the deltas for the previous layer
  // It takes its deltas and the network inputs as arguments
  std::vector<double> train(std::vector<double>, std::vector<double>);
  // the destructor
  ~Layer();

private:
  // The layer's neurons
  std::vector<Neuron *> neurons;
  // Number of neurons in the layer and the inputs each neuron will take
  int count, inputs;
  // true if the layer is the input layer
  bool isInput;
};

#endif
