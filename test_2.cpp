# include <iostream>
# include <limits>

int main () {
    std::cout<<std::numeric_limits<int>::max()
            <<std::endl;
    // va dans librairie standard, la partie numeric limit, demande le max, on a donc le plus grand entier dans int
    unsigned max = std::numeric_limits<int>::max();

    std::cout <<max + 1
            <<std::endl;
    // c++ evalue l expression max ()+1 de type int car somme de int, ensuite il fait la somme donc overflow
    return 0;
}
