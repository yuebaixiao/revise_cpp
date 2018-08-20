#include "template_class.h"

class Value{
  friend ostream& operator<<(ostream &o, const Value &v);
public:
  Value(int d = 0) : value(d){}
private:
  int value;
};
ostream& operator<<(ostream &o, const Value &v){
  o << v.value << "->";
  return o;
}
int main(){
  List<Value> l;
  for(int i = 0; i < 10; ++i){
    l.push_back(Value(i));
  }
  l.show();
}
