#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <vector>
#include <string>

class Layer{
public:
  // Initializes the layer
  // The inputs it takes are: the number of neurons, the
  // number of inputs of each neuron and whether it is
  // an input, a hidden or an output layer
  Layer(int, int, std::string);
  // Feeds the values to the layer and returns the outputs
  std::vector<double> feed(std::vector<double>);
  // returns the number of neurons in the layer
  int getNeuronCount();
  // returns the neuron vector
  std::vector<Neuron *> getNeurons();
  // This function trains the layer and returns the deltas for the previous layer
  // It takes its deltas and the network inputs as arguments
  std::vector<double> train(std::vector<double>, std::vector<double>);
  // the destructor
  ~Layer();
  // Takes as arguments the target values, the activations of the output layer
  // and the activations of the previous layer
  std::vector<double> trainOutput(std::vector<double>, std::vector<double>, std::vector<double>);
  // Takes as arguments the next layer's deltas, the next layer, the hidden
  // layer's activations and the previous layer's activations
  std::vector<double> trainHidden(std::vector<double>, Layer *, std::vector<double>,
                                  std::vector<double>);

private:
  // The layer's neurons
  std::vector<Neuron *> neurons;
  // Number of neurons in the layer and the inputs each neuron will take
  int count, inputs;
  // true if the layer is the input layer
  std::string type;
};

#endif
