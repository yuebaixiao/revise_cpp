#include <iostream>
using namespace std;

class Imaginary{
  friend Imaginary operator+(int i, const Imaginary &m);
  friend ostream& operator<<(ostream &os, const Imaginary &m);
  friend istream& operator>>(istream &is, Imaginary &m);
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
  Imaginary operator+ (int i){
    return Imaginary(real + i, imag);
  }
  Imaginary& operator= (const Imaginary &m){
    cout << "asign" << endl;
    if(this != &m){
      real = m.real;
      imag = m.imag;
    }
    return *this;
  }
  ostream& operator<<(ostream& os){
    os <<  "[" << real << "," << imag << "]";
    return os;
  }
  ~Imaginary(){
    cout << this << endl;
  }
private:
  int real;
  int imag;
};
Imaginary operator+(int i, const Imaginary &m){
  return Imaginary(i + m.real, m.imag);
}

ostream& operator<<(ostream &os, const Imaginary &m){
  os <<  "(" << m.real << "," << m.imag << ")";
  return os;
}
istream& operator>>(istream &is, Imaginary &m){
  is >> m.real >> m.imag;
  return is;
}
int main(){
  Imaginary m1(10, 20);
  Imaginary m2(1, 2);
  Imaginary m3 = m1 + m2;
  Imaginary m4 = m1 + 10;
  Imaginary m5 = 20 + m1;
  cout << "a" << m5 << "aa" << endl;;
  m5 << cout << "bb" << endl;
  Imaginary m6;
  cin >> m6;
  cout << m6 << endl;
  return 0;
}
