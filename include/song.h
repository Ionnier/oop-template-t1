#ifndef OOP_SONG_H
#define OOP_SONG_H

#include <string>

// definirea unei clase
// obiect = instanta a unei clase
class Song {
private:
    // date membre private
    std::string name;
public:
    // constructor de initializare
    Song(const std::string &);

    Song();

    // constructor de copiere
    Song(const Song &);

    // destructor
    ~Song();

    // functii de citire si afisare
    void citire(std::istream &);

    void afisare(std::ostream &) const;
    // e destul de important sa fie functii, o sa vedem in viitor de ce


    // supracincarcarea operatorului de atribuire
    Song &operator=(const Song &);


    // supraincarcare operatori de afisare si intrare
    friend std::istream &operator>>(std::istream &, Song &);

    friend std::ostream &operator<<(std::ostream &, const Song &);
    // intorc o referinta la stream pentru a putea da chain la call-uri cout << 1 << 2;

    // supraincarcare operator egalitate
    friend bool operator==(const Song &, const Song &);

    // getter & setter pentru acces la date private
    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);
};

#endif //OOP_SONG_H