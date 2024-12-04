#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class Figure {
public:
    virtual ~Figure() {}

    virtual std::pair<double, double> center() const = 0;
    virtual double area() const = 0;

    virtual Figure* clone() const = 0;

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);

    virtual operator double() const {
        return area();
    }

    virtual bool operator==(const Figure& other) const {
        return area() == other.area();
    }

protected:
    virtual void read(std::istream& is) = 0;
    virtual void print(std::ostream& os) const = 0;
};

// Класс Hexagon (шестиугольник)
class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(double side);
    Hexagon(const Hexagon& other);
    Hexagon& operator=(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(Hexagon&& other) noexcept;
    bool operator==(const Figure& other) const override;
    Hexagon* clone() const override;
    std::pair<double, double> center() const override;
    double area() const override;

protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;

private:
    double side_length;
};

// Класс Octagon (восьмиугольник)
class Octagon : public Figure {
public:
    Octagon();
    Octagon(double side);
    Octagon(const Octagon& other);
    Octagon& operator=(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    Octagon& operator=(Octagon&& other) noexcept;
    bool operator==(const Figure& other) const override;
    Octagon* clone() const override;
    std::pair<double, double> center() const override;
    double area() const override;

protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;

private:
    double side_length;
};

// Класс Triangle (треугольник)
class Triangle : public Figure {
public:
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Figure& other) const override;
    Triangle* clone() const override;
    std::pair<double, double> center() const override;
    double area() const override;

protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;

private:
    double a, b, c;
};

// Функция для вычисления общей площади всех фигур в массиве
double total_area(const std::vector<Figure*>& figures);

// Функция для удаления фигуры по индексу
void remove_figure(std::vector<Figure*>& figures, size_t index);

#endif  