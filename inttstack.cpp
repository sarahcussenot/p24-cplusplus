#include <iostream>
#include <stdexcept>

// constante entière pour la taille de la pile
const int SIZE{12};

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
public:

    IntStack(int s) : pos(0), SIZE(s)
    {
        ti = new int[SIZE];
    }

    IntStack(const IntStack &r) : pos(r.pos), SIZE(r.SIZE)
    { // derrière les : on a pas des affectations 
        ti = new int[SIZE];
        for (int i = 0; i < pos; i++)
        {
            *(ti + i) = r.ti[i];
        }
    }

    IntStack &operator=(const IntStack &r)
    // on redéfinit l'opérateur =
    {
        if (this != &r)
        {
            delete[] ti;
            SIZE = r.SIZE;
            pos = r.pos;
            ti = new int[SIZE];
            for (int i = 0; i < pos; i++)
            {
                ti[i] = r.ti[i];
            }
        }
        return *this;
    }

    ~IntStack()
    {
        // on redéfinit la destruction
        delete[] ti;
    }

    void push(int e)
    {
        if (is_full() == false)
        {
            *(ti+pos) = e; //on ajoute à la suite le nouvel élément 
            // on le fait tant qu'on reste dans l'espace alloué
            pos++;
        }
        // cette fonction ajoute l'entier e dans la pile
    }
    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        return *(ti+pos);
    }
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        if (is_empty() == false)
        {
            get_top();
            return *(ti + --pos);
            //on ne supprime pas vraiment le dernier empile
            //on change juste l'adresse du dernier entier
        }
    }
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
    //la pile est vide si pos est nul
        return pos == 0;
    }

    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // la pile est plein si pos vaut SIZE
        return pos == SIZE;

    }

    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << '[';

        for (int i = 0; i < pos; i++)
        {
            std::cout << *(ti+i); //on renvoie l'élement dans l'ordre
            // grace au parcours linéaire des adresses
            std::cout << ' ';
        }
        std::cout << '[' << std::endl;
    }

private:
    // vos attributs pour représenter la pile d'entier
    int SIZE;
    int *ti;
    int pos;
    // dans cette version toutes les piles sont de taille SIZE
};

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    IntStack s1;
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}