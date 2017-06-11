#include "Neuron.h"
#include <vector>

class Network{

private:
	int inputs, hid1, hid2;
	std::vector<Neuron> input, h1, h2;
	Neuron output;
	std::vector<double> feedInputs(std::vector<double>);
	std::vector<double> feedHid1(std::vector<double>);
	std::vector<double> feedHid2(std::vector<double>);
	std::vector<double> inputsOutput, hid1Output, hid2Output;

public:
	Network(int);
	void trainNetwork(double, std::vector<double>);
	double getNumber(std::vector<double>);
	int getRes(std::vector<double>);
};