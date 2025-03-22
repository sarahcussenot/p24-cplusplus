#ifndef INT_STACK_H
#define INT_STACK_H

#include <iostream>
#include <stdexcept>

const int SIZE{12};

class IntStack {
public:
    IntStack(int s = SIZE);
    IntStack(const IntStack& r);
    IntStack& operator=(const IntStack& r);
    ~IntStack();

    void push(int e);
    int get_top() const;
    int pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;

    friend std::ostream& operator<<(std::ostream& os, const IntStack& stack);

private:
    int SIZE;
    int* ti;
    int pos;
};

#endif // INT_STACK_H
int_stack.cpp

#include "int_stack.h"

IntStack::IntStack(int s) : pos(0), SIZE(s) {
    ti = new int[SIZE];
}

IntStack::IntStack(const IntStack& r) : pos(r.pos), SIZE(r.SIZE) {
    ti = new int[SIZE];
    for (int i = 0; i < pos; i++) {
        ti[i] = r.ti[i];
    }
}

IntStack& IntStack::operator=(const IntStack& r) {
    if (this != &r) {
        delete[] ti;
        SIZE = r.SIZE;
        pos = r.pos;
        ti = new int[SIZE];
        for (int i = 0; i < pos; i++) {
            ti[i] = r.ti[i];
        }
    }
    return *this;
}

IntStack::~IntStack() {
    delete[] ti;
}

void IntStack::push(int e) {
    if (!is_full()) {
        ti[pos++] = e;
    } else {
        throw std::overflow_error("Stack is full");
    }
}

int IntStack::get_top() const {
    if (!is_empty()) {
        return ti[pos - 1];
    } else {
        throw std::underflow_error("Stack is empty");
    }
}

int IntStack::pop() {
    if (!is_empty()) {
        return ti[--pos];
    } else {
        throw std::underflow_error("Stack is empty");
    }
}

bool IntStack::is_empty() const {
    return pos == 0;
}

bool IntStack::is_full() const {
    return pos == SIZE;
}

void IntStack::print() const {
    std::cout << '[';
    for (int i = 0; i < pos; i++) {
        std::cout << ti[i] << ' ';
    }
    std::cout << '[' << std::endl;
}

std::ostream& operator<<(std::ostream& os, const IntStack& stack) {
    stack.print();
    return os;
}
