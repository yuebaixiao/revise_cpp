#include <iostream>
using namespace std;

class Test{
public:
  //explicit Test(int d):data(d){
  //cout << "create Test obj:" << this << endl;
  //}
  explicit Test(int d=0, int f=1):data(d),cnt(f){}
  ~Test(){
    cout << "Free Test obj:" << this << endl;
  }
  operator int(){
    return data;
  }
private:
  int data;
  int cnt;
};
int main(){
  Test t(10,20);
  //Test t;
  t = (Test)100;
  int b = t;
  return 0;
}
