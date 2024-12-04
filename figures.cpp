#include "figures.h"

// Реализация методов класса Figure
std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}

// Реализация класса Hexagon
Hexagon::Hexagon() : side_length(0) {}
Hexagon::Hexagon(double side) : side_length(side) {}
Hexagon::Hexagon(const Hexagon& other) : side_length(other.side_length) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this == &other) return *this;
    side_length = other.side_length;
    return *this;
}

Hexagon::Hexagon(Hexagon&& other) noexcept : side_length(other.side_length) {
    other.side_length = 0;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this == &other) return *this;
    side_length = other.side_length;
    other.side_length = 0;
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* other_hex = dynamic_cast<const Hexagon*>(&other);
    return other_hex && side_length == other_hex->side_length;
}

Hexagon* Hexagon::clone() const {
    return new Hexagon(*this);
}

std::pair<double, double> Hexagon::center() const {
    return {0, 0};
}

double Hexagon::area() const {
    return (3 * sqrt(3) * side_length * side_length) / 2;
}

void Hexagon::read(std::istream& is) {
    std::cout << "Введите длину стороны шестиугольника: ";
    is >> side_length;
}

void Hexagon::print(std::ostream& os) const {
    os << "Шестиугольник с длиной стороны " << side_length << "\n";
}

// Реализация класса Octagon
Octagon::Octagon() : side_length(0) {}
Octagon::Octagon(double side) : side_length(side) {}
Octagon::Octagon(const Octagon& other) : side_length(other.side_length) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this == &other) return *this;
    side_length = other.side_length;
    return *this;
}

Octagon::Octagon(Octagon&& other) noexcept : side_length(other.side_length) {
    other.side_length = 0;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this == &other) return *this;
    side_length = other.side_length;
    other.side_length = 0;
    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* other_oct = dynamic_cast<const Octagon*>(&other);
    return other_oct && side_length == other_oct->side_length;
}

Octagon* Octagon::clone() const {
    return new Octagon(*this);
}

std::pair<double, double> Octagon::center() const {
    return {0, 0};
}

double Octagon::area() const {
    return 2 * (1 + sqrt(2)) * side_length * side_length;
}

void Octagon::read(std::istream& is) {
    std::cout << "Введите длину стороны восьмиугольника: ";
    is >> side_length;
}

void Octagon::print(std::ostream& os) const {
    os << "Восьмиугольник с длиной стороны " << side_length << "\n";
}

// Реализация класса Triangle
Triangle::Triangle() : a(0), b(0), c(0) {}
Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
Triangle::Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this == &other) return *this;
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}

Triangle::Triangle(Triangle&& other) noexcept : a(other.a), b(other.b), c(other.c) {
    other.a = other.b = other.c = 0;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this == &other) return *this;
    a = other.a;
    b = other.b;
    c = other.c;
    other.a = other.b = other.c = 0;
    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* other_tri = dynamic_cast<const Triangle*>(&other);
    return other_tri && a == other_tri->a && b == other_tri->b && c == other_tri->c;
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}

std::pair<double, double> Triangle::center() const {
    return {0, 0};
}

double Triangle::area() const {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::read(std::istream& is) {
    std::cout << "Введите длины сторон треугольника: ";
    is >> a >> b >> c;
}

void Triangle::print(std::ostream& os) const {
    os << "Треугольник со сторонами " << a << ", " << b << ", " << c << "\n";
}

// Реализация функции для вычисления общей площади всех фигур
double total_area(const std::vector<Figure*>& figures) {
    double total = 0;
    for (const auto& fig : figures) {
        total += static_cast<double>(*fig);
    }
    return total;
}

// Реализация функции для удаления фигуры по индексу
void remove_figure(std::vector<Figure*>& figures, size_t index) {
    if (index < figures.size()) {
        delete figures[index]; 
        figures.erase(figures.begin() + index); 
        std::cout << "Фигура удалена.\n";
    } else {
        std::cout << "Неверный индекс!\n";
    }
}