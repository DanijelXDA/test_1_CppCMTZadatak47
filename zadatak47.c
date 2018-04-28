#include <iostream>
using namespace std;

class Skup {
    private:
        int *pok;
    public:
        Skup() {
            pok = new int[10];

            for(int i = 0; i < 10; ++i) {
                pok[i] = 0;
            }
        }

        Skup(int *niz, int duzina) {
            pok = new int[10];

            for(int i = 0; i < 10; ++i) {
                if( i < duzina && duzina < 10) {
                    pok[i] = niz[i];
                }
                else {
                    pok[i] = 0;
                }
            }
        }

        Skup(const Skup &sk) {

            for(int i = 0; i < 10; ++i){
                pok[i] = sk.pok[i];
            }

        }

        Skup& operator=(const Skup &s) {
            for(int i = 0; i < 10; ++i){
                if( s.pok[i] % 2 == 0) {
                    s.pok[i] = 0;
                }
                else {
                    s.pok[i] = 1;
                }
            }

        }

        Skup& operator-=(const Skup &s) {
            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < 10; ++j) {
                if( pok[i] == s.pok[j]) {
                    pok[i] = 1;
                }
                else {
                    pok[i] = 0;
                }
            }
        }

        friend Skup& operator==(const Skup &s1, const Skup &s2) {
            bool uspesno = false;

            for(int i = 0; i < 10; ++i)
                for(int j = 0; j < 10; ++j) {
                    if(s1.pok[i] == s2.pok[j]) {
                        uspesno = true;
                    }
            }
            if(uspesno)
                cout << "Nizovi su jednaki" << endl;
        }

        friend ostream& operator<<(ostream &out, const Skup &s) {
            for(int i = 0; i < 10; ++i) {
                out << "{ " << s.pok[i] << ", ";
                out << " }";
            }
            return out;
        }
};

int main(void) {

    int niz[10] = {5, 31, 8, 4, 6, 9, 12, 3, 7, 14};
    Skup s1(niz, 10);

    return 0;
}
