#include <gtest/gtest.h>
#include "figures.h"


// Тест 1: Проверка площади шестиугольника
TEST(FigureTest, HexagonArea) {
    Hexagon hex(2); 
    double expected_area = (3 * sqrt(3) * 2 * 2) / 2;
    EXPECT_DOUBLE_EQ(hex.area(), expected_area);
}

// Тест 2: Проверка площади восьмиугольника
TEST(FigureTest, OctagonArea) {
    Octagon oct(3); 
    double expected_area = 2 * (1 + sqrt(2)) * 3 * 3;
    EXPECT_DOUBLE_EQ(oct.area(), expected_area);
}

// Тест 3: Проверка площади треугольника
TEST(FigureTest, TriangleArea) {
    Triangle tri(3, 4, 5);  
    double expected_area = 6;  
    EXPECT_DOUBLE_EQ(tri.area(), expected_area);
}


// Тест 4: Проверка центра шестиугольника
TEST(FigureTest, HexagonCenter) {
    Hexagon hex(2);
    auto center = hex.center();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0);
}

// Тест 5: Проверка центра восьмиугольника
TEST(FigureTest, OctagonCenter) {
    Octagon oct(3);
    auto center = oct.center();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0);
}

// Тест 6: Проверка центра треугольника
TEST(FigureTest, TriangleCenter) {
    Triangle tri(3, 4, 5);
    auto center = tri.center();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0);
}

// Тест 7: Копирование шестиугольника
TEST(FigureTest, HexagonCopy) {
    Hexagon hex1(5);
    Hexagon hex2 = hex1;  
    EXPECT_DOUBLE_EQ(hex1.area(), hex2.area());  
}

// Тест 8: Копирование восьмиугольника
TEST(FigureTest, OctagonCopy) {
    Octagon oct1(4);
    Octagon oct2 = oct1; 
    EXPECT_DOUBLE_EQ(oct1.area(), oct2.area()); 
}

// Тест 9: Перемещение шестиугольника
TEST(FigureTest, HexagonMove) {
    Hexagon hex1(6);
    Hexagon hex2 = std::move(hex1);  
    EXPECT_DOUBLE_EQ(hex2.area(), (3 * sqrt(3) * 6 * 6) / 2);
}

// Тест 10: Перемещение восьмиугольника
TEST(FigureTest, OctagonMove) {
    Octagon oct1(5);
    Octagon oct2 = std::move(oct1); 
    EXPECT_DOUBLE_EQ(oct2.area(), 2 * (1 + sqrt(2)) * 5 * 5);
}


// Тест 11: Сравнение одинаковых шестиугольников
TEST(FigureTest, HexagonComparisonEqual) {
    Hexagon hex1(3);
    Hexagon hex2(3);
    EXPECT_TRUE(hex1 == hex2);  
}

// Тест 12: Сравнение разных треугольников
TEST(FigureTest, TriangleComparisonNotEqual) {
    Triangle tri1(3, 4, 5);
    Triangle tri2(5, 12, 13);
    EXPECT_FALSE(tri1 == tri2);  
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}