#include "Network.h"
#include "NetworkOptions.h"
#include "Functions.h"
#include <cmath>
#include <vector>

Network::Network(NetworkOptions opts){
  this->opts = new NetworkOptions(&opts);
  this->input = new Layer(opts.inputSize, 1, true);
  this->output = new Layer(opts.outputSize, opts.hiddenLength[opts.hiddenCount - 1], false);
  this->hidden.push_back(new Layer(opts.hiddenLength[0], opts.inputSize, false));
  for(int i = 1; i < opts.hiddenCount; i++){
    this->hidden.push_back(new Layer(opts.hiddenLength[i], opts.hiddenLength[i - 1], false));
  }
}

Network::~Network(){
  delete this->input;
  delete this->output;
  delete this->opts;
  for(int i = 0; i < this->hidden.size(); i++){
    delete this->hidden[i];
  }
}

std::vector<double> Network::getHiddenOutputs(int index, std::vector<double> in){

}

double Network::getTotalError(std::vector<double> outputs, std::vector<double> target){
  double out = 0;
  if(outputs.size() != expected.size()){
    // This cannot output a negative value therefore any negative value will mean
    // that there's an error (the output and expected vectors are not equal
    // in size in this case)
    return -1;
  }
  for(int i = 0; i < outputs.size(); i++){
    out += pow(tartget[i] - outputs[i], 2);
  }
  out /= 2;
  return out;
}

std::vector<double> Network::calculateOutputDeltas(double netError, std::vector<double> out,
std::vector<double> target){
  std::vector<double> deltas;
  Functions f;
  for(int i = 0; i < this->output->getNeurons(); i++){
    deltas.push_back(
      (out[i] - target[i]) * f.sigmoidDerivative(out[i]);
    );
  }
  return deltas;
}


void Network::train(std::vector<double> out, std::vector<double> target){
  double totalErr = getTotalError(out, target);
  if(totalErr < 0){
    // We should implement an actual error logging system but this is just too
    // early and there are a million other things to fix first
    return;
  }
  // Calculating the deltas for each output neuron
  std::vector<double> outputDeltas = this->calculateOutputDeltas(totalErr, out, target);

}

std::vector<double> Network::feed(std::vector<double> inp){
  Functions f;
  std::vector<double> in = f.minMax(inp, this->opts->inputSize, this->opts->min, this->opts->max);
  std::vector<double> result = this->input->feed(in);
  std::vector<double> temp;
  for(int i = 0; i < this->opts->hiddenCount; i++){
    temp = this->hidden[i]->feed(result);
    result = temp;
  }
  temp = this->output->feed(result);
  result = temp;
  return result;
}
