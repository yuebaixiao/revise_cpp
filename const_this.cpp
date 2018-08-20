#include <iostream>
using namespace std;

class Test{
public:
  Test(int d = 0) : data(d){}
  void a()const{
    b();
  }
  void b()const{

  }
  ~Test(){}
private:
  int data;
};

int main(){
  Test t(10);
}
