#include "Neuron.h"
#include "RandomGen.h"
#include <memory>

Neuron::Neuron(int inputs){
  // Initializing all the values to random
  RandomGen r;
  this->inputs = inputs;
  this->bias = r.randomDouble();
  this->wBias = r.randomDouble();
  for(int i = 0; i < inputs; i++){
    this->weights.push_back(r.randomDouble());
  }
  this->learningConstant = 0.01;
  this->momentum = 0.3;
}

std::vector<double> Neuron::getWeights(){
  return this->weights;
}

double Neuron::feed(std::vector<double> in){  // Feeds the inputs to the neuron
  double sum = 0.0;                     // Initializing the sum
  for (int i = 0; i < this->inputs; i++){
    sum += this->weights[i] * in[i];    // Producing the weighted sum
  }
  // sum += bias * wBias;                  // Adding the bias to the sum
  // sum += 1.0;
  Functions f;
  return f.sigmoid(sum);                // Returning the output between 0 and 1 using the sigmoid
}

void Neuron::train(std::vector<double> deltas){
  if(this->lastDeltas.empty()){
    for(int i = 0; i < this->inputs; i++){
      this->lastDeltas.push_back(this->learningConstant * deltas[i]);
      this->weights[i] -= this->lastDeltas[i];
    }
  }else{
    for(int i = 0; i < this->inputs; i++){
      lastDeltas[i] = ((1 - momentum) * deltas[i] * this->learningConstant + momentum * this->lastDeltas[i]);
      this->weights[i] -= this->lastDeltas[i];
    }
  }
}
