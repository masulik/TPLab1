#include "Bird.h"
#include <iomanip>

Bird::Bird() {
    cout << "[Constructor] Default Bird created" << endl;
}

Bird::Bird(string s, string c, string f, string h)
    : species(s), color(c), food(f), habitat(h) {
    cout << "[Constructor] Bird created with parameters" << endl;
}

Bird::Bird(const Bird& other) {
    species = other.species;
    color = other.color;
    food = other.food;
    habitat = other.habitat;
    cout << "[Constructor] Bird copy created" << endl;
}

Bird::~Bird() {
    cout << "[Destructor] Bird destroyed" << endl;
}

void Bird::input() {
    cin.ignore();
    cout << "Enter bird species: ";
    getline(cin, species);
    cout << "Enter bird color: ";
    getline(cin, color);
    cout << "Enter bird food: ";
    getline(cin, food);
    cout << "Enter bird habitat: ";
    getline(cin, habitat);
}


void Bird::show() const {
    cout << "Bird | Species: " << species << ", Color: " << color
        << ", Food: " << food << ", Habitat: " << habitat << endl;
}

void Bird::save(ofstream& fout) const {
    fout << std::quoted(species) << ' '
        << std::quoted(color) << ' '
        << std::quoted(food) << ' '
        << std::quoted(habitat);
}

void Bird::load(ifstream& fin) {
    fin >> std::quoted(species)
        >> std::quoted(color)
        >> std::quoted(food)
        >> std::quoted(habitat);
}
