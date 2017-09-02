#include "Layer.h"
#include <vector>
#include <iostream>

Layer::Layer(int neurons, int inputs, std::string type){
  this->count = neurons;
  this->inputs = inputs;
  if(type == "biased_hidden" || type == "output"){
    this->inputs++;
  }
  this->type = type;
  for(int i = 0; i < neurons; i++){
    this->neurons.push_back(new Neuron(this->inputs));
  }
}

int Layer::getNeuronCount(){
  return this->count;
}

std::vector<Neuron *> Layer::getNeurons(){
  return this->neurons;
}

std::vector<double> Layer::trainOutput(std::vector<double> target,
std::vector<double> activations,
std::vector<double> prevActivations){
  Functions f;
  std::vector<double> layerDeltas;
  for(int i = 0; i < this->count; i++){
    Neuron *current = this->neurons[i];
    double deltaCurrent = (activations[i] - target[i]) * f.sigmoidDerivative(activations[i]);
    layerDeltas.push_back(deltaCurrent);
    std::vector<double> deltas;
    for(int j = 0; j < prevActivations.size(); j++){
      deltas.push_back(prevActivations[j] * deltaCurrent);
    }
    current->train(deltas);
  }
  return layerDeltas;
}

std::vector<double> Layer::trainHidden(std::vector<double> nextDeltas,
Layer *next,
std::vector<double> activations,
std::vector<double> prevActivations){
  Functions f;
  std::vector<Neuron *> nextLayer = next->getNeurons();
  std::vector<double> layerDeltas;
  for(int i = 0; i < this->count; i++){
    double sum = 0.0;
    for(int j = 0; j < nextLayer.size(); j++){
      sum += nextDeltas[j] * nextLayer[j]->getWeights()[i];
    }
    double neuronDelta = sum * f.sigmoidDerivative(activations[i]);
    layerDeltas.push_back(neuronDelta);
    Neuron *current = this->neurons[i];
    std::vector<double> neuronDeltas;
    for(int j = 0; j < prevActivations.size(); j++){
      neuronDeltas.push_back(neuronDelta * prevActivations[j]);
    }
    current->train(neuronDeltas);
  }
  return layerDeltas;
}



std::vector<double> Layer::feed(std::vector<double> in){
  if(this->type != "input"){
    std::vector<double> out;
    for(int i = 0; i < this->count; i++){
      out.push_back(this->neurons[i]->feed(in));
    }
    if(this->type != "output"){
      out.push_back(1.0);
    }
    return out;
  }else{
    return in;
  }
}

Layer::~Layer(){
  for(int i = 0; i < this->neurons.size(); i++){
    delete this->neurons[i];
  }
}
