#include <iostream>
using namespace std;

class CGood{

  int amount;
  float price;
  float total_value;
  char name[21];
};

int main(){
  cout << sizeof(CGood) <<endl;
  CGood c1;
  cout << sizeof(c1) <<endl;
}
