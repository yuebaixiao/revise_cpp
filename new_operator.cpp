#include <iostream>
#include <string.h>
using namespace std;

class String{
public:
  String(const char* str = ""){
  cout << "Create" << endl;
    if(NULL == str){
      data = new char[1];
      data[0] = '\0';
    }
    else{
      data = new char[strlen(str) + 1];
      strcpy(data, str);
    }
  }
  ~String(){
  cout << "Free" << endl;
    delete []data;
    data = NULL;
  }
private:
  char* data = NULL;
};

void* operator new(size_t sz){
  cout << "in operator new" << endl;
  void* o = malloc(sz);
  return o;
}
void operator delete(void *o){
  cout << "in operator delete" << endl;
  free(o);
}

void* operator new[](size_t sz){
  cout << "in operator new[]" << endl;
  void* o = malloc(sz);
  return o;
}
void operator delete[](void *o){
  cout << "in operator delete[]" << endl;
  free(o);
}

//第一个参数size_t即使不适用，也必须有
void* operator new(size_t sz, String* s, int pos){
  return s + pos;
}
int main(){
  String *s = new String("abc");
  delete s;

  String *sr = new String[3];
  delete []sr;

  //开辟内存池，但是还没有调用过对象的构造方法
  String *ar = (String*)operator new(sizeof(String) * 2);
  //调用池里第一个对象的构造方法
  new(ar, 0)String("first0");
  //调用池里第二个对象的构造方法
  new(ar, 1)String("first1");
  //调用池里第一个对象的析构方法，注意不会释放到内存
  (&ar[0])->~String();
  //调用池里第二个对象的析构方法，注意不会释放到内存
  (&ar[1])->~String();
  //下面语句执行前，内存池里的对象可以反复利用
  operator delete(ar);

}
