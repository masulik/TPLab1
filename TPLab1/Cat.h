#pragma once
#include "Base.h"

// Класс Cat (Кошка), наследник Base
class Cat : public Base {
private:
    string species;   // Порода
    string color;     // Окрас
    string owner;     // Владелец
    string name;      // Кличка
public:
    Cat();                                    // Конструктор по умолчанию
    Cat(string s, string c, string o, string n); // Конструктор с параметрами
    Cat(const Cat& other);                     // Копирующий конструктор
    ~Cat();                                   // Деструктор

    void input() override;                     // Ввод данных
    void show() const override;                // Вывод данных
    void save(ofstream& fout) const override;  // Сохранение в файл
    void load(ifstream& fin) override;         // Загрузка из файла
};
