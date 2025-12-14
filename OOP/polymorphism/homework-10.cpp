#include <iostream>
using namespace std;

/*
    Inheritance and Polymorphism with Static members
*/

class Shape {
public:
    // Static method to compare the areas of two shapes
    static void CompareAreas(double circleArea, double rectangleArea) {
        if (circleArea == rectangleArea)
            cout << "The areas are equal." << endl;
        else
            cout << "The areas are not equal." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    // Static method to calculate the area of a circle
    static double CalculateArea(double radius) {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    // Static method to calculate the area of a rectangle
    static double CalculateArea(double width, double height) {
        return width * height;
    }
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    // Calculate areas using static methods
    double circleArea = Circle::CalculateArea(circleRadius);
    double rectangleArea = Rectangle::CalculateArea(rectWidth, rectHeight);

    // Display the areas
    cout << "Circle Area: " << circleArea << endl;
    cout << "Rectangle Area: " << rectangleArea << endl;

    // Compare areas using Shape's static method
    Shape::CompareAreas(circleArea, rectangleArea);

    return 0;
}
