#include <iostream>

int i; // je déclare une variable i en dehors de tout le reste en donnant son type, valeur par defaut est 0
// en c++ toutes les variables globales sont a zero initialement

int add (int a, int b);
extern int i;

int main (int argc, char* argv[]) 
{
    std::cout << add(i, 90) <<std::endl;
    return 0;
}

int add (int i, int j) {
    return i+j;
}
// on crée une fonction add qui prend en entrée un entier i, un entier j et qui fait l'addition, renvoie un int (precise au debut)
// ici le i des variables d entre n est pas le i global, propre a la fonction