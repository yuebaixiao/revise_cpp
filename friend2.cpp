#include <iostream>
using namespace std;

class Test;

class B{
public:
  void fun1(const Test &t);
  void fun2(const Test &t);
};

class Test{
  friend class B;
public:
  Test(int d = 0) : data(d){}
private:
  void pri()const{
    cout << "pri" << endl;
  }
  int data;
};

void B::fun1(const Test &t){
  cout << t.data << endl;
}
void B::fun2(const Test &t){
  t.pri();
}

int main(){
  Test t(10);
  B b;
  b.fun1(t);
  b.fun2(t);
}
