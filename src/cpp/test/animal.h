#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal
{
public:
	string name;
	string password;

	Animal(string name, string password);
	virtual void shout();
};

class Cat : public Animal
{
public:
	Cat(string name, string password);
	void shout();
};

class Dog : public Animal
{
public:
	Dog(string name, string password);
	void shout();
};

#endif