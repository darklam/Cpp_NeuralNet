#ifndef NETWORK_H
#define NETWORK_H

#include "NetworkOptions.h"
#include "Layer.h"
#include <vector>

class Network{
public:
  // Initializes the network
  Network(NetworkOptions);
  ~Network();
  // Takes the input values to the network and returns the outputs
  std::vector<double> feed(std::vector<double>);
  // The training function takes the inputs and the expected outputs as arguments
  // and trains the network
  void train(std::vector<double>, std::vector<double>);

private:
  // The network layers
  Layer *input;
  Layer *output;
  std::vector<Layer *> hidden;
  // The settings of the network
  NetworkOptions *opts;
  // Calculates the total network error
  double getTotalError(std::vector<double>, std::vector<double>);
  // Calculates the deltas for each output neuron
  // Takes as arguments the total network error, the target values vector
  // and the output neurons' outputs
  std::vector<double> calculateOutputDeltas(double, std::vector<double>, std::vector<double>);
  // Returns the outputs of the hidden layer at the given index
  std::vector<double> getHiddenOutputs(int, std::vector<double>);
};

#endif
