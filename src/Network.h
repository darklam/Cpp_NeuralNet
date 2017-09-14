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
  void loadFromVector(std::vector<double>);
  int getWeightCount();
  double getNetworkError(std::vector<std::vector<double>>,
                        std::vector<std::vector<double>>);

private:
  // The network layers
  Layer *input;
  Layer *output;
  std::vector<Layer *> hidden;
  // The settings of the network
  NetworkOptions *opts;
};

#endif
