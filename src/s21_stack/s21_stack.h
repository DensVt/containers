#ifndef CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_

#include "../s21_list/s21_list.h"

namespace s21 {
template <class T, class Container = List<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &o);
  Stack(Stack &&o);
  ~Stack();

  Stack<T, Container> &operator=(const Stack &o);
  Stack<T, Container> &operator=(Stack &&o) noexcept;

  const_reference Top() const;
  size_type Size() const;

  bool Empty() const;

  void Push(const_reference value);
  void Pop();
  void Swap(Stack &o);

  void Display();

 private:
  Container list_;
};
}  // namespace s21

#include "s21_stack_basic.tpp"
#include "s21_stack_constructor.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_