#include <vector>

class Neuron{

public:
	Neuron(int);
	double feedNeuron(std::vector<double>);
	int activate(std::vector<double>);
	void train(double, std::vector<double>);
	void networkTrain(double, std::vector<double>);

private:
	double f(double);
	double fdiff(double);
	double getFault(std::vector<double>);
	int inputs;
	std::vector<double> weights;
	double bias, wBias, learningConstant;
};