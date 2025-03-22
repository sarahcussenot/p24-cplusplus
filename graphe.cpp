#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_set>

// création de la classe Graph pour représenter le graphe avec des vecteurs
class Graph
{
private:
    // liste d'adjacence : listadj[a] doit donner tous les couples sommets et poids auxquels a est lié
    std::unordered_map<int, std::vector<std::pair<int, int>>> listadj;

public:
    // ajout d'une arête pondérée au graphe
    void addEdge(int a, int b, int poids)
    {
        listadj[a].push_back({b, poids});
        listadj[b].push_back({a, poids});
    }

    // représentation du graphe par les sommets adjacents
    void printGraph()
    {
        for (const auto &somadj : listadj)
        {
            std::cout << "sommet " << somadj.first << " : " << std::endl;
            for (const auto &arete : somadj.second)
            {
                std::cout << "  lié à l'arête " << arete.first << " avec le poids " << arete.second << std::endl;
            }
        }
    }

    // parcours en profondeur récursif à partir d'un sommet ou non
    //  sans préciser de sommet
    void dfs_rec()
    {
        std::cout << "parcours en profondeur récursif sans sommet de départ précisé" << std::endl;
        // on crée une unordered_map des sommets visités
        std::unordered_map<int, bool> somm_visit;
        // on ne donne pas de sommet de départ donc on fait tout
        for (const auto &somadj : listadj)
        {
            if (!somm_visit[somadj.first])
            {
                dfs_rec(somadj.first, somm_visit);
            }
        }
    }

    // en précisant le sommet de départ
    void dfs_rec(int sommet)
    {
        std::cout << "parcours en profondeur récursif avec sommet de départ précisé" << std::endl;
        std::unordered_map<int, bool> somm_visit;
        dfs_rec(sommet, somm_visit);
    }

    void dfs_rec(int sommet, std::unordered_map<int, bool> &somm_visit)
    {
        // doit effectuer le parcours en profondeur a partir de sommet, en ayant deja visite somm_visit
        // marque sommet comme visité
        somm_visit[sommet] = true;
        // pour chaque sommet adjacent : si arrete jamais vue la montrer (i.e. sommet et sj jamais vu)
        //                               si sommet non visité lancer la visite
        for (const auto &somadj : listadj[sommet])
        {
            int sj = somadj.first;
            int poids = somadj.second;
            std::cout << "arête entre " << sommet << " et " << sj << " de poids " << poids << std::endl;

            if (!somm_visit[sj])
            { // je n'affiche l'arête que si elle n'a pas déjà été affichée
                dfs_rec(sj, somm_visit);
                // toutes les arêtes ne s'affichent pas lors de l'execution, je ne comprends pas pourquoi
            }
        }
    }

    // Parcours en profondeur itératif
    void dfs_iter()
    {
        std::cout << "parcours en profondeur itératif sans sommet de départ précisé" << std::endl;
        // même départ que pour le parcours en profondeur récursif
        std::unordered_map<int, bool> somm_visit;
        for (const auto &somadj : listadj)
        {
            int sommet = somadj.first;
            if (!somm_visit[sommet])
            {
                dfs_iter(sommet, somm_visit);
            }
        }
    }

    // en précisant le sommet de départ
    void dfs_iter(int sommet)
    {
        std::cout << "parcours en profondeur itératif avec sommet de départ précisé" << std::endl;
        std::unordered_map<int, bool> somm_visit;
        dfs_iter(sommet, somm_visit);
    }

    void dfs_iter(int sommet, std::unordered_map<int, bool> &somm_visit)
    {
        std::stack<int> pile; // création d'une pile d'entiers
        pile.push(sommet);    // on ajoute le sommet que l'on étudie

        while (!pile.empty())
        { // tant qu'il reste des sommets à étudier la pile n'est pas vide
            int nv_sommet = pile.top();
            pile.pop();

            if (!somm_visit[nv_sommet])
            {
                somm_visit[nv_sommet] = true;
                for (const auto &somadj : listadj[nv_sommet])
                {
                    int sj = somadj.first;
                    int poids = somadj.second;
                    if (!somm_visit[sj])
                    {
                        std::cout << "arête entre " << nv_sommet << " et " << sj << " de poids " << poids << std::endl;
                        pile.push(sj);
                    }
                }
            }
        }
    }

    // Parcours en largeur
    void bfs()
    {
        // on reprend le meme principe que pour dfs en renvoyant les deux cas initiaux vers la fonction principale
        std::cout << "parcours en largeur sans préciser le sommet initial" << std::endl;
        std::unordered_map<int, bool> somm_visit;
        for (const auto &somadj : listadj)
        {
            int sommet = somadj.first;
            if (!somm_visit[sommet])
            {
                bfs(sommet, somm_visit);
            }
        }
    }

    //  avec un sommet de départ précisé
    void bfs(int sommet)
    {
        // de meme
        std::cout << "parcours en largeur en précisant le sommet initial" << std::endl;
        std::unordered_map<int, bool> somm_visit;
        bfs(sommet, somm_visit);
    }

    // Parcours en largeur à partir d'un sommet donné fonction principale
    void bfs(int sommet, std::unordered_map<int, bool> &somm_visit)
    {
        std::queue<int> file;
        file.push(sommet);
        somm_visit[sommet] = true; // on initialise la file

        // on stocke les arêtes visitees
        std::unordered_set<std::string> aretes_visitees;

        while (!file.empty())
        { // le parcours se finit quand tout a ete visite ie quand la file est vide
            int nv_sommet = file.front();
            file.pop();

            // on regarde les voisins
            for (const auto &arete : listadj[nv_sommet])
            {
                int sj = arete.first;
                int poids = arete.second;

                std::string arrete1 = std::to_string(nv_sommet) + "-" + std::to_string(sj);
                std::string arrete2 = std::to_string(sj) + "-" + std::to_string(nv_sommet);

                // Si l'arête n'a pas encore été visitée
                if (aretes_visitees.find(arrete1) == aretes_visitees.end() and aretes_visitees.find(arrete2) == aretes_visitees.end())
                {
                    std::cout << "  Arête entre " << nv_sommet << " et " << sj << " de poids " << poids << std::endl;
                    aretes_visitees.insert(arrete1);
                    aretes_visitees.insert(arrete2);
                }

                // Si le sommet adjacent n'a pas été visité, l'ajouter à la file
                if (!somm_visit[sj])
                {
                    file.push(sj);
                    somm_visit[sj] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 100);
    g.addEdge(1, 3, 150);
    g.addEdge(2, 0, 80);
    g.addEdge(3, 0, 70);
    g.addEdge(0, 1, 200);
    g.printGraph();
    g.dfs_rec(); //  PROBLEME tout les arêtes ne sont pas affichées
    g.dfs_iter();

    g.dfs_rec(1); // PROBLEME tout les arêtes ne sont pas affichées
    g.dfs_iter(1);
    g.bfs();

    g.bfs(1);

    return 0;
}