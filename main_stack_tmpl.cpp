#include "stack_tmpl.h"

int main() {
    Stack<int, 12> s1;
    std::cout << s1; // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << s1; // affichera [1 2 3 [
    std::cout << s1.pop() << std::endl; // affichera 3
    std::cout << s1; // affichera [1 2 [
    return 0;
}
