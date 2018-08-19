#include <iostream>
using namespace std;

class Int{
public:
  Int(int d):data(d){}
  Int& operator++(){//++a
    data++;
    return *this;
  }
  Int operator++(int){//a++
    Int tmp(data);
    data++;
    return tmp;
  }
  Int& operator--(){//--a
    data--;
    return *this;
  }
  
  Int operator--(int){//a--
    Int tmp(data);
    data--;
    return tmp;
  }
  
  ~Int(){
    cout << this << endl;
  }
private:
  int data;
};

int main(){
  Int i(10);
  Int i1 = ++i;
  Int i2 = i++;
  Int i3 = --i;
  Int i4 = i--;
  return 0;
}
