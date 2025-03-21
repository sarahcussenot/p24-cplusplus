#ifndef STACK_TMPL_H
#define STACK_TMPL_H

#include <iostream>
#include <stdexcept>

template <typename T, int SIZE>
class Stack {
public:
    Stack() : pos(0) {
        ti = new T[SIZE];
    }

    Stack(const Stack& r) : pos(r.pos) {
        ti = new T[SIZE];
        for (int i = 0; i < pos; i++) {
            ti[i] = r.ti[i];
        }
    }

    Stack& operator=(const Stack& r) {
        if (this != &r) {
            delete[] ti;
            pos = r.pos;
            ti = new T[SIZE];
            for (int i = 0; i < pos; i++) {
                ti[i] = r.ti[i];
            }
        }
        return *this;
    }

    ~Stack() {
        delete[] ti;
    }

    void push(T e) {
        if (!is_full()) {
            ti[pos++] = e;
        } else {
            throw std::overflow_error("Stack is full");
        }
    }

    T get_top() const {
        if (!is_empty()) {
            return ti[pos - 1];
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    T pop() {
        if (!is_empty()) {
            return ti[--pos];
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool is_empty() const {
        return pos == 0;
    }

    bool is_full() const {
        return pos == SIZE;
    }

    void print() const {
        std::cout << '[';
        for (int i = 0; i < pos; i++) {
            std::cout << ti[i] << ' ';
        }
        std::cout << '[' << std::endl;
    }

private:
    T* ti;
    int pos;
};

template <typename T, int SIZE>
std::ostream& operator<<(std::ostream& os, const Stack<T, SIZE>& stack) {
    stack.print();
    return os;
}

#endif // STACK_TMPL_H
