#include <iostream>
#include "Keeper.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "C"); // Используем стандартную английскую локаль

    Keeper zoo; // Создаём контейнер
    int choice;

    while (true) {
        // Главное меню программы
        cout << "\nMENU\n"
            << "1. Add animal\n"
            << "2. Show all animals\n"
            << "3. Edit animal\n"
            << "4. Remove animal\n"
            << "5. Save to file\n"
            << "6. Load from file\n"
            << "7. Exit\n"
            << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Select animal type (1 - Fish, 2 - Bird, 3 - Cat): ";
            int type;
            cin >> type;

            Base* obj = nullptr; // Указатель на базовый класс

            // Создаём объект нужного типа
            if (type == 1) obj = new Fish;
            else if (type == 2) obj = new Bird;
            else if (type == 3) obj = new Cat;
            else {
                cout << "Invalid type!\n";
                continue;
            }

            obj->input();  // Вызываем ввод данных
            zoo += obj;    // Добавляем объект в контейнер
        }
        else if (choice == 2) {
            zoo.showAll(); // Вывод всех объектов
        }
        else if (choice == 3) {
            cout << "Enter animal number to edit: ";
            int index;
            cin >> index;
            try {
                zoo.edit(index - 1); // Изменяем выбранный объект
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 4) {
            cout << "Enter animal number to remove: ";
            int index;
            cin >> index;
            try {
                zoo.remove(index - 1); // Удаляем выбранный объект
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 5) {
            try {
                zoo.saveToFile("animals.txt"); // Сохраняем в файл
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 6) {
            try {
                zoo.loadFromFile("animals.txt"); // Загружаем из файла
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 7) {
            cout << "Exiting program..." << endl;
            break; // Завершаем работу программы
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
