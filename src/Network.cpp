#include "Network.h"
#include "NetworkOptions.h"
#include "Functions.h"
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
