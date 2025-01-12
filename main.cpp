#include <iostream>

using namespace std;
// prototyyppi
int game( int maxnum);

int main()
    {
    int arvausten_lkm = 0;
        int maxnum = 40;
    arvausten_lkm = game(maxnum);
        cout << "Arvauksia: "
         << arvausten_lkm
         << endl;
        /*
        int satunnaisluku = 0;
        int arvaus = 0;

    //1Arvotaan satunnainen luku
        satunnaisluku = 17;
        while (true){
    //2Kysytään pelaajalta arvaus
    cout << "anna luku? "
         << endl;
        cin >> arvaus;
    // kun pelaaja tekee arvauksen lkm +1
    arvausten_lkm++;
    // 3.1 jos arvaus on yhtäsuuri kuin satunnaisluku
    if (arvaus == satunnaisluku){
            cout << "Oikein"
             << endl;
        break;
     }

    // 3.2 jos arvaus on pienempi kuin satunnaisluku
        if (arvaus < satunnaisluku) {
            cout << "Arvauksesi on pienempi kuin satunnaisluku"
                 << endl;
        }
    // 3.3 jos arvaus on suurempi kuin satunnaisluku
        if (arvaus > satunnaisluku) {
            cout << "Arvauksesi on suurempi kuin satunnais luku"
                 << endl;
        }

    //4Kerrotaan tarkistuksen tulos tyyliin ”luku on pienempi/suurempi” tai ”oikea vastaus”
    //5Jos pelaajan vastaus ei ollut oikein, niin palataan kohtaan 2.

    }

*/
    return 0;
}
    // prototyyppi
int game(int maxnum){
    int satunnaisluku = 0;
    int arvaus = 0;
    int arvausten_lkm = 0;
    cout << "Maxnum="
         << maxnum
         << endl;
    //1Arvotaan satunnainen luku
    satunnaisluku = 17;
    while (true){
        //2Kysytään pelaajalta arvaus
        cout << "anna luku? "
             << endl;
        cin >> arvaus;
        // kun pelaaja tekee arvauksen lkm +1
        arvausten_lkm++;
        // 3.1 jos arvaus on yhtäsuuri kuin satunnaisluku
        if (arvaus == satunnaisluku){
            cout << "Oikein"
                 << endl;
            break;
        }

        // 3.2 jos arvaus on pienempi kuin satunnaisluku
        if (arvaus < satunnaisluku) {
            cout << "Arvauksesi on pienempi kuin satunnaisluku"
                 << endl;
        }
        // 3.3 jos arvaus on suurempi kuin satunnaisluku
        if (arvaus > satunnaisluku) {
            cout << "Arvauksesi on suurempi kuin satunnais luku"
                 << endl;
        }

        //4Kerrotaan tarkistuksen tulos tyyliin ”luku on pienempi/suurempi” tai ”oikea vastaus”
        //5Jos pelaajan vastaus ei ollut oikein, niin palataan kohtaan 2.

    }
    return 0;
}
