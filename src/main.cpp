#include "Neuron.h"
#include <iostream>

int main(){
  Neuron n(5);
  double lel[] = {3.4, 15.3, 1.5, 9.3, 2.8};
  std::cout << n.feedNeuron(lel);
  return 0;
}
