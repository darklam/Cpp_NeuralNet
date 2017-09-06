#include "NetworkOptions.h"
#include "Network.h"
#include "FileManagement.h"
#include <iostream>
#include <vector>
#include <cmath>

double meanQuadError(std::vector<double> out, std::vector<double> expected){
  double sum = 0.0;
  for(int i = 0; i < out.size(); i++){
    sum += pow(out[i] - expected[i], 2);
  }
  sum *= 0.5;
  return sum;
}

void printVec(std::vector<double> v){
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
  }
}


int main(){
  FileManager f("data.txt", ' ');
  Functions func;
  f.setInputs(13);
  f.setOutputs(3);
  f.openFile();
  std::vector<std::vector<double>> in = f.getInputs();
  std::vector<std::vector<double>> out = f.getOutputs();
  std::vector<int> hiddenLenArr = {600};
  int inputs = 13, hiddenCount = 1, outputs = 3, maxEpoch = 10000;
  NetworkOptions opts(inputs, outputs, hiddenCount, hiddenLenArr);
  Network n(opts);
  double error = 4;
  double lowest = 100;
  char c;
  int i = 0;
  int trainSize = (int)(in.size() * 0.5);
  while(error > 0.001){
  // for(int i = 0; i < maxEpoch; i++){
    error = 0.0;
    for(int j = 0; j < trainSize; j++){
      n.train(in[j], out[j]);
      // std::vector<double> res = n.feed(in[j]);
      // printVec(res);
      error += meanQuadError(n.feed(in[j]), out[j]);
    }

    i++;
    error /= trainSize;
    if(error < lowest) lowest = error;
    std::cout << error << std::endl;
  }
  std::cout << "lowest error: " << lowest << " - Epoch: "<< i <<  std::endl;
  error = 0;
  // std::cout << in.size() << " - " << out.size() << "\n";
  for(int i = 0; i < out.size(); i++){
    error += meanQuadError(n.feed(in[i]), out[i]);
    // std::cout << error << std::endl;
  }
  error /= in.size();
  std::cout << error << std::endl;
  // for(int i = 0; i < 100000; i++){
  //   n.train(in[0], out[0]);
  // }
  // printVec(n.feed(in[0]));
  return 0;
}
