#include <iostream>
using namespace std;

class Test{
  friend void show(const Test &t);
public:
  Test(int d = 0) : data(d){}
private:
  void fun()const{
    cout << "fun:" << data << endl;
  }
  int data;
};

//友元，即可以访问私有成员变量，也可以访问私有方法
void show(const Test &t){
  cout << "friend of Test:" << t.data << endl;
  t.fun();
}

int main(){
  Test t(100);
  show(t);

  return 0;
}
