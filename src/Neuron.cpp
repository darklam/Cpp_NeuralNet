#include "Neuron.h"
#include "RandomGen.h"
#include <memory>

Neuron::Neuron(int inputs){
  // Initializing all the values to random
  RandomGen r;
  this->inputs = inputs;
  this->bias = r.randomDouble();
  this->wBias = r.randomDouble();
  this->weights = new double[inputs];
  for(int i = 0; i < inputs; i++){
    this->weights[i] = r.randomDouble();
  }
  this->learningConstant = 0.01;
}

Neuron::~Neuron(){
  delete[] this->weights;
}

Neuron::Neuron(){
  this->weights = nullptr;
}

double Neuron::feed(double *in){  // Feeds the inputs to the neuron
  double sum = 0.0;                     // Initializing the sum
  for (int i = 0; i < this->inputs; i++){
    sum += this->weights[i] * in[i];    // Producing the weighted sum
  }
  sum += bias * wBias;                  // Adding the bias to the sum
  Functions f;
  return f.sigmoid(sum);                // Returning the output between 0 and 1 using the sigmoid
}

void Neuron::train(double *in, double delta){
  for(int i = 0; i < this->inputs; i++){
    this->weights[i] += in[i] * delta * this->learningConstant;
  }
  this->wBias += this->bias * delta * this->learningConstant;
}
