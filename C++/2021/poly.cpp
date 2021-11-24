#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

enum ShapeType
{
    ECircle,
    ERectangle,
    ESquare
};

class Shape
{
public:
    auto virtual area() const -> double = 0;
    auto virtual type() const -> enum ShapeType = 0;
    auto virtual about() const -> void = 0;
};

class Circle : public Shape
{
protected:
    double radius;

public:
    Circle(double radius) : radius{radius} {}

    ~Circle()
    {
        std::cout << "Circle Destructor" << std::endl;
    }

    auto area() const -> double override
    {
        return std::pow(this->radius, 2.0) * 3.1415926535;
    }

    auto type() const -> enum ShapeType override { return ShapeType::ECircle;
    }

    auto about() const -> void override
    {
        std::cout << "Circle { area: " << this->area() << " }" << std::endl;
    }
};

class Rectangle : public Shape
{
protected:
    double side1;
    double side2;

public:
    Rectangle(double side1, double side2) : side1{side1}, side2{side2} {}

    ~Rectangle()
    {
        std::cout << "Rectangle Destructor" << std::endl;
    }

    auto area() const -> double override
    {
        return this->side1 * this->side2;
    }

    auto type() const -> enum ShapeType override { return ShapeType::ERectangle;
    }

    auto about() const -> void override
    {
        std::cout << "Rectangle { area: " << this->area() << " }" << std::endl;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}

    ~Square()
    {
        std::cout << "Square Destructor" << std::endl;
    }

    auto type() const -> enum ShapeType override { return ShapeType::ESquare;
    }

    auto about() const -> void override
    {
        std::cout << "Square { area: " << this->area() << " }" << std::endl;
    }
};

auto main() -> int
{
    std::vector<std::unique_ptr<Shape>> vec;

    vec.push_back(std::make_unique<Rectangle>(10.0, 12.0));
    vec.push_back(std::make_unique<Rectangle>(12.0, 12.0));
    vec.push_back(std::make_unique<Square>(15.0));
    vec.push_back(std::make_unique<Circle>(8.0));

    for (auto& shape : vec)
    {
        shape->about();
    }
}
