// début de la définition de la classe MyNewType
#include <iostream>

class MyNewType
{
    // affichage des objets de ce type friend si besoin d'accéder aux attributs ou méthodes privées
    friend std::ostream &operator<<(std::ostream &os,
                                    const MyNewType &r);

    // surcharge des opérateurs classiques si besoin
    friend MyNewType operator+(const MyNewType &r1,
                               const MyNewType &r2);

private:
    // attributs qui constituent les objets de ce type
    int attr1{0}; // valeurs par défaut
    int attr2{0};
    // méthodes privées qui manipulent les objets de ce type
    void method1()
    {
        std::cout << "method1" << std::endl;
    }

public:
    // constructeurs (ou un seul constructeur avec des arguments par défaut)
    // constructeur par défaut généré par le compilateur (optionnel)
    MyNewType() = default;

    // constructeur avec un seul argument
    // on peut empêcher la conversion implicite avec explicit
    explicit MyNewType(int attr) : attr1{attr}, attr2{attr} // liste d'initialisation
    {
        std::cout << "constructeur avec un seul argument" << std::endl;
    }

    // constructeur avec deux arguments
    MyNewType(int attr1, int attr2) : attr1{attr1}, attr2{attr2} // liste d'initialisation
    {
        std::cout << "constructeur avec deux arguments" << std::endl;
    }

    // constructeur de copie si nécessaire
    MyNewType(const MyNewType &r)
    {
        std::cout << "constructeur de copie" << std::endl;
    }

    // destructeur si nécessaire (quelque chose à libérer à défaire)
    ~MyNewType()
    {
        std::cout << "destructeur" << std::endl;
    }

    // surcharge de l'opérateur d'affectation si nécessaire (quelque chose à libérer à défaire)
    MyNewType &
    operator=(const MyNewType &r)
    {
        if (this != &r) // toujours tester si on n'a pas une auto affectation (t = t)
        {
            std::cout << "opérateur d'affectation" << std::endl;
        }
        return *this; // toujours retourner l'objet courant pour chaîner les opérations (t1 = t2 = t3)
    }

    // méthodes publiques qui manipulent les objets de ce type
    // c'est l'interface publique de votre classe
    void method2()
    {
        std::cout << "method2" << std::endl;
    }
    void method3()
    {
        method1(); // appel d'une méthode privée
        std::cout << "method3" << std::endl;
    }
};

// inline pour que l'appel de la fonction soit remplacé par le code de la fonction (si possible)
// l'appel sera plus rapide (pas de fonction définie à appeler)
// mais le code doit être visible partout où la fonction est appelée (sinon on ne peut pas remplacer l'appel par le code...)

// affichage des objets de ce type friend si besoin
inline std::ostream &operator<<(std::ostream &os, const MyNewType &obj)
{
    os << "affichage de l'objet " << obj.attr1 << " " << obj.attr2 << std::endl;
    return os;
}

// affichage des objets de ce type friend si besoin
inline MyNewType operator+(const MyNewType &r1, const MyNewType &r2)
{
    return MyNewType{r1.attr1 + r2.attr1, r1.attr2 + r2.attr2};
}

// fin de la définition de la classe MyNewType
int main()
{
    MyNewType t1;                 // appel du constructeur par défaut
    t1.method2();                 // appel d'une méthode publique
    std::cout << t1 << std::endl; // affichage de l'objet t1

    MyNewType t2{1, 2}; // appel du constructeur avec arguments
    t2.method3();       // appel d'une méthode publique

    MyNewType t3{t1}; // appel du constructeur de copie

    t1 = t2; // appel de l'opérateur d'affectation

    MyNewType t4{17, 5};
    MyNewType t5 = t2 + t4; // appel de l'opérateur +
    std::cout << t5 << std::endl;

    t1 = t2 = t3;
    // équivalent à:
    t1.operator=(t2.operator=(t3));

    std::cout << "affichage chaînés" << std::endl;
    std::cout << t1 << t2 << t3;
    // équivalent à:
    operator<<(operator<<(operator<<(std::cout, t3), t2), t1);

    // on sort du programme sans erreur en renvoyant 0 = succès
    return 0;
    // équivalent à renvoyer EXIT_SUCCESS qui vaut 0
    // return EXIT_SUCCESS;

    // on peut aussi sortir en échec si besoin avec return 1 (ou autre valeur)
    // équivalent à renvoyer EXIT_FAILURE
    // return EXIT_FAILURE;
}