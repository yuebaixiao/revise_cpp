#include <iostream>
using namespace std;

class Base{
public:
  virtual Base* show(){
    cout << "Base show" << endl;
    return this;
  }
  Base(){cout << "create base" << endl;}
  virtual ~Base(){cout << "free base" << endl;}
};

class Ba : public Base{
public:
  Ba* show(){
    cout << "Ba show" << endl;
    return this;
  }
  Ba(){cout << "creata ba" << endl;}
  ~Ba(){cout << "free ba" << endl;}
};

int main(){
  //知识点1
  Ba ba;
  Base* pb = &ba;
  //会调用子类Ba的show方法，虽然show返回值不同
  pb->show();

  //知识点2
  Base *pb1 = new Ba;
  //如果父类的析构函数不是虚函数的话，就不能调用子类的析构函数
  delete pb1;
}
