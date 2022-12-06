#include <iostream>
#include <memory>

class MyClass;

class Example {
  public:
  //~Example();
  std::unique_ptr<MyClass> my_class_ptr;
};
