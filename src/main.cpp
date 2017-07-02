#include "NetworkOptions.h"
#include "Network.h"
#include <iostream>

int main(){
  NetworkOptions opts(5, 1);
  opts.setMinMax(0, 20);
  Network n(opts);
  double lel[] = {3.4, 15.3, 1.5, 9.3, 2.8};
  std::cout << n.feed(lel);
  return 0;
}
