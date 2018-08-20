#include "template_class.h"

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

