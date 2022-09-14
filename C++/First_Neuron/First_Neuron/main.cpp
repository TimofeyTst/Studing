#include <iostream>
#include "Neuron.h"

using namespace std;

int main()
{
	double dollars = 1,
		rubs = 74.0852;

	Neuron FirstNeuron;

	cout << "Before learning: ";
	cout << "In 1$ there are " << FirstNeuron.Convert_to(dollars) << " rubs\t" << 
		"In " << rubs << " rubs there are " << FirstNeuron.Convert_reverse(rubs) << "$\n";
	cout << "For start learning ";
	system("pause");

	int i = 0;
	while ((FirstNeuron.LastError > FirstNeuron.Smoothing || FirstNeuron.LastError < -FirstNeuron.Smoothing) )
	{
		FirstNeuron.learning(dollars, rubs);
		//cout << "\nIteration #" << ++i << " Error: " << FirstNeuron.LastError;
	}

	cout << endl;
	system("pause");
	cout << "After learning: ";
	cout << "In 1$ there are " << FirstNeuron.Convert_to(dollars) << " rubs\t" <<
		"In " << rubs << " rubs there are " << FirstNeuron.Convert_reverse(rubs) << "$\n";
	int k = 100;
	cout << "In " << k << "$ there are " << FirstNeuron.Convert_to(dollars*k) << " rubs\t" <<
		"In " << rubs*k << " rubs there are " << FirstNeuron.Convert_reverse(rubs*k) << "$\n";
	k = 541;
	cout << "In " << k << "$ there are " << FirstNeuron.Convert_to(dollars * k) << " rubs\t" <<
		"In " << rubs * k << " rubs there are " << FirstNeuron.Convert_reverse(rubs * k) << "$\n";
	k = 10;
	cout << "In " << k << "$ there are " << FirstNeuron.Convert_to(dollars * k) << " rubs\t" <<
		"In " << rubs * k << " rubs there are " << FirstNeuron.Convert_reverse(rubs * k) << "$\n";
	k = 78;
	cout << "In " << k << "$ there are " << FirstNeuron.Convert_to(dollars * k) << " rubs\t" <<
		"In " << rubs * k << " rubs there are " << FirstNeuron.Convert_reverse(rubs * k) << "$\n";
	cout << "In 10 rubs there are " << FirstNeuron.Convert_reverse(10) << "$\n";

}