#pragma once

namespace ad {

struct Dual {
		double value;
		double derivative;

		Dual(double v = 0.0, double d = 0.0): value(v), derivative(d) {}
		friend Dual operator+(Dual a, Dual b);
		friend Dual operator-(Dual a, Dual b);
		friend Dual operator*(Dual a, Dual b);
		friend Dual operator/(Dual a, Dual b);
};


Dual sin(Dual x);
Dual exp(Dual x);

}
