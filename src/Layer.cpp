#include "Layer.h"
#include <vector>

Layer::Layer(int neurons, int inputs, bool isInput){
  this->count = neurons;
  this->inputs = inputs;
  this->isInput = isInput;
  for(int i = 0; i < neurons; i++){
    this->neurons.push_back(new Neuron(inputs));
  }
}

std::vector<double> Layer::feed(std::vector<double> in){
  std::vector<double> out;
  if(!this->isInput){
    for(int i = 0; i < this->count; i++){
      out.push_back(this->neurons[i]->feed(in));
    }
  }else{
    for(int i = 0; i < this->count; i++){
      std::vector<double> tmp;
      tmp.push_back(in[i]);
      out.push_back(this->neurons[i]->feed(tmp));
    }
  }
  return out;
}

void Layer::train(){
  // TODO write this function lol
}

Layer::~Layer(){
  for(int i = 0; i < this->neurons.size(); i++){
    delete this->neurons[i];
  }
}
