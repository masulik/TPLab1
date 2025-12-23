#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Абстрактный базовый класс — общий интерфейс для всех животных
class Base {
public:
    virtual void input() = 0;                       // Виртуальный метод: ввод данных (реализуется в наследниках)
    virtual void show() const = 0;                  // Виртуальный метод: вывод информации на экран
    virtual void save(ofstream& fout) const = 0;    // Виртуальный метод: сохранение объекта в файл
    virtual void load(ifstream& fin) = 0;           // Виртуальный метод: загрузка объекта из файла

    virtual ~Base() {
        cout << "[Destructor] Base class destroyed" << endl; // Сообщаем, когда уничтожается объект базового класса
    }
};
