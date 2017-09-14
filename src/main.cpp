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
  std::vector<int> hiddenLenArr = {50};
  int inputs = 13, hiddenCount = 1, outputs = 3, maxEpoch = 10000;
  NetworkOptions opts(inputs, outputs, hiddenCount, hiddenLenArr);
  Network n(opts);
  double min = -1.0, max = 1.0, mutation = 0.1, cross = 0.2, elitism = 0.2;
  int length = n.getWeightCount(), populationSize = 1000, maxGen = 1000;
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
