#include "s21_stack.h"

namespace s21 {
template <class T, class Container>
void Stack<T, Container>::Display() {
  list_.Display();
}

template <class T, class Container>
bool Stack<T, Container>::Empty() const {
  return list_.Empty();
}

template <class T, class Container>
typename Stack<T, Container>::const_reference Stack<T, Container>::Top() const {
  return list_.Back();
}

template <class T, class Container>
void Stack<T, Container>::Push(const_reference value) {
  list_.PushBack(value);
}

template <class T, class Container>
typename Stack<T, Container>::size_type Stack<T, Container>::Size() const {
  return list_.Size();
}

template <class T, class Container>
void Stack<T, Container>::Swap(Stack &o) {
  list_.Swap(o.list_);
}

template <class T, class Container>
void Stack<T, Container>::Pop() {
  list_.PopBack();
}

}  // namespace s21