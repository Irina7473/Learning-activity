#pragma once
#include<iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Fraction;
Fraction operator-(Fraction left, Fraction right);
inline Fraction operator* (Fraction left, Fraction right);
inline Fraction operator/ (Fraction left, Fraction right);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denomiantor()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//			Constructors:
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction() {};
	//		Operators:
	Fraction& operator=(const Fraction& other);
	operator int();
	operator double();

	//			Methods:
	void print()const;
	void print_address()const;
	Fraction& proper();
	Fraction& improper();
	Fraction operator*=(const Fraction& other);
	Fraction inverted();
	Fraction& reduce(); //по алгоритму Евклида
	Fraction& operator/=(const Fraction& other);
	Fraction& operator++();  //префикс
	Fraction operator++(int); //постфикс
};

bool operator==(const Fraction& left, const Fraction& right);
ostream& operator<<(ostream& os, const Fraction& obj);
Fraction operator-(Fraction left, Fraction right);
inline Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (Fraction left, Fraction right);
