#include <iostream>
using namespace std;

class Skup{

    private:
      int *pok;
    public:
        Skup(){
            pok = new int[10];

            for(int i = 0; i < 10; ++i){
                pok[i] = 0;
            }
        }

        Skup(int *p, int n){

            pok = new int[10];

            for(int i = 0; i < 10; ++i){
                if(i < n){
                    pok[i] = p[i];
                }else{
                    pok[i] = 0;

                }

            }

        }

        Skup(const Skup &s){
            pok = new int[10];

            for(int i = 0; i < 10; ++i){
                if(i < 10){
                    pok[i] = s.pok[i];
                }else{
                    pok[i] = 0;

                }

            }

        }
        Skup& operator=(const Skup &s) {
          for(int i = 0; i < 10; ++i) {
            if(s.pok[i] % 2 == 0) {
              pok[i] = 0;
            }
            else {
              pok[i] = 1;
            }
          }
        return *this;
        }

        Skup& operator-=(const Skup &s) {
          for(int i = 0; i < 10; ++i) {
            int temp = pok[i];
            pok[i] = 0;

            for(int j = 0; j < 10; ++j) {
              if(temp == s.pok[j]) {
                pok[i] = 1;
                break;
              }
            }
          }
          return *this;
        }

        friend bool operator==(const Skup &s1, const Skup &s2) {
          bool uspesno = true;

          if(&s1 != &s2) {
            for(int i = 0; i < 9; ++i) {
              bool pronadjen = false;
              for(int j = 0; j < 10; ++j) {
                if(s1.pok[i] == s2.pok[j]) {
                  pronadjen = true;
                  break;
                }
              }
              if(!pronadjen) {
                uspesno = false;
                break;
              }
            }
          }

          return uspesno;
        }

        friend ostream& operator<<(ostream &out, const Skup &s) {
          out << "{";

          for(int i = 0; i < 10; ++i) {
            out << s.pok[i];

            if(i < 9) {
              out << ", ";
            }

          }
          out << "}";

          return out;
        }

};

int main(){

    Skup s1;

    int niz1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int niz2[] = {8, -11, 9, 20, 3};

    Skup s2(niz1, 15);
    Skup s3(niz2, 5);

    cout << (s2 == s2 ? "DA" : "NE") << endl;
    cout << (s2 == s3 ? "DA" : "NE") << endl;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    return 0;

}
