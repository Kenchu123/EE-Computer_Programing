#include <iostream>
using namespace std;

class Complex{
    protected:
        double re;
        double im;
    public:
        Complex():re(0), im(0){}
        Complex(double a,double b):re(a), im(b){}
        Complex operator+(const Complex&);
        Complex operator||(const Complex&);
        friend istream& operator>>(istream &input,Complex &c);
        friend ostream& operator<<(ostream &output,Complex &c);
};

class Resistor: public Complex{
    public:
        Resistor():Complex() {}
        Resistor(double r):Complex(r, 0) {}
        friend istream& operator>>(istream &,Resistor &);
};


class Capacitor: public Resistor{
    private:
        double C;
        double w;
    public:
        Capacitor():C(0), w(0){}
        Capacitor(double Cin, double win):C(Cin), w(win){ compute(); }
        void compute();
        friend istream& operator>>(istream &,Capacitor &);
};


class Inductor: public Resistor{
    private:
        double L;
        double w;
    public:
        Inductor():L(0), w(0){}
        Inductor(double Lin,double win):L(Lin), w(win){ compute(); }
        void compute();
        friend istream& operator>>(istream &,Inductor &);
};

// TEMPLATE BEGIN
Complex Complex::operator+(const Complex& c) {
    
    Complex* sum = new Complex(this->re + c.re, this->im + c.im);
    return *sum;
}

Complex Complex::operator||(const Complex& C) {
    double a = this->re, b = this->im, c = C.re, d = C.im;
    double ac = a + c, bd = b + d;
    double upre = (a + c) * (a * c - b * d) + (b + d) * (a * d + b * c);
    double upim = (a + c) * (a * d + b * c) - (b + d) * (a * c - b * d);
    double down = ac * ac + bd * bd;
    Complex* ans =  new Complex(upre / down, upim / down);
    return *ans;
}

istream& operator>>(istream &input,Complex &c) {
    input >> c.re >> c.im;
    return input;
}
ostream& operator<<(ostream &output,Complex &c) {
    if (c.re == 0 && c.im == 0) {
        output << "0\n";
        return output;
    }
    if (c.re != 0) {
        output << c.re;
    }
    if (c.im > 0 && c.re != 0) output << "+";
    if (c.im != 0) output << c.im << "i";
    output << endl;
    return output;
}


istream& operator>>(istream& input, Resistor& r) {
    input >> r.re;
    r.im = 0;
    return input;
}

void Capacitor::compute() {
    im = -1 / (w * C);
}

istream& operator>>(istream& input, Capacitor& c) {
    input >> c.C >> c.w;
    c.compute();
    return input;
}

void Inductor::compute() {
    im = w * L;
}

istream& operator>>(istream& input, Inductor& i) {
    input >> i.L >> i.w;
    i.compute();
    return input;
}
// TEMPLATE END

int main() {
    Complex Zeq, Zeq2, Zeq3, Zeq4;
    Resistor r1(3), r2(4), r3(5), r4, r5;
    Capacitor zC(0.00003,10000), zC2;
    Inductor zL(0.1,10000), zL2;
    Zeq = (r1||r2||r3);
    Zeq2 = (zC+zL);
    cout << Zeq << Zeq2;

    cin >> r4 >> zC2;
    Zeq3 = r4 + zC2;
    cout << Zeq3;

    cin >> r5 >> zL2;
    Zeq4 = r5 || zL2;
    cout << Zeq4;
    return 0;
}