
#include "classes.h"
#include <iostream>

void Warrior::print()
{
	for (int i = 0; i < 10; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(speed * 10));
		std::cout << "<-> ";
	}
}
void Warrior::attack()
{
	if (hp)
	{
		hp -= 10;
		std::cout << "\t<=====|~~~> Warrior is attacking you <~~~|=====>\tMy hp: " << hp << "\n\t\t";
		print();
	}
	else std::cout << "Warrior have died";
}

void Archer::print()
{
	for (int i = 0; i < 30; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		std::cout << "~";
	}
}
void Archer::attack()
{
	if (hp)
	{
		hp -= 10;
		std::cout << "\t~~ Archer is attack you! ~~\tMy hp: " << hp << "\n\t\t";
		print();
	}
	else std::cout << "Archer have died";
}


void SuperWarrior::print()
{
	std::cout << "\t! + ~ ===== SUPER WARRIOR ===== ~ + !\tMy hp: " << SuperWarrior::Warrior::hp + SuperWarrior::Archer::hp << "\n\t\t";
	for (int i = 0; i < 3; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SuperWarrior::Warrior::speed * 50));
		std::cout << "BUM ";
	}
}
void SuperWarrior::attack()
{
	if (SuperWarrior::Warrior::hp)
	{
		SuperWarrior::Warrior::hp -= 10;
		print();
		SuperWarrior::Warrior::print();
		
	}
	else if (SuperWarrior::Archer::hp)
	{
		SuperWarrior::Archer::hp -= 10;
		print();
		SuperWarrior::Archer::print();
	}
	else std::cout << "SuperWarrior have died";
}

void Shelby::print()
{
	std::cout << 'c';
	std::this_thread::sleep_for(std::chrono::milliseconds(speed * 7));
	std::cout << 'l';
	std::this_thread::sleep_for(std::chrono::milliseconds(speed * 7));
	std::cout << 'u';
	std::this_thread::sleep_for(std::chrono::milliseconds(speed * 7));
	std::cout << 'c';
	std::this_thread::sleep_for(std::chrono::milliseconds(speed * 7));
	std::cout << "k ";
}
void Shelby::attack()
{
	if (hp)
	{
		hp -= 10;
		std::cout << "\t(===) (=) Shelby (=) (===)\tMy hp: " << hp << "\n\t\t";
		for (int i = 0; i < 4; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(speed * 20));
			print();
		}
	}
	else std::cout << "Shelby have died";
}
