#include "Complex.h"
#include <iostream>
#include <cmath>

using namespace std;

complex::complex() : re(0.0), im(0.0) {}

complex::complex(double a) : re(a), im(0.0) {}

complex::complex(double a, double b) : re(a), im(b) {}

complex::complex(const complex& c) {
	re = c.re;
	im = c.im;
}

complex& complex:: operator=(const complex& rhs) {
	if (this != &rhs) {
		re = rhs.re;
		im = rhs.im;
	}
	return *this;
}

complex& complex:: operator+=(const complex& z) {
	re += z.re;
	im += z.im;
	return *this;
}

complex& complex:: operator-=(const complex& z) {
	re -= z.re;
	im -= z.im;
	return *this;
}

complex& complex:: operator*=(const complex& z) {
	double temp_re;
	temp_re = ((re * z.re) - (im * z.im)); //calculates imaginary part
	im = ((re * z.im) + (im * z.re)); //calculates real part
	re = temp_re;
	return *this;
}

complex& complex:: operator/=(const complex& z) {
	double denom = ((z.re * z.re) + (z.im * z.im));
	double temp_re = ((re * z.re) + (im * z.im)) / denom;
	im = ((im * z.re) - (re * z.im)) / denom;
	re = temp_re;
	return *this;
}

complex& complex:: operator+=(const double x) {
	re += x;
	return *this;
}

complex& complex:: operator-=(const double z) {
	re -= z;
	return *this;
}

complex& complex:: operator*=(const double z) {
	re *= z;
	im *= z;
	return *this;
}

complex& complex:: operator/=(const double z) {
	re /= z;
	im /= z;
	return *this;
}

double complex::real() const {
	return re;
}

double complex::imag() const {
	return im;
}

double complex::magnitude() const {
	return sqrt((re * re) + (im * im));
}

complex operator+(const complex& z1, const complex& z2) {
	complex result = z1;
	result += z2;
	return result;
}

complex operator+(const complex& z1, double x) {
	complex result(z1);
	result += x;
	return result;
}

complex operator+(const double x, const complex& z) {
	complex result(z);
	result += x;
	return result;
}

complex operator-(const complex& z1, const complex& z2) {
	complex result = z1;
	result -= z2;
	return result;
}

complex operator-(const complex& z1, const double x) {
	complex result = z1;
	result -= x;
	return result;
}

complex operator-(const double x, const complex& z) {
	complex result(z);
	result -= x;
	return result;
}


complex operator*(const complex& z1, const complex& z2) {
	complex result = z1;
	result *= z2;
	return result;
}

complex operator*(const complex& z1, const double x) {
	complex result = z1;
	result *= x;
	return result;
}

complex operator*(const double x, const complex& z) {
	return complex(x * z.real(), x * z.imag());
}


complex operator/(const complex& z1, const complex& z2) {
	double denominator = z2.real() * z2.real() + z2.imag() * z2.imag(); // Calculate the denominator
	
	double realPart = (z1.real() * z2.real() + z1.imag() * z2.imag()) / denominator;
	double imagPart = (z1.imag() * z2.real() - z1.real() * z2.imag()) / denominator; 

	return complex(realPart, imagPart); 
}

complex operator+(const complex& z) {
	return z;
}

complex operator-(const complex& z) {
	return complex(-z.real(), -z.imag());
}

bool operator==(const complex& z1, const complex& z2) {
	return ((z1.real() == z2.real()) && (z1.imag() == z2.imag()));
}

bool operator!=(const complex& z1, const complex& z2) {
	return (!(z1 == z2));
}

ostream& operator<<(ostream& os, const complex& z) {
	os << "(" << z.real() << ", " << z.imag() << ")";
	return os;
}

istream& operator>>(istream& is, complex& z) {
	char leftParen, comma, rightParen;
	double realPart, imagPart;

	is >> leftParen >> realPart >> comma >> imagPart >> rightParen;

	if (leftParen == '(' && comma == ',' && rightParen == ')') {
		z = complex(realPart, imagPart);
	}

	return is;
}

double magnitude(const complex& z) {
	return z.magnitude();
}

double real(const complex& z) {
	return z.real();
}

double imag(const complex& z) {
	return z.imag();
}

complex polar(const double r, const double theta) {
	return complex(r * cos(theta), r * sin(theta));
}

complex polar(const double r) {
	return complex(r, 0);
}

complex conj(const complex& z) {
	return complex(z.real(), -z.imag());
}

double norm(const complex& z) {
	return ((z.real() * z.real()) + (z.imag() * z.imag()));
}

double arg(const complex& z) {
	return atan2(z.imag(), z.real());
}
