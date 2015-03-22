#include "animal.h"

Animal::Animal(string name, string password)
{
	this->name = name;
	this->password = password;
}

void Animal::shout()
{
	cout<<"animal shout"<<endl;
}

Cat::Cat(string name, string password) : Animal(name, password)
{
}

void Cat::shout()
{
	cout<<"cat shout"<<endl;
}

Dog::Dog(string name, string password) : Animal(name, password)
{
}

void Dog::shout()
{
	cout<<"dog shout"<<endl;
}