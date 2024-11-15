#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <optional>

using namespace std::chrono_literals;


/**
 * Please write a "circular buffer" class for arbitrary types.
 *   - It should have a compile-time fixed size.
 *   - Like a linked list, it should support both a:
 *     - "push" operation for adding an element, and a
 *     - "pop" operation for reading and removing an element.
 */

template <typename T>
class BufferElement {
  public:
  BufferElement() {}
  BufferElement(BufferElement* prev_in) : prev(prev_in) {}

  std::optional<T> data;
  BufferElement* next;
  BufferElement* prev;
};

template <typename T>
class CircularBuffer {
  public:
  /**
   * @brief Initialize the buffer
   * @details Ensure that all next and prev members are initialized
   * in the buffer elements
   */
  explicit CircularBuffer(size_t size) {
    size_ = size;
    BufferElement<T>* first = new BufferElement<T>();
    BufferElement<T>* curr = new BufferElement<T>{first};
    first->next = curr;
    for (size_t ii = 2; ii < size; ii++) {
      BufferElement<T>* new_element = new BufferElement<T>{curr};
      curr->next = new_element;
//      std::cout << "Elem " << curr << " | prev: " << curr->prev << ", next: " << curr->next << std::endl;
      curr = new_element;
    } 
    // Join the start and end
    curr->next = first;
 //   std::cout << "Elem " << curr << " | prev: " << curr->prev << ", next: " << curr->next << std::endl;
    first->prev = curr;
  //  std::cout << "Elem " << first << " | prev: " << first->prev << ", next: " << first->next << std::endl;
    head_ = first;
    tail_ = first;
  }

  /**
   * @brief Push a new element to the buffer, returning a bool success result
   * @details Fails if the buffer is full
   */
  bool Push(const T& data) {
    if (head_->next->data.has_value()) {
      // Buffer full
      return false;
    }
    head_->next->data = std::optional<T>{data};
    head_ = head_->next;
    // Update tail, if the buffer was empty
    if (!tail_->data.has_value()) {
      tail_ = head_;
    }
    return true;
  }

  /**
   * @brief Pop an element from the buffer, returning the oldest element.
   * @details Returns std::nullopt if the buffer is empty.
   */
  std::optional<T> Pop() {
    std::optional<T> value = tail_->data;
    if (value.has_value()) {
      tail_->data = std::nullopt;
      tail_ = tail_->next;
    }
    return value;
  }

  // Debugging
  void Print() {
    //std::cout << "Head: " << head_ << std::endl;
    //std::cout << "Tail: " << tail_ << std::endl;
    BufferElement<T>* curr = head_;
    for (size_t ii = 0; ii < size_; ii++) {
      //std::cout << "\t" << ii << "(" << curr << "):";
      std::cout << ii << ":";
      if (curr->data) {
        std::cout << curr->data.value();
      } else {
        std::cout << "null";
      }
      std::cout << ", "; 
      //std::cout << std::endl;
      curr = curr->prev;
    }
    std::cout << std::endl;
    //PrintReverse();
  }

  void PrintReverse() {
    std::cout << "In reverse:" << std::endl;
    BufferElement<T>* curr = tail_;
    for (size_t ii = size_; ii > 0; ii--) {
      //std::cout << "\t" << ii << "(" << curr << "):";
      std::cout << ii << ":";
      if (curr->data) {
        std::cout << curr->data.value();
      } else {
        std::cout << "null";
      }
      std::cout << ", "; 
      //std::cout << std::endl;
      curr = curr->next;
    }
    std::cout << std::endl;
  }

  private:
  size_t size_;
  BufferElement<T>* head_;
  BufferElement<T>* tail_;
};

int main() {
    //Test code here.
    CircularBuffer<int> buffer{9};
    buffer.Print();
    std::cout << std::endl;
    for (int ii = 0; ii < 10; ii++) {
      bool res = buffer.Push(10 + ii);
      if (!res) std::cout << "Failed to push " << ii << std::endl;
      buffer.Print();
      std::cout << std::endl;
    }
    for (int ii = 0; ii < 10; ii++) {
      std::optional<int> popped = buffer.Pop();
      if (popped) {
        std::cout << "Popped: " << popped.value() << std::endl;
      } else {
        std::cout << "Nothing popped" << std::endl;
      }
      buffer.Print();
    }
    
    return 0;
}
