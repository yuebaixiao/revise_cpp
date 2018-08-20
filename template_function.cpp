#include <iostream>
#include <typeinfo>

using namespace std;

class Test{
  friend ostream& operator<<(ostream &os, const Test &t);
public:
  Test(int d = 0) : data(d){}
  bool operator>(const Test &t){
    return data > t.data ? true : false;
  }
  ~Test(){}
private:
  int data;
};

ostream& operator<<(ostream &os, const Test &t){
  os << "Test::data : " << t.data;
  return os;
}
template<typename T>
T Max(T a, T b){
  cout << typeid(T).name() << endl;
  return a > b ? a : b;
}

int main(){
  cout << Max(1, 2) << endl;
  cout << Max('A', 'B') << endl;
  cout << Max(1.2f, 3.4f) << endl;
  cout << Max(1.2, 3.4) << endl;

  Test t(10);
  Test t1(11);
  cout << Max(t, t1) << endl;

  //编译不过
  //cout << Max(1, 2.1) << endl;
  cout << Max(1, (int)2.1) << endl;
  cout << Max((double)1, 2.1) << endl;
  cout << Max<int>(1, 2.1) << endl;
  cout << Max<double>(1, 2.1) << endl;
  cout << Max<>(1, 2) << endl;
}
