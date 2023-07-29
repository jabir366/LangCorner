#include<iostream>
using namespace std;
int do_math(
  void * context, 
  int a, 
  int b, 
  int (*operation)(void * context, int a, int b)
  ){
  return operation(context,a,b);
}

class MyClass {
public:
  static int add_callback(void * context, int a, int b){
    //no access to member variables here
    return reinterpret_cast<MyClass*>(context)->add(a,b);
  }

  static int subtract_callback(void * context, int a, int b){
    //no access to member variables here
    return reinterpret_cast<MyClass*>(context)->subtract(a,b);
  }

  int add(int a, int b){
    //access to member variables is OK here
    cout<<"From Add";
    return a + b + m_offset;
  }

  int subtract(int a, int b){
    //access to member variables is OK here
    cout<<"From Subtract";
    return a - b + m_offset;
  }

   int m_offset;
};

int main(int argc, char * argv[]){
  MyClass no_offset;
  no_offset.m_offset = 0;

  MyClass offset;
  offset.m_offset = 10;

    //the compiler won't allow passing MyClass::add() directly because it is non-static
  do_math(&no_offset, 
    5, 
    5, 
    MyClass::add_callback); //returns 5+5 + 0
  do_math(&offset, 
    5, 
    5, 
    MyClass::subtract_callback); //return 5-5 + 10

  return 0;
}
