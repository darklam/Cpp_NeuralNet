#include "NetworkOptions.h"
#include "Network.h"
#include <iostream>
#include <vector>

std::vector<double> toVector(double *in, int len){
  std::vector<double> out;
  for(int i = 0; i < len; i++){
    out.push_back(in[i]);
  }
  return out;
}

std::vector<int> toVector(int *in, int len){
  std::vector<int> out;
  for(int i = 0; i < len; i++){
    out.push_back(in[i]);
  }
  return out;
}



int main(){
  int hiddenLenArr[] = {20};
  NetworkOptions opts(2, 1, 1, toVector(hiddenLenArr, 1));
  opts.setMinMax(0, 20);
  Network n(opts);
  double values[][2] = {
    {1.0, 1.0},
    {1.0, 0.0},
    {0.0, 1.0},
    {0.0, 0.0}
  };
  double correct[][1] = {
    {1.0},
    {1.0},
    {1.0},
    {0.0}
  };
  for(int i = 0; i < 50000; i++){
    for(int j = 0; j < 4; j++){
      double *vals = values[j];
      double *targets = correct[j];
      std::vector<double> in = toVector(vals, 2);
      std::vector<double> tar = toVector(targets, 1);
      n.train(in, tar);
    }
  }
  for(int i = 0; i < 4; i++){
    double *vals = values[i];
    double *targets = correct[i];
    std::vector<double> in = toVector(vals, 2);
    std::vector<double> tar = toVector(targets, 1);
    std::vector<double> out = n.feed(in);
    std::cout << out[0] << " - Expected: " << tar[0] << std::endl;
  }
  return 0;
}
