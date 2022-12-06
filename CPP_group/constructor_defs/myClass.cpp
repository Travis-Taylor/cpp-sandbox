/*  Practice for Andrew's cpp group
*   In this case, exercise looking at default constructor/destructor
*   definitions within headers as compared to within cpp files
*
*   TODO Give this more thought after reading some of Effective C++
*/


#include "myClass.h"

class MyClass {
  public:
  MyClass() {
    std::cout << "Constructing myClass!" << std::endl;
  }
  ~MyClass() {
    std::cout << "Destructing myClass!" << std::endl;
  }
};



int main() {
  MyClass c;
  Example e;
}

