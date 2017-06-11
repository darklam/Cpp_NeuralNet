#pragma once

#include "Neuron.h"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

Neuron::Neuron(int inputs){
	this->inputs = inputs;
	srand(time(0));
	learningConstant = 0.01;
	wBias = rand();
	bias = rand();
	for(int i = 0; i < inputs; i++){
		weights.push_back(rand());
	}
}

double Neuron::f(double x){
	return 1 / (1 + exp(-x));
}

double feedNeuron(std::vector<double> in){
	double sum = 0.0;
	for(int i = 0; i < inputs; i++){
		sum += weights[i] * in[i]; 
	}
	sum += bias * wBias;
	return f(sum);
}

int Neuron::activate(std::vector<double> in){
	double val = feedNeuron(in);
	if(val > 0.5){
		return 1;
	}else{
		return -1;
	}
}

void Neuron::train(double err, std::vector<double> in){
	for(int i = 0; i < inputs; i++){
		weights[i] += err * in[i] * learningConstant;
	}
	wBias += err * bias * learningConstant;
}

double Neuron::fdiff(double x){
	return f(x) - 1 / pow(1 + exp(-x), 2);
}

double Neuron::getFault(std::vector<double> in){
	double sum = 0.0;
	for(int i = 0; i < inputs; i++){
		sum += in[i] * weights[i];
	}
	sum += wBias * bias;
	return fdiff(sum);
}

void Neuron::networkTrain(double err, std::vector<double> in){
	err *= getFault(in);
	for(int i = 0; i < inputs; i++){
		weights[i] += err * in[i] * learningConstant; 
	}
	wBias += err * bias * learningConstant;
}