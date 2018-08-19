#include <iostream>
using namespace std;

class Test{
public:
  Test(int d = 0):data(d){
    cout << "c" << endl;
  }
  Test(const Test &t){
    cout << "copy" << endl;
    data = t.data;
  }
  Test& operator= (const Test &t){
    cout << "assign" << endl;
    if(this != &t){
      data = t.data;
    }
    return *this;
  }
  ~Test(){
    cout << "f" << endl;
  }
  Test* operator&(){
    cout << "operator&" << endl;
    return this;
  }
  const Test* operator&() const{
    cout << "const operator&" << endl;
    return this;
  }
private:
  int data;
};

int main(){
  Test t;//构造函数
  Test t1 = t;//拷贝构造函数
  Test t2;
  t2 = t;//operator=

  Test t3;
  Test *pt3 = &t3;//operator&

  const Test t4;
  const Test *pt4 = &t4;//const operator&
}
