#include <iostream>
using namespace std;

class Test{
public:
  explicit Test(int d):data(d){
    cout << "C:" << this << endl;
  }
  //拷贝构造函数
  Test(const Test &t){
    cout << "Copy:" << this << endl;
    data = t.data;
  }
  ~Test(){
    cout << "F:" << this->data << endl;
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
  Test t2(t1);//调用拷贝构造函数
  //Test t3 = t2;//编译不过
  Test t5 = test(t1);
  //Test t4(20);
  //t2 = t4;
  Test t6 = (Test)100;

  return 0;
}
