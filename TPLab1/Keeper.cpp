#include "Keeper.h"
#include <stdexcept> // для исключений
#include <iomanip> 

Keeper::Keeper() : items(nullptr), size(0) {
    cout << "[Constructor] Default Keeper created" << endl; // Контейнер создан, пока пуст
}

Keeper::Keeper(const Keeper& other) {
    cout << "[Constructor] Keeper copy created" << endl;
    size = other.size;                                     // Копируем размер
    items = new Base * [size];                               // Выделяем новую память
    for (int i = 0; i < size; i++) {
        items[i] = other.items[i];                         // Поверхностное копирование (указатели)
    }
}

Keeper::~Keeper() {
    cout << "[Destructor] Keeper destroyed" << endl;
    // Удаляем все объекты и массив
    for (int i = 0; i < size; i++) delete items[i];
    delete[] items;
}

// Добавить объект в контейнер
void Keeper::add(Base* obj) {
    Base** temp = new Base * [size + 1];      // Создаём новый массив на один элемент больше
    for (int i = 0; i < size; i++) temp[i] = items[i]; // Копируем старые указатели
    temp[size] = obj;                       // Добавляем новый объект
    delete[] items;                         // Удаляем старый массив указателей
    items = temp;                           // Присваиваем новый
    size++;                                 // Увеличиваем размер
    cout << "[Keeper] Object added" << endl;
}

// Удалить объект по индексу
void Keeper::remove(int index) {
    if (index < 0 || index >= size)         // Проверяем, что индекс корректный
        throw out_of_range("Invalid index");

    delete items[index];                    // Удаляем сам объект

    Base** temp = new Base * [size - 1];      // Новый массив на 1 меньше
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) temp[j++] = items[i]; // Копируем все, кроме удаляемого
    }

    delete[] items;                         // Удаляем старый массив указателей
    items = temp;
    size--;                                 // Уменьшаем размер
    cout << "[Keeper] Object removed" << endl;
}

// Изменить объект по индексу
void Keeper::edit(int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Invalid index");

    cout << "Editing object #" << index + 1 << endl;
    items[index]->input();                  // Вызываем у объекта его метод input()
}

// Показать все объекты
void Keeper::showAll() const {
    if (size == 0) {
        cout << "[Keeper] Container is empty" << endl;
        return;
    }
    cout << "\n--- List of animals ---\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";              // Номер элемента
        items[i]->show();                   // Полиморфный вызов show() конкретного класса
    }
}

// Сохранить все объекты в файл
void Keeper::saveToFile(const string& filename) const {
    ofstream fout(filename);
    if (!fout) throw runtime_error("Cannot open file for saving");

    fout << size << '\n';                    // сколько объектов
    for (int i = 0; i < size; i++) {
        if (dynamic_cast<Fish*>(items[i]))      fout << "Fish ";
        else if (dynamic_cast<Bird*>(items[i])) fout << "Bird ";
        else if (dynamic_cast<Cat*>(items[i]))  fout << "Cat ";
        items[i]->save(fout);                // ← здесь сохраняем ТОЛЬКО поля
        fout << '\n';
    }
    cout << "[Keeper] Saved to file: " << filename << endl;
}

// Загрузить объекты из файла
void Keeper::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) throw runtime_error("Cannot open file for loading");

    for (int i = 0; i < size; i++) delete items[i];
    delete[] items; items = nullptr; size = 0;

    int newSize;
    fin >> newSize;

    for (int i = 0; i < newSize; i++) {
        string type; fin >> type;
        Base* obj = nullptr;
        if (type == "Fish") obj = new Fish;
        else if (type == "Bird") obj = new Bird;
        else if (type == "Cat")  obj = new Cat;
        else throw runtime_error("Unknown object type in file");

        obj->load(fin);   // поля читаются через std::quoted
        add(obj);
    }
    cout << "[Keeper] Loaded from file: " << filename << endl;
}
// Перегрузка оператора += (добавление)
Keeper& Keeper::operator+=(Base* obj) {
    add(obj);
    return *this;
}

// Перегрузка [] — доступ к элементу по индексу
Base* Keeper::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Invalid index");
    return items[index];
}

// Перегрузка оператора = (копирование контейнера)
Keeper& Keeper::operator=(const Keeper& other) {
    if (this == &other) return *this;       // Проверка на самоприсваивание

    // Удаляем старые данные
    for (int i = 0; i < size; i++) delete items[i];
    delete[] items;

    // Копируем новые
    size = other.size;
    items = new Base * [size];
    for (int i = 0; i < size; i++) items[i] = other.items[i];
    return *this;
}
