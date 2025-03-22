#include <iostream>
#include <vector>

class Figure
{
private: // accessible que depuis la classe et pas depuis les classes dérivées
protected:
    // peuvent être accédés depuis les classes dérivées
    int x;
    int y;
    int color;

public:
    Figure(int x, int y, int color) : x(x), y(y), color(color) {}

    virtual void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
        // on fait le virtual pour prévoir l'influnce des sosu classes
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
public : 
    Circle(int x, int y, int color, double radius) : Figure(x, y, color), radius(radius) {}
    double area() const override
    {
        return pi * radius * radius;
    }
    bool is_at_position(int px, int py) const override
    {
        return ((x - px) * (x - px) + (y - py) * (y - py)) <= radius*radius;
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

// il faut que la figure puisse être déplacée
// il faut pouvoir calculer l'aire de la figure
// implement an editor that can display and move shapes
// the editor has a method to find the shape at a given position
// if the shape exists you can call the move or the compute area method

// optionnel:
// faire une fonction prend en argument x, y et un vecteur de formes et retourne la forme au point (x, y)

Figure *find_at_position(int x, int y, const std::vector<Figure*> &shapes)
{
    // dans cette fonction vous avez besoin de tester si une forme est au point (x, y)
    // pour faire cela sans mettre cette fonction friend, ajouter en plus de move et area
    // une méthode bool is_at_position(int x, int y)
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
    Circle c{10, 20, 4.5};       // x, y, radius
    Rectangle r{20, 30, 30, 60}; // x, y, width, height
    std::vector</Figure*/> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    // première version (sans find_at_position et is_at_position)
    shapes[0]->move(4, 6);
    shapes[1]->move(2, 8);
    std::cout << shapes[0]->area() << std::endl; // affiche dans les 63.6173
    std::cout << shapes[1]->area() << std::endl; // 1800

    // deuxième version (avec find_at_position et is_at_position)
    Figure* shape1 = find_at_position(10, 20, shapes);
        if (shape1) {
        shape1->move(5, 5);
        std::cout << shape1->area() << std::endl;
    }
    // appeler la méthode move et area sur shape1
    Figure* shape2 = find_at_position(100, 200, shapes);
        if (shape2) {
        shape2->move(5, 5);
        std::cout << shape2->area() << std::endl;
    } else {
        std::cout << "No shape found at position (100, 200)" << std::endl;
    }
    // pouvez vous appeler la méthode move et area sur shape2 ?
    return 0;
}