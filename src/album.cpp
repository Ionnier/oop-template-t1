#include <album.h>
#include <iostream>

// Implementarea efectiva a definitiilor din fisierul header pentru Album
// :: este operator de referentiere si face referire la clasa efectiva

Album::Album(const std::string &name, const std::string &author) {
    this->name = name;
    this->author = author;
}

Album::~Album() {
    songs.clear();
}

const std::string &Album::getName() const {
    return name;
}

Album &operator+(Album &album, const Song &song) {
    album.songs.push_back(song);
    return album;
}

const Song *Album::operator[](const int &position) {
    if (songs.size() <= position || position < 0) {
        return nullptr;
    }
    return &songs[position];
}

std::istream &operator>>(std::istream &in, Album &album) {
    std::cout << "nume = ";
    in >> album.name;

    std::cout << "author = ";
    in >> album.author;

    std::cout << "no_songs = ";
    int n;
    in >> n;

    Song s("");
    for (int i = 0; i < n; i++) {
        in >> s;
    }

    album.songs.push_back(s);

    return in;
}

std::ostream &operator<<(std::ostream &out, const Album &album) {
    out << "nume = " << album.name << std::endl;
    out << "author = " << album.author << std::endl;
    for (auto &song: album.songs) {
        out << song << std::endl;
    }
    return out;
}

const Album &Album::update_song(const Song &current, const Song &new_song) {
    for (auto &aux: songs) {
        if (aux == current) {
            aux = new_song;
            break;
        }
    }
    return *this;
}

const std::vector<Song> &Album::getSongs() const {
    return songs;
}
