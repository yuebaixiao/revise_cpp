#include <iostream>
using namespace std;

class Test;

class A{
 public:
  A(int d = 0) : data(d){}
  void fun(const Test &t);
  void fun1(const Test &t);
  
 private:
  int data;
};

class Test{
  friend void A::fun(const Test &t);
public:
  Test(int d = 10) : data(d){}
private:
  int data;
};

void A::fun(const Test &t){
  cout << t.data << endl;
}
void A::fun1(const Test &t){
  //编译不能通过，因为fun1不是class Test的友元函数。
  //cout << t.data <<endl;
}
int main(){
  Test t(100);
  A a;
  a.fun(t);
}
