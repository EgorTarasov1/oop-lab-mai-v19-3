#include <iostream>
#include <vector>
#include "figures.h"

int main() {
    std::vector<Figure*> figures;  
    char choice;

    do {
        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить шестиугольник\n";
        std::cout << "2 - Добавить восьмиугольник\n";
        std::cout << "3 - Добавить треугольник\n";
        std::cout << "4 - Удалить фигуру по индексу\n";
        std::cout << "5 - Показать все фигуры\n";
        std::cout << "6 - Вычислить общую площадь фигур\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                Hexagon* hex = new Hexagon(); 
                std::cin >> *hex;
                figures.push_back(hex); 
                break;
            }
            case '2': {
                Octagon* oct = new Octagon(); 
                std::cin >> *oct;
                figures.push_back(oct); 
                break;
            }
            case '3': {
                Triangle* tri = new Triangle(); 
                std::cin >> *tri;
                figures.push_back(tri); 
                break;
            }
            case '4': {
                size_t index;
                std::cout << "Введите индекс фигуры для удаления: ";
                std::cin >> index;
                remove_figure(figures, index); 
                break;
            }
            case '5': {
                if (figures.empty()) {
                    std::cout << "Фигуры отсутствуют.\n";
                } else {
                    std::cout << "\nСписок фигур:\n";
                    for (size_t i = 0; i < figures.size(); ++i) {
                        std::cout << "Фигура " << i << ":\n";
                        std::cout << *figures[i];
                        std::cout << "Центр фигуры: (" << figures[i]->center().first << ", " << figures[i]->center().second << ")\n";
                        std::cout << "Площадь фигуры: " << static_cast<double>(*figures[i]) << "\n\n";
                    }
                }
                break;
            }
            case '6': {
                double total = total_area(figures); 
                std::cout << "Общая площадь всех фигур: " << total << "\n";
                break;
            }
            default:
                std::cout << "Неверный выбор!\n";
                break;
        }

        std::cout << "Хотите продолжить? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    for (Figure* fig : figures) {
        delete fig;  
    }

    return 0;
}