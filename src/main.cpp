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

int main(){
  NetworkOptions opts(5, 1);
  opts.setMinMax(0, 20);
  Network n(opts);
  double lel[] = {3.4, 15.3, 1.5, 9.3, 2.8};
  std::vector<double> res = n.feed(toVector(lel, 5));
  for(int i = 0; i < res.size(); i++){
    std::cout << res[i] << std::endl;
  }
  return 0;
}
