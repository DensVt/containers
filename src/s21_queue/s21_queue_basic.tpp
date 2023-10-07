#include "s21_queue.h"

namespace s21 {
template <class T, class Container>
void Queue<T, Container>::Display() {
  list_.Display();
}

template <class T, class Container>
bool Queue<T, Container>::Empty() const {
  return list_.Empty();
}

template <class T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::Front()
    const {
  return list_.Back();
}

template <class T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::Back()
    const {
  return list_.Front();
}

template <class T, class Container>
void Queue<T, Container>::Push(const_reference value) {
  list_.PushFront(value);
}

template <class T, class Container>
typename Queue<T, Container>::size_type Queue<T, Container>::Size() const {
  return list_.Size();
}

template <class T, class Container>
void Queue<T, Container>::Swap(Queue &o) {
  list_.Swap(o.list_);
}

template <class T, class Container>
void Queue<T, Container>::Pop() {
  list_.PopBack();
}

}  // namespace s21