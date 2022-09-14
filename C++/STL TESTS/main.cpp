#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes.h"
#include <time.h>
using namespace std;

std::mutex mtx1, mtx2;

void print(char ch)
{
	mtx1.lock();
	cout << "/=/=/=/= Print \tThread id: " << std::this_thread::get_id() << " /= /= /= /=\n";
	mtx2.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 15; i++)
		{
			cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << endl;
	}
	mtx2.unlock();
	cout << endl;
	mtx1.unlock();
}
void print2(char ch)
{
	mtx2.lock();
	cout << "/=/=/=/= Print \tThread id: " << std::this_thread::get_id() << " /= /= /= /=\n";
	mtx1.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 15; i++)
		{
			cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << endl;
	}
	mtx1.unlock();
	cout << endl;
	mtx2.unlock();
}

struct METRO_struct {
	unsigned int year, life;
	std::string id, model;
};

std::ostream& operator << (std::ostream& os, METRO_struct var)
{
	os << var.id << '\n' << var.model
		<< '\n' << var.year << '\n' << var.life << '\n' << "========\n";
	return os;
}

void test_threads()
{
	thread extra1(print,'T');

	thread extra2(print2,'#');


	extra1.join();
	extra2.join();
}

void test_unique_foreach()
{
	vector<string> Tst = { "Tima", "Maxim", "Azamat", "Vanka", "Yanochka", "Polina", "Vika" };

	for (int i = 0; i < Tst.size(); i++)
	{
		cout << "[" << Tst[i] << "]" << ' ';
	}
	srand(time(NULL));

	for_each(std::begin(Tst), std::end(Tst), [](string& element)
		{
			if (rand() % 2)
				element = "LOVE";
		});
	cout << endl;

	for (int i = 0; i < Tst.size(); i++)
	{
		cout << "[" << Tst[i] << "]" << ' ';
	}

	cout << "\nAfter unique:\n";

	auto iterator = unique(begin(Tst), end(Tst));
	Tst.erase(iterator, end(Tst));
	Tst.shrink_to_fit();

	for (int i = 0; i < Tst.size(); i++)
	{
		cout << "[" << Tst[i] << "]" << ' ';
	}

	cout << endl;
	vector<int> tst = { 1,2,2,3,2,4,4 };

	for (int i = 0; i < tst.size(); i++)
	{
		cout << "[" << tst[i] << "]" << ' ';
	}
	cout << endl;

	tst.erase(unique(begin(tst), end(tst)), end(tst));

	for (int i = 0; i < tst.size(); i++)
	{
		cout << "[" << tst[i] << "]" << ' ';
	}
	cout << endl;
}

void test_file_struct()
{
	METRO_struct buf = { 2020, 15, "001", "Tesla" };
	fstream File;
	File.open("Test.txt");
	File << buf;
}

void test_random_shuffle()
{
	srand(time(nullptr));

	vector<Troop*> Army;
	int warriors = 0, archers = 0, shelbyes = 0;
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			Army.push_back (new Warrior);
			++warriors;
			break;
		case 1:
			Army.push_back (new Archer);
			++archers;
			break;
		case 2:
			Army.push_back (new Shelby);
			++shelbyes;
		default:
			break;
		}
	}
	std::cout << "Army consist: [" << warriors << " Warriors]\t[" << archers << " Archers]\t[" << shelbyes << " Shelbyes]\n";
	for (int i = 0; i < 13; i++)
	{
		std::cout << "\n\t#" << i + 1 << "\n";
		for (auto element : Army)
		{
			element->attack();
			std::cout << endl;
		}
		random_shuffle(begin(Army), end(Army));
	}
	
	
}

void test_super()
{
	SuperWarrior LEGEND;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "\n\t#" << i + 1 << "\n";
		LEGEND.attack();
		std::cout << endl;
	}
}

int main()
{	
	test_random_shuffle();

	test_super();

    return 0;
}
