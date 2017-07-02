#include "Layer.h"

Layer::Layer(int neurons, int inputs, bool isInput){
  this->count = neurons;
  this->inputs = inputs;
  this->isInput = isInput;
  this->neurons = new Neuron[neurons];
  for(int i = 0; i < neurons; i++){
    this->neurons[i] = Neuron(inputs);
  }
}

Layer::Layer(){
  this->neurons = nullptr;
}

double *Layer::feed(double *in){
  double *out = new double[this->count];
  if(!this->isInput){
    for(int i = 0; i < this->count; i++){
      out[i] = this->neurons[i].feed(in);
    }
  }else{
    for(int i = 0; i < this->count; i++){
      out[i] = this->neurons[i].feed(&in[i]);
    }
  }
  return out;
}

void Layer::train(){
  // TODO write this function lol
}

Layer::~Layer(){
  delete[] this->neurons;
}
