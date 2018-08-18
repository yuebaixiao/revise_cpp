#include <iostream>
using namespace std;

class Test{
public:
  Test(int d = 0):data(d){
    cout << "C:" << d << " " << this << endl;
  }
  Test(Test &t){
    cout << "Copy:" << t.data << " " << this << endl;
    data = t.data;
  }
  
  Test& operator = (const Test &t){
    cout << "Assign:" << this << " = " << &t << endl;
    if(this != &t){
      data = t.data;
    }
    return *this;
    }
  
  ~Test(){
    cout << "F:" << this->data << "->" << this << endl;
  }
  int getData()const{
    return data;
  }
private:
  int data;
};


Test& fun(Test &x){
  int value = x.getData();
  Test tmp(value);
  return tmp;
  
}

int main(){
  Test t1(100);
  Test t2;
  t2 = fun(t1);
  cout << t2.getData() << endl;
  //Test t2 = fun(t1);
 
  return 0;
}
