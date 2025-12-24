#include "Fish.h"
#include <iomanip> // std::quoted

Fish::Fish() {
    cout << "[Constructor] Default Fish created" << endl;
}

Fish::Fish(string s, string c, string f) : species(s), color(c), foodType(f) {
    cout << "[Constructor] Fish created with parameters" << endl;
}

Fish::Fish(const Fish& other) {
    species = other.species;
    color = other.color;
    foodType = other.foodType;
    cout << "[Constructor] Fish copy created" << endl;
}

Fish::~Fish() {
    cout << "[Destructor] Fish destroyed" << endl;
}

void Fish::input() {
    cin.ignore(); // очищаем буфер, чтобы корректно работал getline
    cout << "Enter fish species: ";
    getline(cin, species);
    cout << "Enter fish color: ";
    getline(cin, color);
    cout << "Enter fish food type: ";
    getline(cin, foodType);
}

void Fish::show() const {
    cout << "Fish | Species: " << species
        << ", Color: " << color
        << ", Food type: " << foodType << endl;
}

void Fish::save(ofstream& fout) const {
    // Сохраняем все поля в кавычках, чтобы поддерживать пробелы
    fout << std::quoted(species) << ' '
        << std::quoted(color) << ' '
        << std::quoted(foodType);
}

void Fish::load(ifstream& fin) {
    // Загружаем в том же порядке, в каком сохраняли
    fin >> std::quoted(species)
        >> std::quoted(color)
        >> std::quoted(foodType);
}

string Fish::getSpecies() const { return species; }
void Fish::setSpecies(string s) { species = s; }
