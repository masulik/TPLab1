#pragma once
#include "Base.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

// Класс Keeper — контейнер для хранения указателей на объекты Base
class Keeper {
private:
    Base** items;  // Динамический массив указателей на Base
    int size;      // Количество элементов в контейнере
public:
    Keeper();                               // Конструктор по умолчанию
    Keeper(const Keeper& other);            // Копирующий конструктор
    ~Keeper();                              // Деструктор

    void add(Base* obj);                    // Добавление нового объекта
    void remove(int index);                 // Удаление объекта по индексу
    void edit(int index);                   // Изменение данных объекта
    void showAll() const;                   // Вывод всех объектов

    void saveToFile(const string& filename) const; // Сохранение всех объектов в файл
    void loadFromFile(const string& filename);     // Загрузка всех объектов из файла

    // Перегрузки операторов
    Keeper& operator+=(Base* obj);          // Перегрузка += (добавление элемента)
    Base* operator[](int index);            // Перегрузка [] (доступ по индексу)
    Keeper& operator=(const Keeper& other); // Перегрузка = (копирование контейнера)
};
