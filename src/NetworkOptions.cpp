#include "NetworkOptions.h"
#include <cmath>
#include <vector>

NetworkOptions::NetworkOptions(int inputSize, int outputSize, int hiddenCount, std::vector<int> lengths){
  this->hiddenCount = hiddenCount;
  this->inputSize = inputSize;
  this->normalizationFunction = "minmax"; // The default function
  this->outputSize = outputSize;
  for(int i = 0; i < hiddenCount; i++){
    this->hiddenLength.push_back(lengths[i]);
  }
}

NetworkOptions::NetworkOptions(NetworkOptions *opts){
  this->hiddenCount = opts->hiddenCount;
  this->inputSize = opts->inputSize;
  this->outputSize = opts->outputSize;
  this->min = opts->min;
  this->max = opts->max;
  this->normalizationFunction = opts->normalizationFunction;
  for(int i = 0; i < this->hiddenCount; i++){
    this->hiddenLength.push_back(opts->hiddenLength[i]);
  }
}

void NetworkOptions::setMinMax(double min, double max){
  this->min = min;
  this->max = max;
}

NetworkOptions::NetworkOptions(int inputSize, int outputSize){
  this->hiddenCount = 2;
  this->inputSize = inputSize;
  this->normalizationFunction = "minmax"; // The default function
  this->outputSize = outputSize;
  for(int i = 0; i < this->hiddenCount; i++){
    this->hiddenLength.push_back(ceil(inputSize * 10.0 / (double) (i + 1)));
  }
}

NetworkOptions::~NetworkOptions(){
}
