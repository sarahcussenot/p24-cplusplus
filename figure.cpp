#include <iostream>

class Figure
{
private:
    int x;
    int y;
    int color;
};

class circle : public Figure
{
    private :
    int radius;
};

class square
{
    private:
    int side;
};

class rectangle
{
    private :
    int width;
    int height;
};