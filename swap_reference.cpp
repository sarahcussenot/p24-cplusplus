#include <iostream>

int add(int a, int b) {
    int t = a + b;
    return t;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a {5};
    int b {10};
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
