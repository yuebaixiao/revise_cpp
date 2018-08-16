#include <iostream>
using namespace std;

class Test{
public:
  explicit Test(int d):data(d){
    cout << "C:" << this << endl;
  }
  //拷贝构造函数
  explicit Test(const Test &t){
    cout << "Copy:" << this << endl;
    data = t.data;
  }
  ~Test(){
    cout << "F:" << this << endl;
  }
private:
  int data;
};
int main(){
  Test t1(10);
  Test t2(t1);//调用拷贝构造函数
  //Test t3 = t2;//编译不过
  Test t4(20);
  t2 = t4;

  return 0;
}
