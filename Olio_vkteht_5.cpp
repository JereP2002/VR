#include <iostream>
#include <string>
using namespace std;

// Seuraaja-luokka yksittäisen solmun toteutukseen
class Seuraaja {
public:
    string nimi;               // Seuraajan nimi
    Seuraaja* next;            // Osoitin seuraavaan seuraajaan

    // Konstruktori
    Seuraaja(const string& nimi) : nimi(nimi), next(nullptr) {}

    // paivitys()-funktio tulostaa annetun viestin
    void paivitys(const string& viesti) {
        cout << "Seuraaja [" << nimi << "]: " << viesti << endl;
    }

    // getNimi()-funktio palauttaa seuraajan nimen
    string getNimi() const {
        return nimi;
    }
};

// Notifikaattori-luokka linkitetyn listan hallintaan
class Notifikaattori {
private:
    Seuraaja* alku;  // Listan alku

public:
    // Konstruktori
    Notifikaattori() : alku(nullptr) {}

    // Destruktori vapauttaa dynaamisesti varatut muistipaikat
    ~Notifikaattori() {
        while (alku != nullptr) {
            Seuraaja* poistettava = alku;
            alku = alku->next;
            delete poistettava;
        }
    }

    // Funktio seuraajan lisäämiseksi listan alkuun
    void lisaa(const string& nimi) {
        Seuraaja* uusiSeuraaja = new Seuraaja(nimi);
        uusiSeuraaja->next = alku;
        alku = uusiSeuraaja;
    }

    // Funktio seuraajan poistamiseksi listalta
    void poista(const string& nimi) {
        Seuraaja* nykyinen = alku;
        Seuraaja* edellinen = nullptr;

        while (nykyinen != nullptr) {
            if (nykyinen->getNimi() == nimi) {
                if (edellinen == nullptr) {
                    // Poistetaan listan ensimmäinen solmu
                    alku = nykyinen->next;
                } else {
                    // Ohitetaan poistettava solmu
                    edellinen->next = nykyinen->next;
                }
                delete nykyinen;
                cout << "Seuraaja \"" << nimi << "\" poistettu." << endl;
                return;
            }
            edellinen = nykyinen;
            nykyinen = nykyinen->next;
        }
        cout << "Seuraajaa \"" << nimi << "\" ei löytynyt." << endl;
    }

    // Funktio seuraajien nimien tulostamiseen
    void tulosta() const {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            cout << "Seuraaja: " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }

    // Funktio viestin postittamiseen seuraajille
    void postita(const string& viesti) {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
};

int main() {
    Notifikaattori notifikaattori;

    // Testataan lisäystoiminnallisuutta
    notifikaattori.lisaa("Alice");
    notifikaattori.lisaa("Bob");
    notifikaattori.lisaa("Charlie");

    cout << "Seuraajat listalla:" << endl;
    notifikaattori.tulosta();

    // Testataan viestin postitusta
    cout << "\nPostitetaan viesti seuraajille:" << endl;
    notifikaattori.postita("Tämä on testiviesti!");

    // Testataan poisto
    cout << "\nPoistetaan Bob..." << endl;
    notifikaattori.poista("Bob");

    cout << "\nSeuraajat listalla Bobin poiston jälkeen:" << endl;
    notifikaattori.tulosta();

    return 0;
}
