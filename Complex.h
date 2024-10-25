#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class complex {
public:

	complex();

	complex(double a);

	complex(double a, double b);

	complex(const complex& c);

	complex& operator=(const complex& rhs);

	complex& operator+=(const complex& z);

	complex& operator-=(const complex& z);

	complex& operator*=(const complex& z);

	complex& operator/=(const complex& z);

	complex& operator+=(const double x);

	complex& operator-=(const double z);

	complex& operator*=(const double z);

	complex& operator /=(const double z);

	double real() const;

	double imag() const;

	double magnitude() const;



private:
	double re, im;
};

complex operator+(const complex& z1, const complex& z2);

complex operator+(const complex& z1, const double x);

complex operator+(const double x, const complex& z);

complex operator+(const complex& z);

complex operator-(const complex& z);

bool operator==(const complex& z1, const complex& z2);

bool operator!=(const complex& z1, const complex& z2);

ostream& operator<<(ostream& os, const complex& z);

istream& operator>>(istream& is, complex& z);

double magnitude(const complex& z);

double real(const complex& z);

double imag(const complex& z);

complex operator-(const complex& z1, const complex& z2);

complex operator-(const complex& z1, const double x);

complex operator-(const double x, const complex& z);

complex operator*(const complex& z1, const complex& z2);

complex operator*(const complex& z1, const double x);

complex operator*(const double x, const complex& z);

complex operator/(const complex& z1, const complex& z2);

complex polar(const double r, const double theta);

complex polar(const double r);

complex conj(const complex& z);

double norm(const complex& z);

double arg(const complex& z);
