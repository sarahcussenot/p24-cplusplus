#include "rational_sep.h"

Rational::Rational() : numerateur(0), denominateur(1) {}

Rational::Rational(int u) : numerateur(u), denominateur(1) {}

Rational::Rational(int a, int b) {
    if (b == 0) {
        std::cout << "on ne peut pas diviser par zero" << std::endl;
        throw 1;
    } else {
        numerateur = a;
        denominateur = b;
    }
}

float Rational::div_c() const {
    return static_cast<float>(numerateur) / denominateur;
}

float Rational::eval() const {
    return static_cast<float>(numerateur) / denominateur;
}

Rational operator+(Rational r1, Rational r2) {
    return Rational(r1.numerateur * r2.denominateur + r2.numerateur * r1.denominateur, r1.denominateur * r2.denominateur);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerateur << "/" << r.denominateur;
    return os;
}

void Rational::print() const {
    std::cout << numerateur << "/" << denominateur << std::endl;
}
