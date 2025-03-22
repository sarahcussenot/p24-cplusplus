#include <iostream>
#include <stdexcept>

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
public:
    IntStack (int s): nb(0), size(s){
        tab = new int[size];
    }

    ~IntStack(){
        delete[]tab;
    }

    IntStack (const IntStack&r) : n(r.n), tab = new int[size]; size(r.size){}

    void push(int e)
    {
        pile[remplissage] = e;
        remplissage = remplissage + 1;
        // cette fonction ajoute l'entier e dans la pile
    }
    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        if (remplissage > 0)
        {
            return pile[remplissage - 1];
        }
    }
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        remplissage = remplissage - 1;
        if (remplissage > 0)
        {
            return pile[remplissage];
        }
    }
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        return remplissage == 0;
    }
    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        return remplissage == SIZE;
    }
    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << '[';

        for (int i = 0; i < remplissage ; i++)
        {
            std::cout << pile[i];
            std::cout << ' ';
        }
        std::cout<< '[' <<std::endl;
    }

private:
    // vos attributs pour représenter la pile d'entier
    int n;  // nombre d'éléments
    int size; //taille 

    int* tab; //adresse du premier element du tableau
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
    IntStack s (120);  // constructeur pour la IntStack
    IntStack* ps = new IntStack;
    delete ps;
}
