
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    float length;
    float width;

public:
    Rectangle(); // Default constructor
    Rectangle(float l, float w); // Overloaded constructor
    ~Rectangle(); // Destructor

    void setLength(float l);
    void setWidth(float w);
    float getLength() const;
    float getWidth() const;
    float calculateArea() const;
};

#endif
#include "Rectangle.h"

Rectangle::Rectangle() : length(0.0), width(0.0) {}

Rectangle::Rectangle(float l, float w) : length(l), width(w) {}

Rectangle::~Rectangle() {}

void Rectangle::setLength(float l) {
    length = l;
}

void Rectangle::setWidth(float w) {
    width = w;
}

float Rectangle::getLength() const {
    return length;
}

float Rectangle::getWidth() const {
    return width;
}

float Rectangle::calculateArea() const {
    return length * width;
}
#include <iostream>
#include "Rectangle.h"

int main() {
    // Create an instance of Rectangle using the default constructor
    Rectangle rect1;

    // Set length and width using accessor methods
    float length, width;
    std::cout << "Enter length for the first rectangle: ";
    std::cin >> length;
    std::cout << "Enter width for the first rectangle: ";
    std::cin >> width;
    rect1.setLength(length);
    rect1.setWidth(width);

    // Output the area of the first rectangle
    std::cout << "Area of the first rectangle: " << rect1.calculateArea() << std::endl;

    // Create an instance of Rectangle using the overloaded constructor
    std::cout << "Enter length for the second rectangle: ";
    std::cin >> length;
    std::cout << "Enter width for the second rectangle: ";
    std::cin >> width;
    Rectangle rect2(length, width);

    // Output the area of the second rectangle
    std::cout << "Area of the second rectangle: " << rect2.calculateArea() << std::endl;

    return 0;
}
#ifndef SQUARE_H
#define SQUARE_H

namespace shapes {
    class Square {
    private:
        float side;

    public:
        Square();
        Square(float s);
        ~Square();

        void setSide(float s);
        float getSide() const;
    };
}

#endif
#ifndef TRIANGLE_H
#define TRIANGLE_H

namespace shapes {
    class Triangle {
    private:
        float base;
        float height;

    public:
        Triangle();
        Triangle(float b, float h);
        ~Triangle();

        void setBase(float b);
        void setHeight(float h);
        float getBase() const;
        float getHeight() const;
    };
}

#endif
#ifndef CIRCLE_H
#define CIRCLE_H

namespace shapes {
    class Circle {
    private:
        float radius;

    public:
        Circle();
        Circle(float r);
        ~Circle();

        void setRadius(float r);
        float getRadius() const;
    };
}

#endif
#ifndef AREA_H
#define AREA_H

#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

namespace shapes {
    class Area {
    public:
        static float calculateArea(const Square& square);
        static float calculateArea(const Triangle& triangle);
        static float calculateArea(const Circle& circle);
    };
}

#endif
#include "Square.h"

namespace shapes {
    Square::Square() : side(0.0) {}
    Square::Square(float s) : side(s) {}
    Square::~Square() {}

    void Square::setSide(float s) {
        side = s;
    }

    float Square::getSide() const {
        return side;
    }
}
#include "Triangle.h"

namespace shapes {
    Triangle::Triangle() : base(0.0), height(0.0) {}
    Triangle::Triangle(float b, float h) : base(b), height(h) {}
    Triangle::~Triangle() {}

    void Triangle::setBase(float b) {
        base = b;
    }

    void Triangle::setHeight(float h) {
        height = h;
    }

    float Triangle::getBase() const {
        return base;
    }

    float Triangle::getHeight() const {
        return height;
    }
}
#include "Circle.h"

namespace shapes {
    Circle::Circle() : radius(0.0) {}
    Circle::Circle(float r) : radius(r) {}
    Circle::~Circle() {}

    void Circle::setRadius(float r) {
        radius = r;
    }

    float Circle::getRadius() const {
        return radius;
    }
}
#include "Area.h"

namespace shapes {
    float Area::calculateArea(const Square& square) {
        return square.getSide() * square.getSide();
    }

    float Area::calculateArea(const Triangle& triangle) {
        return 0.5 * triangle.getBase() * triangle.getHeight();
    }

    float Area::calculateArea(const Circle& circle) {
        return 3.14159 * circle.getRadius() * circle.getRadius();
    }
}

#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Area.h"

int main() {
    char choice;
    do {
        std::cout << "Choose an option:\n";
        std::cout << "1. Calculate the area of a square\n";
        std::cout << "2. Calculate the area of a triangle\n";
        std::cout << "3. Calculate the area of a circle\n";
        std::cout << "4. Quit\n";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                float side;
                std::cout << "Enter the side length of the square: ";
                std::cin >> side;
                shapes::Square square(side);
                std::cout << "Area of the square: " << shapes::Area::calculateArea(square) << std::endl;
                break;
            }
            case '2': {
                float base, height;
                std::cout << "Enter the base of the triangle: ";
                std::cin >> base;
                std::cout << "Enter the height of the triangle: ";
                std::cin >> height;
                shapes::Triangle triangle(base, height);
                std::cout << "Area of the triangle: " << shapes::Area::calculateArea(triangle) << std::endl;
                break;
            }
            case '3': {
                float radius;
                std::cout << "Enter the radius of the circle: ";
                std::cin >> radius;
                shapes::Circle circle(radius);
                std::cout << "Area of the circle: " << shapes::Area::calculateArea(circle) << std::endl;
                break;
            }
            case '4':
                std::cout << "Quitting program." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != '4');

    return 0;
}
