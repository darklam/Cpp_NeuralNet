#ifndef NETWORK_H
#define NETWORK_H

#include "NetworkOptions.h"
#include "Layer.h"

class Network{
public:
  // Initializes the network
  Network(NetworkOptions);
  Network();
  ~Network();
  // Takes the input values to the network and returns the outputs
  double *feed(double *);

private:
  // The network layers
  Layer *input;
  Layer *output;
  Layer *hidden;
  // The settings of the network
  NetworkOptions *opts;
};

#endif
