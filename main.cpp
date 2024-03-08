#include <iostream>
#include <album.h>

void afisare_meniu() {
    std::cout << "1. Adauga album" << std::endl;
    std::cout << "2. Vizualizare albume" << std::endl;
    std::cout << "3. Modifica melodie" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choice: ";
}

int main() {
    std::vector<Album> albums;
    int choice;
    bool display_menu = true;
    while (display_menu) {
        afisare_meniu();
        std::cin >> choice;
        std::cin.get();

        switch (choice) {
            case 0: {
                display_menu = false;
                break;
            }
            case 1: {
                Album a("", "");
                std::cin >> a;
                albums.push_back(a);
                break;
            }
            case 2: {
                for (auto &album: albums) {
                    std::cout << album;
                }
                break;
            }
            case 3: {
                std::string album_name;
                std::cout << "Album name = ";
                std::cin >> album_name;

                Album *album = nullptr;

                for (auto &aux: albums) {
                    if (aux.getName() == album_name) {
                        album = &aux;
                        break;
                    }
                }

                if (album == nullptr) {
                    std::cout << "Album not found";
                    break;
                }

                std::cout << "Current song";
                Song current("");
                std::cin >> current;

                std::cout << "New song";
                Song new_song("");
                std::cin >> new_song;

                album->update_song(current, new_song);
                break;
            }

            default: {
                std::cout << "Not implemented";
                break;
            }
        }
    }
}
