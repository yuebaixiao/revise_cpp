#include <iostream>
#include <string.h>
using namespace std;

class String{
 public:
  String(const char* str = ""){
    if(NULL == str){
      data = (char*)malloc(sizeof(char));
      data[0] = '\0';
    }
    else{
      data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
      strcpy(data, str);
    }
  }
  String (const String &str){
    data = (char*)malloc(sizeof(char) * (strlen(str.data) + 1));
    strcpy(data, str.data);
  }
  String& operator= (const String &str){
    if(this != &str){
      char* tmp = data;
      data = (char*)malloc(sizeof(char) * (strlen(str.data) + 1));
      if(NULL == data){
	data = tmp;
      }
      else{
	free(tmp);
	tmp = NULL;
	strcpy(data, str.data);
      }
    }
    return *this;
  }
  ~String(){
    free(data);
    data = NULL;
  }
  char* getData(){
    return data;
  }
 private:
  char *data;
};

int main(){
  char* a = "abc";
  String s(a);

  String s1(s);
  
  String s2;
  s2 = s1;


  return 0;
}
