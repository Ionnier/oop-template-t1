#ifndef OOP_ALBUM_H
#define OOP_ALBUM_H

#include <vector>
#include <song.h>

// definirea unei clase
// obiect = instanta a unei clase
class Album {
private:
    // date membre private, nu pot fi accesate in mod direct din obiect
    std::string name;
    std::string author;
    std::vector<Song> songs;
public:
    // date membre publice, pot fi accesate in mod direct din obiect
    // functii = metode

    // constructor, modul in care instantiem o clasa
    Album(const std::string &name, const std::string &author);
    // pot exista mai multi constructori subincarcati

    // destructor, se apeleaza la distrugerea obiectului
    ~Album();


    // supraincarcare operatori
    friend Album &operator+(Album &album, const Song &song);

    const Song *operator[](const int &);
    // supraincarcare operatori


    // | declare separate functions for write and read | -> like Song class
    friend std::istream &operator>>(std::istream &, Album &);

    friend std::ostream &operator<<(std::ostream &, const Album &);
    // | declare separate functions for write and read |


    // metoda cu "logica"
    // in loc sa iau vectorul de songs si sa imi inlocuiesc manual melodia cu un setter
    // encapsulez logica in aceasta metoda
    const Album &update_song(const Song &s, const Song &t);

    // getters pentru datele memebre private, in caz ca avem nevoie de ele
    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const std::vector<Song> &getSongs() const;
};

#endif //OOP_ALBUM_H
