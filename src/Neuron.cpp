#include "Neuron.h"
#include "RandomGen.h"
#include <memory>

Neuron::Neuron(int inputs){
  //Initializing all the values to random
  RandomGen r;
  this->inputs = inputs;
  this->bias = r.randomDouble();
  this->wBias = r.randomDouble();
  this->weights = new double[inputs];
  for(int i = 0; i < inputs; i++){
    this->weights[i] = r.randomDouble();
  }
}
