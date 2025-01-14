#include <iostream>
#include <vector>
#include <cmath> // pour std::sqrt

class Figure
{
protected:
    int x;
    int y;
    int color;

public:
    Figure(int x, int y, int color) : x(x), y(y), color(color) {}

    virtual void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }

    virtual bool is_at_position(int px, int py) const = 0;
    virtual ~Figure() = default;
    virtual double area() const = 0;
};

class Circle : public Figure
{
private:
    double radius;
    const double pi = 3.14;

public:
    Circle(int x, int y, int color, double radius) : Figure(x, y, color), radius(radius) {}

    double area() const override
    {
        return pi * radius * radius;
    }

    bool is_at_position(int px, int py) const override
    {
        return std::sqrt((x - px) * (x - px) + (y - py) * (y - py)) <= radius;
    }
};

class Square : public Figure
{
private:
    int side;

public:
    Square(int x, int y, int color, int side) : Figure(x, y, color), side(side) {}

    double area() const override
    {
        return side * side;
    }

    bool is_at_position(int px, int py) const override
    {
        return px >= x and px <= x + side and py >= y and py <= y + side;
    }
};

class Rectangle : public Figure
{
private:
    int width;
    int height;

public:
    Rectangle(int x, int y, int color, int width, int height) : Figure(x, y, color), width(width), height(height) {}

    double area() const override
    {
        return width * height;
    }

    bool is_at_position(int px, int py) const override
    {
        return px >= x and px <= x + width and py >= y and py <= y + height;
    }
};

Figure* find_at_position(int x, int y, const std::vector<Figure*>& shapes)
{
    for (auto shape : shapes)
    {
        if (shape->is_at_position(x, y))
        {
            return shape;
        }
    }
    return nullptr;
}

int main()
{
    Circle c(10, 20, 4, 5.0);       // x, y, color, radius
    Rectangle r(20, 30, 1, 30, 60);  // x, y, color, width, height (ici, 1 est une valeur pour color)
    std::vector<Figure*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    // première version
    shapes[0]->move(4, 6);
    shapes[1]->move(2, 8);
    std::cout << shapes[0]->area() << std::endl; // affiche dans les 63.6173
    std::cout << shapes[1]->area() << std::endl; // 1800

    // deuxième version avec find_at_position et is_at_position
    Figure* shape1 = find_at_position(10, 20, shapes);
    if (shape1) {
        shape1->move(5, 5);
        std::cout << shape1->area() << std::endl;
    }

    Figure* shape2 = find_at_position(100, 200, shapes);
    if (shape2) {
        shape2->move(5, 5);
        std::cout << shape2->area() << std::endl;
    } else {
        std::cout << "No shape found at position (100, 200)" << std::endl;
    }

    return 0;
}