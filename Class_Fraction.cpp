#pragma once
#include "Class_Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denomiantor()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	this->denominator = denominator ? denominator : 1;
}

//			Constructors:
Fraction::Fraction()
{
	integer = numerator = 0;
	denominator = 1;
	//cout << "DefaultConstructor:" << this << endl;
}
Fraction::Fraction(int integer)
{
	//Конструктор с одним параметром
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	//cout << "1argConstructor:" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->denominator = denominator;
	//cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	//cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:" << this << endl;
}




//				Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:" << this << endl;
	return *this;
}

Fraction::operator int()
{
	this->proper();
	return integer;
}
Fraction::operator double()
{

	return integer + (double)numerator / denominator;
}

//			Methods:
void Fraction::print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	if (integer == 0 && numerator == 0)cout << 0;
	cout << endl;
}
void Fraction::print_address()const
{
	cout << "Object:\t\t" << this << "\n";
	cout << "Integer:\t" << &integer << "\n";
	cout << "Numerator:\t" << &numerator << "\n";
	cout << "Denominator:\t" << &denominator << "\n";
}

Fraction& Fraction::proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction& Fraction::improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction Fraction:: operator*=(const Fraction& other)
{
	return *this = *this * other;
}

Fraction Fraction::inverted()
{
	this->improper();
	return Fraction(denominator, numerator);
}

Fraction& Fraction::reduce() //по алгоритму Евклида
{
	int more, less, rest;
	if (numerator < denominator)
	{
		less = numerator;
		more = denominator;
	}
	else
	{
		less = denominator;
		more = numerator;
	}

	for (rest = 1; rest == 0; )
	{
		rest = more % less;
		more = less;
		less = rest;
	}

	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

Fraction& Fraction::operator++()  //префикс
{
	integer++;
	return *this;
}

Fraction Fraction::operator++(int)  //постфикс
{
	Fraction old = *this;
	integer++;
	return old;
}



bool operator==(const Fraction& left, const Fraction& right)
{
	/*if (left.get_integer() == right.get_integer() &&
		left.get_numerator() == right.get_numerator() &&
		left.get_denomiantor() == right.get_denomiantor())
				return true;
	else return false;*/

	return left.get_integer() == right.get_integer() &&
		left.get_numerator() == right.get_numerator() &&
		left.get_denomiantor() == right.get_denomiantor();

}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer() != 0) os << obj.get_integer() << ' ';
	if (obj.get_numerator() != 0) os << obj.get_numerator() << '/' << obj.get_denomiantor() << ' ';
	return os;
}

Fraction operator-(Fraction left, Fraction right)
{
	Fraction result(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denomiantor() -
		right.get_numerator() * left.get_denomiantor(),
		left.get_denomiantor() * right.get_denomiantor()
	);

	return result.proper();
}

inline Fraction operator* (Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	Fraction result(left.get_numerator() * right.get_numerator(), left.get_denomiantor() * right.get_denomiantor());
	return result.proper();
}

Fraction operator/ (Fraction left, Fraction right)
{
	return left * right.inverted();
}
