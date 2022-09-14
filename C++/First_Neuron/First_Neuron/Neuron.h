#pragma once
#include <iostream>

class Neuron {
private:
	double weight;

public:
	double Smoothing,
		LastError;

	Neuron():
		weight (0.5), Smoothing (0.000001), LastError (1) {}


	double Convert_to(double input) 
	{
		return input * weight;
	}

	double Convert_reverse(double input) 
	{
		return input / weight;
	}

	void learning(double input, double ExpectedResult) 
	{
		double FactResult = input * weight;
		LastError = (ExpectedResult - FactResult);
		double correction = (LastError / FactResult);

		weight += correction;
		
	}
};
