#include "Network.h"
#include "NetworkOptions.h"
#include "Functions.h"

Network::Network(NetworkOptions opts){
  this->opts = new NetworkOptions(&opts);
  this->input = new Layer(opts.inputSize, 1, true);
  this->output = new Layer(opts.outputSize, opts.hiddenLength[opts.hiddenCount - 1], false);
  this->hidden = new Layer[opts.hiddenCount];
  this->hidden[0] = Layer(opts.hiddenLength[0], opts.inputSize, false);
  for(int i = 1; i < opts.hiddenCount; i++){
    this->hidden[i] = Layer(opts.hiddenLength[i], opts.hiddenLength[i - 1], false);
  }
}

Network::Network(){
  this->opts = nullptr;
  this->input = nullptr;
  this->output = nullptr;
  this->hidden = nullptr;
}

Network::~Network(){
  delete this->input;
  delete this->output;
  delete this->opts;
  delete[] this->hidden;
}

double *Network::feed(double *inp){
  Functions f;
  double *in = f.minMax(inp, this->opts->inputSize, this->opts->min, this->opts->max);
  double *result = this->input->feed(in);
  delete[] in;
  // Temp holds the result of the next layer and result the ouput of the current
  // layer. Once the result of the next layer is computed the result of the
  // previous layer is no longer needed and is deleted
  double *temp;
  for(int i = 0; i < this->opts->hiddenCount; i++){
    temp = this->hidden[i].feed(result);
    delete[] result;
    result = temp;
  }
  temp = this->output->feed(result);
  delete[] result;
  result = temp;
  return result;
}
