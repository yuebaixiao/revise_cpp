#include <iostream>
#include <malloc.h>

using namespace std;

void c_1(){
  //c方式的内存空间的动态开辟
  int n;
  cin >> n;
  int *p = (int*)malloc(sizeof(int) * n);
  for(int i = 0; i < n ; ++i){
    p[i] = i;
  }
  free(p);
}

void cpp_1(){
  //c++方式的内存空间的动态开辟
  int m;
  cin >> m;
  int *q = new int[m];
  for(int i = 0; i < m ; ++i){
    q[i] = i;
  }
  //释放数组的空间，要加[]
  delete []q;
}

class Test{
public:
  Test(int d = 0) : data(d){
    cout << "create" << endl; 
  }
  ~Test(){
    cout << "free" << endl;
  }
private:
  int data;
};

void c_2(){
  Test *t = (Test*)malloc(sizeof(Test));
  free(t);
}
void cpp_2(){
  Test *t = new Test(10);
  delete t;
}
int main(){
  c_1();
  cpp_1();

  c_2();
  cpp_2();

  Test *t = new Test[3];
  delete []t;

  return 0;
}
