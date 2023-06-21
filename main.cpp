#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>



enum class Shape
{
    CIRCLE,
    TRIANGLE,
    RECTANGLE
};

enum class Color
{
    BLACK,
    WHITE
};

struct Coords
{
    int m_x;
    int m_y;
};

struct Figure
{
private:
    Color m_color;
protected:
    Shape m_shape;

public:
    Figure(Color color)
    {
        m_color = color;
    }
    virtual void Print()
    {

    }
};

struct Circle : Figure
{
private:
    Coords m_center;
    float m_radius;
public:
    Circle(Coords center, float radius, Color color) : Figure(color), m_radius(radius), m_center(center)
    {
        m_shape = Shape::CIRCLE;
    }
    float Square()
    {
        return M_PI * m_radius * m_radius;
    }
};

struct Triangle : Figure
{
private:
    Coords A;
    Coords B;
    Coords C;
public:
    Triangle(Coords a, Coords b, Coords c, Color color) : Figure(color), A(a), B(b), C(c)
    {
        m_shape = Shape::TRIANGLE;
    }

    float SideLength(Coords a, Coords b)
    {
        float vx = a.m_x - b.m_x;
        float vy = a.m_y - b.m_y;
        return sqrt(vx*vx + vy*vy);
    }

    float Square()
    {
        float p = (SideLength(A, B) + SideLength(B, C) + SideLength(A, C)) / 2;
        return sqrt(p * (p- SideLength(A, B)) * (p- SideLength(B, C)) * (p- SideLength(A, C)));
    }
};

struct Rectangle : Figure
{
private:
    Coords A;
    Coords B;
    Coords C;
    Coords D;
public:
    Rectangle(Coords a, Coords b, Coords c, Coords d, Color color) : Figure(color), A(a), B(b), C(c), D(d)
    {
        m_shape = Shape::RECTANGLE;
    }
    float SideLength(Coords a, Coords b)
    {
        float vx = a.m_x - b.m_x;
        float vy = a.m_y - b.m_y;
        return sqrt(vx*vx + vy*vy);
    }
    float Square()
    {
        return SideLength(A, B) * SideLength(A, C);
    }
};

int main()
{
    return 0;
}