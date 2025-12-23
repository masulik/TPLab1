#pragma once
#include "Base.h"

// Класс Bird (Птица), наследник Base
class Bird : public Base {
private:
    string species;   // Порода
    string color;     // Окрас
    string food;      // Чем питается
    string habitat;   // Где обитает
public:
    Bird();                                      // Конструктор по умолчанию
    Bird(string s, string c, string f, string h); // Конструктор с параметрами
    Bird(const Bird& other);                      // Копирующий конструктор
    ~Bird();                                     // Деструктор

    void input() override;                        // Ввод данных
    void show() const override;                   // Вывод данных
    void save(ofstream& fout) const override;     // Сохранение в файл
    void load(ifstream& fin) override;            // Загрузка из файла
};
