#pragma once

class Test {
  public: 
  // Add one.
  void inc() {
    i_++;
  }

  // Subtract one.
  void dec();

  // Set value to zero.
  void zero();

  private:
  int i_ = 0;
};
