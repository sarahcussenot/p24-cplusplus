#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int numerateur;
    int denominateur;

public:
    Rational();
    Rational(int u);
    Rational(int a, int b);

    float div_c() const;
    float eval() const;

    friend Rational operator+(Rational, Rational);
    friend std::ostream& operator<<(std::ostream&, const Rational&);

    void print() const;
};

#endif // RATIONAL_H
