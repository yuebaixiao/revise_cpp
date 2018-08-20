#include <iostream>
using namespace std;

template<typename A>
class List;

//节点
template<typename A>
class ListNode{
  friend class List<A>;
public:
  ListNode():data(A()), next(NULL){}
  ListNode(A a, ListNode *n) : data(a), next(n){}
private:
  A data;
  ListNode *next;
};

//单链表
template<typename A>
class List{
public:
  List();
  //尾插
  bool push_back(A val);
  //显示链表
  void show()const{
    ListNode<A> *n = first->next;
    while(NULL != n){
      cout << n->data;
      n = n->next;
    }
    cout << "NULL" << endl;
  }
private:
  ListNode<A> *first;
  ListNode<A> *last;
  size_t size;
};

template<typename T>
List<T>::List(){
  first = last = new ListNode<T>;
  last->next = NULL;
  size = 0;
}
//尾插
template<typename A>
bool List<A>::push_back(A value){
  ListNode<A> *node = new ListNode<A>;
  if(NULL == node) return false;
  node->data = value;
  node->next = NULL;

  last->next = node;
  last = node;
  size++;

  return true;
}
//显示链表
/*
template<typename A>
void List<A>::show()const{
  ListNode<A> *n = first->next;
  while(NULL != n){
    cout << n->data;
    n = n->next;
  }
  cout << "NULL" << endl;
}
*/
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
