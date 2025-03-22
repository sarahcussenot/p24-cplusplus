int main() {
    int i = 10;
    {
        int* pi = new int {i}; // si pi est une adresse, *pi est pour aller à l'adresse indiquée
        *pi = 17;
        delete pi;
    }
    return 0;
}


// créer un tableau d'entiers 
// new int[10]; on veut 10 entiers
// int* ti= new int[10] pareil que int tab[10]  en mémoire dynamque alloue dans la mémoire dynamique un tableau contigü donc ti est l'dresse du premier élément
// pour supprimer delete [] ti