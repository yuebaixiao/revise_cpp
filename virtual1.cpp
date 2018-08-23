#include <iostream>
using namespace std;

class Base{
public:
  Base(int d = 0) : data(d){}
  //virtual ~Base(){}
  virtual void show(){cout << "Base show" << endl;}
  virtual void show1(){cout << "Base show1" << endl;}
private:
  int data;
};

class Ba : public Base{
public:
  void show(){cout << "Ba show" << endl;}
  virtual void fun(){}
};

int main(){
  Base b;
  Ba ba;

  return 0;
}
