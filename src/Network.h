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

private:
  // The network layers
  Layer *input;
  Layer *output;
  std::vector<Layer *> hidden;
  // The settings of the network
  NetworkOptions *opts;
};

#endif
