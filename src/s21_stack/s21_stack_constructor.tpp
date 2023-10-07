#include "s21_stack.h"

namespace s21 {
template <class T, class Container>
Stack<T, Container>::Stack() : list_() {}

template <class T, class Container>
Stack<T, Container>::Stack(std::initializer_list<value_type> const &items)
    : list_() {
  for (auto i = items.begin(); i != items.end(); i++) {
    this->Push(*i);
  }
}

template <class T, class Container>
Stack<T, Container>::Stack(const Stack &o) {
  *this = o;
}

template <class T, class Container>
Stack<T, Container>::Stack(Stack &&o) {
  *this = o;
  o.~Stack();
}

template <class T, class Container>
Stack<T, Container> &Stack<T, Container>::operator=(const Stack &o) {
  if (this != &o) {
    list_ = o.list_;
  }
  return *this;
}

template <class T, class Container>
Stack<T, Container> &Stack<T, Container>::operator=(Stack &&o) noexcept {
  if (this != &o) {
    *this = o;
    o.~Stack();
  }
  return *this;
}

template <class T, class Container>
Stack<T, Container>::~Stack() {}
}  // namespace s21