#include "Chromosome.h"
#include "RandomGen.h"
#include "Network.h"
#include "Functions.h"
#include <iostream>
#include <cmath>

Chromosome::Chromosome(int size, double min, double max){
  this->genes.reserve(size);
  RandomGen r;
  double num;
  for(int i = 0; i < size; i++){
    num = (max - min) * r.randomDouble() + min;
    this->genes.push_back(num);
  }
}

int Chromosome::getSize(){
  return this->genes.size();
}

void Chromosome::printChromosome(){
  for(int i = 0; i < this->getSize(); i++){
    std::cout << this->genes[i] << " ";
  }
}

void Chromosome::setGene(int index, double value){
  if(index >= this->genes.size()){
    return;
  }
  this->genes[index] = value;
}

void Chromosome::copy(Chromosome *c){
  this->genes.clear();
  for(int i = 0; i < c->getSize(); i++){
    this->genes.push_back(c->getGene(i));
  }
}

double Chromosome::getGene(int index){
  return this->genes[index];
}

void Chromosome::swapGenes(int a, int b){
  if(a >= this->genes.size() || b >= this->genes.size()){
    return;
  }
  double temp = this->genes[a];
  this->genes[a] = this->genes[b];
  this->genes[b] = temp;
}

Chromosome::Chromosome(Chromosome *copy){
  this->genes.reserve(copy->getSize());
  for(int i = 0; i < copy->getSize(); i++){
    this->genes.push_back(copy->getGene(i));
  }
}

double Chromosome::getFitness(std::vector<std::vector<double>> in,
std::vector<std::vector<double>> out, Network *n){
  n->loadFromVector(this->genes);
  double err = n->getNetworkError(in, out);
  return 1.0 / err;
}
