#include <iostream>
using namespace std;

class Test{
public:
  explicit Test(){
    data = 0;
  }
  explicit Test(int d):data(d){
    cout << "C:" << this << ":"<< this->data << endl;
  }
  //拷贝构造函数
  Test(const Test &t){
    cout << "Copy:" << this << endl;
    data = t.data;
  }
  //重载=号运算符
  Test& operator = (const Test &t){
    cout << "assign" << this << endl;
    if(this != &t){
      data = t.data;
    }
    return *this;
  }
  ~Test(){
    cout << "F:" << this << ":" << this->data << endl;
  }
private:
  int data;
};

Test test(Test x){
  Test tmp(21);
  return tmp;
}
int main(){
  Test t1(10);
  Test t2, t3;

  t3 = t2 = t1;

  return 0;
}
