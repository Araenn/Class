/* Basic calculations of complexes (addition, subtraction, comparison) by creating classes. */

#include <iostream>

using namespace std;

class Complexe {

public:
	double re, im;

	Complexe() { 
		re = 0;
		im = 0;
	}

	Complexe(double r, double i) {
		re = r;
		im = i;
	}

	Complexe(double r) {
		re = r;
		im = 0;
	}

	double getReel() {
		return re;
	}

	void setReel(double re) {
		this->re = re;
	}

	double getImaginary() {
		return im;
	}

	void setImaginary(double im) {
		this->im = im;
	}

	void show() {
		if (im < 0) {
			cout << re << " - i" << -im << endl; /* affiche "- i im" et non "- i - im" */
		}
		else {
			cout << re << " + i" << im << endl;
		}
	}

	bool operator==(Complexe &a) {
		return a.getReel() == this->getReel();
	}

	Complexe operator+(Complexe &a) {
		Complexe c;
		c.setReel(a.getReel() + this->getReel());
		c.setImaginary(a.getImaginary() + this->getImaginary());
		return c;
	}

	Complexe operator-(Complexe &a) {
		Complexe c;
		c.setReel(a.getReel() - this->getReel());
		c.setImaginary(a.getImaginary() - this->getImaginary());
		return c;
	}
};

int main() { /* operations test */

	Complexe x;
	Complexe y(1);
	Complexe z(1,2);
	Complexe w = y + z;
	Complexe v = y - z;

	bool t = x == z;
	if (t == true) {
		printf("Complexes are equal\n");
	} else {
		printf("Complexes are not equal\n");
	}

	x.show();
	y.show();
	z.show();
	w.show();
	v.show();

}
