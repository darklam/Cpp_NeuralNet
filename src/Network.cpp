#include "Network.h"
#include "NetworkOptions.h"
#include "Functions.h"
#include <cmath>
#include <vector>

Network::Network(NetworkOptions opts){
  this->opts = new NetworkOptions(&opts);
  this->input = new Layer(opts.inputSize, 1, "input");
  this->output = new Layer(opts.outputSize, opts.hiddenLength[opts.hiddenCount - 1], "output");
  this->hidden.push_back(new Layer(opts.hiddenLength[0], opts.inputSize, "hidden"));
  for(int i = 1; i < opts.hiddenCount; i++){
    this->hidden.push_back(new Layer(opts.hiddenLength[i], opts.hiddenLength[i - 1], "biased_hidden"));
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

void Network::train(std::vector<double> in, std::vector<double> target){
  std::vector<double> inputLayerOutputs = this->input->feed(in);
  std::vector<std::vector<double>> hiddenOutputs;
  for(int i = 0; i < this->opts->hiddenCount; i++){
    if(i == 0){
      hiddenOutputs.push_back(this->hidden[i]->feed(inputLayerOutputs));
    }else{
      hiddenOutputs.push_back(this->hidden[i]->feed(hiddenOutputs[i - 1]));
    }
  }
  std::vector<double> outputLayerOutputs = this->output->feed(
    hiddenOutputs[hiddenOutputs.size() - 1]
  );
  std::vector<double> deltas;
  deltas = this->output->trainOutput(target, outputLayerOutputs, hiddenOutputs[hiddenOutputs.size() - 1]);
  if(this->opts->hiddenCount == 1){
    deltas = this->hidden[0]->trainHidden(deltas, this->output, hiddenOutputs[0], inputLayerOutputs);
  }else{
    for(int i = this->opts->hiddenCount - 1; i >= 0; i--){
      if(i == this->opts->hiddenCount - 1){
        deltas = this->hidden[i]->trainHidden(deltas, this->output, hiddenOutputs[i], hiddenOutputs[i - 1]);
      }else if(i != 0){
        deltas = this->hidden[i]->trainHidden(deltas, this->hidden[i + 1], hiddenOutputs[i], hiddenOutputs[i - 1]);
      }else{
        deltas = this->hidden[i]->trainHidden(deltas, this->hidden[i + 1], hiddenOutputs[i], inputLayerOutputs);
      }
    }
  }
}

void Network::loadFromVector(std::vector<double> w){
  Layer *currentLayer;
  int count = 0;
  std::vector<double> weights;
  int inp;
  for(int k = 0; k < this->hidden.size(); k++){
    currentLayer = this->hidden[k];
    inp = currentLayer->getInputCount();
    for(int i = 0; i < currentLayer->getNeuronCount(); i++){
      Neuron *current = currentLayer->getNeurons()[i];
      for(int j = 0; j < inp; j++){
        weights.push_back(w[count++]);
      }
      current->setWeights(weights);
      weights.clear();
    }
  }
  currentLayer = this->output;
  inp = currentLayer->getInputCount();
  for(int i = 0; i < currentLayer->getNeuronCount(); i++){
    Neuron *current = currentLayer->getNeurons()[i];
    for(int j = 0; j < inp; j++){
      weights.push_back(w[count++]);
    }
    current->setWeights(weights);
    weights.clear();
  }
}

int Network::getWeightCount(){
  int count = 0;
  Layer *current;
  for(int i = 0; i < this->hidden.size(); i++){
    current = this->hidden[i];
    count += current->getNeuronCount() * current->getInputCount();
  }
  current = this->output;
  count += current->getNeuronCount() * current->getInputCount();
  return count;
}

double Network::getNetworkError(std::vector<std::vector<double>> inputs,
std::vector<std::vector<double>> out){
  Functions f;
  double err = 0.0;
  for(int i = 0; i < out.size(); i++){
    err += f.networkError(this->feed(inputs[i]), out[i]);
  }
  err /= out.size();
  return err;
}

std::vector<double> Network::feed(std::vector<double> inp){
  Functions f;
  // std::vector<double> in = f.minMax(inp, this->opts->inputSize, this->opts->min, this->opts->max);
  std::vector<double> in = inp;
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
