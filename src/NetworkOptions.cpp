#include "NetworkOptions.h"
#include <cmath>

NetworkOptions::NetworkOptions(int inputSize, int outputSize, int hiddenCount, int *lengths){
  this->hiddenCount = hiddenCount;
  this->inputSize = inputSize;
  this->normalizationFunction = "minmax"; // The default function
  this->outputSize = outputSize;
  this->hiddenLength = new int[hiddenCount];
  for(int i = 0; i < hiddenCount; i++){
    this->hiddenLength[i] = lengths[i];
  }
}

NetworkOptions::NetworkOptions(NetworkOptions *opts){
  this->hiddenCount = opts->hiddenCount;
  this->inputSize = opts->inputSize;
  this->outputSize = opts->outputSize;
  this->min = opts->min;
  this->max = opts->max;
  this->hiddenLength = new int[this->hiddenCount];
  this->normalizationFunction = opts->normalizationFunction;
  for(int i = 0; i < this->hiddenCount; i++){
    this->hiddenLength[i] = opts->hiddenLength[i];
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
  this->hiddenLength = new int[this->hiddenCount];
  for(int i = 0; i < this->hiddenCount; i++){
    this->hiddenLength[i] = ceil(inputSize * 10.0 / (double) (i + 1));
  }
}

NetworkOptions::~NetworkOptions(){
  delete[] this->hiddenLength;
}
