#include <iostream>
using namespace std;

void swap(int &x, int &y){
  int tmp = x;
  x = y;
  y = tmp;
}
int main(){
  int x = 10;
  int y = 20;
  swap(x, y);

  int a = 1;
  int &b = a;

  int* p = &a;
  int* &q = p;

  int ar[2] = {1,2};
  int (&br)[2] = ar;

  const int m1 = 1;
  const int &m2 = m1;

  const int n1 = 1;
  //int &n2 = n1; //NG

  //b1和引用b2的地址相同
  const double b1 = 1.2;
  const double &b2 = b1;

  //d和引用f的地址不相同，因为发生了隐士类型转化,f是临时对象的引用
  const double d = 1.1;
  const int &f = d;

  return 0;
}
