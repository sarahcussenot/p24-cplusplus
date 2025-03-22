#include <iostream>

class Rational
{
private:
    int numerateur{};
    int denominateur{1};

public:
    Rational() : numerateur(0), denominateur(1) {}
    Rational(int u) : numerateur(u), denominateur(1) {}
    Rational(int a, int b)
    {
        if (b == 0)
        {
            std::cout << "on ne peut pas diviser par zero" << std::endl;
            throw 1;
        }
        else
        {
            numerateur = a;
            denominateur = b;
        }
    }
    // en c
    float div_c()
    {
        float d = float(numerateur) / float(denominateur);
        return d;
    }
    // en C++
    float eval()
    {
        float d = static_cast<float>(numerateur) / denominateur;
        return d;
    }

    friend Rational operator+(Rational, Rational);
    friend std::ostream &operator<<(std::ostream &, const Rational &);
    void print()
    {
        std::cout << numerateur << "/" << denominateur << std::endl;
    }

    // faire une fonction test de egalite, somme, valeur flottante operateur +
};

// Redefinir un opérateur
Rational operator+(Rational r1, Rational r2)
{
    return Rational(r1.numerateur * r2.denominateur + r2.numerateur * r1.denominateur, r1.denominateur * r2.denominateur);
}

// surcharge operateur
std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.numerateur << "/" << r.denominateur;
    return os;
}

int main()
{
    Rational r1;
    // 0/1 si on donne rien numér ateur à 0, denominateur à 1
    Rational r2(1);
    Rational r3(4, 6);
    Rational r4(1, 2);
    Rational r5 = r3 + r4;
    std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    return 0;
}