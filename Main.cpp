// P03ComplexNumbersDriver
// SaraM
// SAMPLE TEST SUITE structure. YOU MUST COMPLETE MANY MORE TESTS
// Test Suite for complex number class


#include <iostream>
#include "Complex.h"
#include <cmath>
#include <assert.h>
using namespace std;

// test function that drives multiple infix operators over complex and double arguments
complex f(const complex& z) {
	return z * z * z - 3 * z * z + 4 * z - 2;
}

//approx_value is used for testing equivalent values of type double
inline bool approx_value(double x, double y) {
	return (y - .0001 <= x && x <= y + .0001);
}

bool assertx(bool expr, unsigned line) {
	if (!expr) cerr << "Error at line " << line << endl; return expr;
}

int main()
{
	const double PI = 3.141592653589793;
	const complex i(0, 1); // complex number i = 0 +1i
	complex z1, z2, z3;
	complex z4 = complex(1, 2);
	complex complex_number[] = { complex(2,3),  complex(-1,1), complex(1,1),
							  complex(1,-1), complex(1,0) };
	complex sum = 0.0;
	double x1;
	double y1;
	// for use with polar tests
	complex z8;
	double r_z8;
	double arg_z8;

	complex z5;
	cout << "\nTesting >>: input a complex number (3, -2): ";
	cin >> z5;
	assertx(z5.real() == 3.0, __LINE__);
	assertx(z5.imag() == -2.0, __LINE__);

	cout << "\nTesting <<: output a complex number(3, -2): " << z5;

	cout << "\n\nTesting Assignment Operator";
	z1 = complex(3, 2);
	z2 = complex(-4, 3);
	z4 = z3;

	cout << "\n\nTesting Complex Math Operators with Object";
	z3 += z2;
	assertx(z3 == z2, __LINE__);
	z3 -= z2;
	assertx(z4 == z3, __LINE__);
	z3 *= z2;
	z3 /= z2;
	assertx(z3 == z4, __LINE__);

	cout << "\n\nTesting Complex Math Operators with Constants";
	x1 = z3.real();
	y1 = z3.imag();
	const double C = 3.0;
	z3 += C;
	assertx((z3.real() == (x1 + C)) && (z3.imag() == y1), __LINE__);
	z3 -= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);
	z3 *= C;
	assertx((z3.real() == (x1 * C)) && (z3.imag() == (y1 * C)), __LINE__);
	z3 /= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);

	cout << "\n\nTesting Complex Infix Operators with Objects";
	assertx(z1 == complex(3, 2), __LINE__);
	assertx(z2 == complex(-4, 3), __LINE__);
	assertx((z1 + z2) == complex(-1, 5), __LINE__);
	assertx((z1 - z2) == complex(7, -1), __LINE__);
	assertx((z1 * z2) == complex(-18, 1), __LINE__);
	assertx((z1 / z2) == complex(-0.24, -0.68), __LINE__);

	cout << "\n\nTesting Polar Magnitude Calculation";
	z1 = complex(2, 3);  //note change of value bound to z1
	assertx(z1.real() == 2.0, __LINE__);
	assertx(z1.imag() == 3.0, __LINE__);
	assertx(real(z1) == 2.0, __LINE__);
	assertx(imag(z1) == 3.0, __LINE__);
	assertx(z1.magnitude() == sqrt(z1.real() * z1.real() + z1.imag() * z1.imag()), __LINE__);

	cout << "\n\nTesting Polar Arg Calculation";
	assertx(arg(complex(1., 0.)) == 0.0, __LINE__);
	assertx(approx_value(arg(complex(0, 1)), PI / 2.0), __LINE__);
	assertx(approx_value(arg(complex(-1, 0)), PI), __LINE__);

	cout << "\n\nTesting Coordinate to Polar";
	z8 = complex{ .5, 4.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), .5), __LINE__);
	assertx(approx_value(polar(r_z8, arg_z8).imag(), 4.0), __LINE__);

	z8 = complex{ -3.0, 7.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), -3.0), __LINE__);
	assertx(approx_value(polar(7.61577, 1.97569).imag(), 7.0), __LINE__);

	cout << "\n\nTesting Chained Calculations";
	// evaluate f(z), z = 2+3i, -1+i, 1+i, 1-i, 1+0i -- chaining
	assertx(f(complex_number[0]) == complex(-25, -15), __LINE__);
	assertx(f(complex_number[1]) == complex(-4, 12), __LINE__);
	assertx(f(complex_number[2]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[3]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[4]) == complex(0, 0), __LINE__);

	// ************************* STUDENTS SHOULD ADD AT LEAST 10 ADDITIONAL TESTS HERE **************************

	cout << "\n\nTesting Default Constructor";
	complex z_default;
	assertx(z_default.real() == 0.0 && z_default.imag() == 0.0, __LINE__);

	cout << "\n\nTesting Constructor with One Argument (Real Part)";
	complex z_single(5.0);
	assertx(z_single.real() == 5.0 && z_single.imag() == 0.0, __LINE__);

	cout << "\n\nTesting Constructor with Negative Values";
	complex z_negative(-2, -3);
	assertx(z_negative.real() == -2.0 && z_negative.imag() == -3.0, __LINE__);

	cout << "\n\nTesting Adding Complex Numbers";
	complex z_add1(1, 2);
	complex z_add2(3, 4);
	assertx((z_add1 + z_add2) == complex(4, 6), __LINE__);

	cout << "\n\nTesting Subtracting Complex Numbers";
	complex z_sub1(5, 7);
	complex z_sub2(2, 3);
	assertx((z_sub1 - z_sub2) == complex(3, 4), __LINE__);

	cout << "\n\nTesting Multiplying Complex Numbers";
	complex z_mul1(1, 2);
	complex z_mul2(3, 4);
	assertx((z_mul1* z_mul2) == complex(-5, 10), __LINE__);

	cout << "\n\nTesting Dividing Complex Numbers";
	complex z_div1(1, 2);
	complex z_div2(2, 3);
	assertx(approx_value(real(z_div1 / z_div2), 0.615384), __LINE__);
	assertx(approx_value(imag(z_div1 / z_div2), 0.076923), __LINE__);

	cout << "\n\nTesting Magnitude Calculation";
	complex z_mag(3, 4);
	assertx(z_mag.magnitude() == 5.0, __LINE__);

	cout << "\n\nTesting Argument Calculation";
	complex z_arg(1, 1);
	assertx(approx_value(arg(z_arg), PI / 4.0), __LINE__);

	cout << "\n\nTesting Comparison Operator";
	complex z_comp1(1, 1);
	complex z_comp2(1, 1);
	assertx(z_comp1 == z_comp2, __LINE__);





	cout << "\n\nPASSED TESTS\n";

	return 0;
} //end main
