#include <iostream>
using namespace std;

class Imaginary{

public:
  Imaginary():real(0), imag(0){
    cout << "c:" << this << endl;
  }
  Imaginary(int real, int imag):real(real), imag(imag){
    cout << "c:" << this << endl;
  }
  Imaginary operator+ (const Imaginary &m){
    return Imaginary (real + m.real, imag + m.imag);
  }
  Imaginary& operator= (const Imaginary &m){
    cout << "asign" << endl;
    if(this != &m){
      real = m.real;
      imag = m.imag;
    }
    return *this;
  }
  ~Imaginary(){
    cout << this << endl;
  }
private:
  int real;
  int imag;
};

int main(){
  Imaginary m1(10, 20);
  Imaginary m2(1, 2);
  Imaginary m3;
  printf("m3 : %p\n",&m3);
  m3 = m1 + m2;
  cout << 1 << endl;

  return 0;
}
