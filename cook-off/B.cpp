#include <iostream>

class Fraction {
    private:

        long long gcd(long long a, long long b) {
            while (a != b) {
                if (a > b) {
                    a -= b;
                } else {
                    b -= a;
                }
            }
            return a;
        }

    public:
        long long numerator, denominator;

        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(long long n, long long d) {
            if (d==0) {
                std::cerr << "Denominator may not be 0." << std::endl;
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                long long tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }

        operator int() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator,
                 lhs.denominator*rhs.numerator);
    return tmp;
}

std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

int main() {
    Fraction a(1,3);
    Fraction b(3,28);
    Fraction c;

    c = a + b;
    std::cout << c << "\t(should be 37/84)" << std::endl;

    c = a - b;
    std::cout << c << "\t(should be 19/84)" << std::endl;

    c = a * b;
    std::cout << c << "\t(should be 1/28)" << std::endl;

    c = a / b;
    std::cout << c << "\t(should be 28/9)" << std::endl;

    c = -1 * b;
    std::cout << c << "\t(should be -3/28)" << std::endl;

    c = b * (-1);
    std::cout << c << "\t(should be -3/28)" << std::endl;

    c = Fraction(-100,3);
    std::cout <<    (int)c << "\t(should be -33)" << std::endl;
    std::cout <<  (float)c << "\t(should be -33.3...)" << std::endl;
    std::cout << (double)c << "\t(should be -33.3...)" << std::endl;

    a -= b;
    std::cout << a << "\t(should be 19/84)" << std::endl;

    return 0;
}
