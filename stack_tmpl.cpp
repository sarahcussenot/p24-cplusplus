#include "stack_tmpl.h"

void IntStack::push(int e) {
    pile[remplissage] = e;
    remplissage++;
}

int IntStack::get_top() const {
    if (remplissage > 0) {
        return pile[remplissage - 1];
    }
    throw std::underflow_error("Stack is empty");
}

int IntStack::pop() {
    if (remplissage > 0) {
        remplissage--;
        return pile[remplissage];
    }
    throw std::underflow_error("Stack is empty");
}

bool IntStack::is_empty() const {
    return remplissage == 0;
}

bool IntStack::is_full() const {
    return remplissage == SIZE;
}

void IntStack::print() const {
    std::cout << '[';
    for (int i = 0; i < remplissage; i++) {
        std::cout << pile[i] << ' ';
    }
    std::cout << '[' << std::endl;
}

std::ostream& operator<<(std::ostream& os, const IntStack& stack) {
    stack.print();
    return os;
}
