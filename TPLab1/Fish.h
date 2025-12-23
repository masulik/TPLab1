#pragma once
#include "Base.h"

//Класс Fish (Рыба), наследник Base
class Fish : public Base {
private:
    string species;   // Порода
    string color;     // Окрас
    string foodType;  // Тип питания
public:
    Fish();                                   // Конструктор по умолчанию
    Fish(string s, string c, string f);       // Конструктор с параметрами
    Fish(const Fish& other);                  // Копирующий конструктор
    ~Fish();                                  // Деструктор

    void input() override;                    // Ввод данных
    void show() const override;               // Вывод данных
    void save(ofstream& fout) const override; // Сохранение в файл
    void load(ifstream& fin) override;        // Загрузка из файла

    string getSpecies() const;                // Геттер породы
    void setSpecies(string s);                // Сеттер породы
};
