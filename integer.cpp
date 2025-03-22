#include <iostream>

class Integer
{
    // faire des methodes privées non visibles par le main
private:
    int value{};
    // le mieux est de tout mettre en privé puis de rendre certaines choses publiques
public:
    // methpde definie dans la classe integer
    // toutes les methodes qui commencent par integer
    Integer(int v)
    {              // le constructeur prend un argument
        value = v; // c'est une affectation
    } // on appelle du nom de la classe les mzthodes qui construisent des objets de cette classe
    // si on veut initialiser out l'objet avant de rentrer dans le constructeur

    Integer() : value(0) {} // constructeur par défaut d'argument i.e. valeur par défaut des arguments
    void incr()
    {
        value = value + 1;
    }
    // par défaut class met tout en privé et struct met tout en public
};
// c++ va traiter le type integer comme ses types

int main()
{
    Integer i;
    // i a un type et on peut lui appilquer incr
    Integer j = i;
    // construction d'un objet par copie
    i = j;
    i.incr();
    // .incr est une methode
    Integer k(-17);
    return 0;
}
