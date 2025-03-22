// on veut retenir les cases où se trouve le serpent
// on définit une classe tableau à deux entrées comme dans python pour simuler le board
// on définit le serpent par un table de couples donnant la position
// on veut tirer au sort l'endroit où se trouve la pomme dans les cases non occupées (en faisant une fonction qui indique les cases non occupées sur un ligne,
// complémentaire du serpent)

// temps que l'utilisateur ne jour pas : toutes les secondes on fait avancer le serpent dans la direction précédente (en vérifiant les bords
// et les intersections )
// au bout de une seconde :
// calcul du nouveau board
// vérification du nouveau board :
// si atteint bord perd le jeu
// si mange une pomme grandit
// si pas de conflit, affichage du nouveau board

// quand le joueur donne une direction :
// changer la variable de direction (une fonction lgobale qui ne distingue la direction qu'en bout de chaîne
// générer une nouvelle pomme et un nouveau board
// remettre à l'initialisation

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pour exit et rand
#include <deque>

// 1) un tableau de caractères pour représenter le board (std::vector<char>)
//      * faites un seul std::vector<char>
//      * gérez les lignes et colonnes vous-même où
//        position(i, j) est la case du tableau de taille (lignes * colonnes) à la i_ème ligne et j_ème colonne

void draw_board(const serpent, const pomme)
{
    //
}

// 2) une structure pour représenter le serpent qui grandit et qui change de position...
//      * à vous de réfléchir (il n'y a pas de solution unique idéale)
//      (vous pouvez utiliser un std::vector<???> pour stocker les positions du serpent ou une deque ou une liste chaînée...)

// 3) quelque chose pour la position de la pomme

// Pour afficher ces états successifs du jeu:
//    0) vous avez créé initialement un board de taille rows x columns de '.' (les caractères représentant le board),
//       un serpent de taille 3 et une pomme (positionnés tous les deux sur le board)

int rows = 5 int columns = 7 std::vector<std::pair<int, int>> snake;
std::vector<char> tab(rows *columns, '.');
tab[i * columns + rows]



// initialisation du








    int
    simple_random(int n) // simple random generation of a integer between 0 and n
{
    return rand() % n;
}

// puis:
//    1) vous ré-initialisez le board avec des '.'
//    2) vous mettez les caractères représentant le serpent dans le vecteur représentant le board
//    3) vous mettez la pomme dans le vecteur représentant le board
//    4) vous affichez le board (qui contient le serpent et la pomme)
//    5) vous attendez une commande ('i', 'k', 'j', 'l' ou 'q')
//    6) vous regardez où vous devez déplacer le serpent
//    7) si tout se passe bien, vous modifiez votre serpent qui éventuellement grandit
//    8) vous recommencez à l'étape 1

// Si la commande échoue, vous affichez un message d'erreur et vous sortez du jeu avec exit(2).

// faire une classe position