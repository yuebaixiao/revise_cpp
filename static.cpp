#include <iostream>
using namespace std;

class Test{
  friend void fun(const Test &t);
public:
  Test(int d = 0) : data(d){
    count++;
  }
  ~Test(){
    count--;
  }
private:
  int data;
  static int count;
  static void a(){
    b();
  }
  static void b(){}
};

void fun(const Test &t){
  cout << t.data << endl;
  cout << Test::count << endl;
}


//初始化static成员变量
int Test::count = 0;

int main(){
  Test t(10);
  fun(t);
  Test t1(11);
  fun(t1);
}
