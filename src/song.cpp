#include "song.h"
#include <iostream>


Song::Song(const std::string &name) {
    this->name = name;
}


Song::Song(const Song &aux) {
    name = aux.name;
}

Song::~Song() {
    name.clear();
}


void Song::citire(std::istream &in) {
    std::cout << "name = ";
    in >> name;
}


void Song::afisare(std::ostream &out) const {
    out << "name=" << name << std::endl;
}


std::istream &operator>>(std::istream &in, Song &aux) {
    aux.citire(in);
    return in;
}


std::ostream &operator<<(std::ostream &out, const Song &aux) {
    aux.afisare(out);
    return out;
}


Song &Song::operator=(const Song &aux) {
    if (this != &aux) {
        name = aux.name;
    }
    return *this;
}

const std::string &Song::getName() const {
    return name;
}

void Song::setName(const std::string &name) {
    Song::name = name;
}

bool operator==(const Song &a1, const Song &a2) {
    return a1.name == a2.name;
}
