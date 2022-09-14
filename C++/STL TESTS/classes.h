#pragma once
#include <iostream>
#include <thread>

class Troop
{
public:
	int hp, speed;
	Troop() :hp(50), speed(20) {};
	virtual void attack() = 0;
};

class Warrior : public Troop 
{
public:
	void attack() override;
	void print();
};

class Archer : public Troop 
{
public:
	void attack() override;
	void print();
};

class Shelby : public Troop
{
public:
	void attack() override;
	void print();
};

class SuperWarrior : public Warrior, public Archer
{
public:
	void attack() override;
	void print();
};