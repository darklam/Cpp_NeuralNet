#include "Population.h"
#include "Chromosome.h"
#include "FileManagement.h"
#include "Network.h"
#include <iostream>


int main(){
  FileManager f("data.txt", ' ');
  Functions func;
  f.setInputs(13);
  f.setOutputs(3);
  f.openFile();
  std::vector<std::vector<double>> in = f.getInputs();
  std::vector<std::vector<double>> out = f.getOutputs();
  std::vector<int> hiddenLenArr = {5, 10};
  int inputs = 13, hiddenCount = 2, outputs = 3, maxEpoch = 10000;
  NetworkOptions opts(inputs, outputs, hiddenCount, hiddenLenArr);
  Network n(opts);
  double min = -3, max = 3, mutation = 0.2, cross = 0.2, elitism = 0.1;
  int length = n.getWeightCount(), populationSize = 10000, maxGen = 100;
  Population lol(
    populationSize, length, maxGen, elitism, cross, mutation, min, max,
    &n, in, out
  );
  Chromosome *best = new Chromosome(length, -1, 1);
  while(lol.nextGen()){
    // if(lol.getBest()->getFitness() > best->getFitness()){
    //   best->copy(lol.getBest());
    // }
    lol.printStats();
  }
  return 0;
}
