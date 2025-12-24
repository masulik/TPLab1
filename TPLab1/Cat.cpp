#include "Cat.h"
#include <iomanip>

Cat::Cat() {
    cout << "[Constructor] Default Cat created" << endl;
}

Cat::Cat(string s, string c, string o, string n)
    : species(s), color(c), owner(o), name(n) {
    cout << "[Constructor] Cat created with parameters" << endl;
}

Cat::Cat(const Cat& other) {
    species = other.species;
    color = other.color;
    owner = other.owner;
    name = other.name;
    cout << "[Constructor] Cat copy created" << endl;
}

Cat::~Cat() {
    cout << "[Destructor] Cat destroyed" << endl;
}

void Cat::input() {
    cin.ignore();
    cout << "Enter cat species: ";
    getline(cin, species);
    cout << "Enter cat color: ";
    getline(cin, color);
    cout << "Enter owner's full name: ";
    getline(cin, owner);
    cout << "Enter cat name: ";
    getline(cin, name);
}


void Cat::show() const {
    cout << "Cat | Species: " << species << ", Color: " << color
        << ", Owner: " << owner << ", Name: " << name << endl;
}

void Cat::save(ofstream& fout) const {
    fout << std::quoted(species) << ' '
        << std::quoted(color) << ' '
        << std::quoted(owner) << ' '
        << std::quoted(name);
}

void Cat::load(ifstream& fin) {
    fin >> std::quoted(species)
        >> std::quoted(color)
        >> std::quoted(owner)
        >> std::quoted(name);
}
