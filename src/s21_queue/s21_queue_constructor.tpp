#include "s21_queue.h"

namespace s21 {
template <class T, class Container>
Queue<T, Container>::Queue() : list_() {}

template <class T, class Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> const &items)
    : list_() {
  for (auto i = items.begin(); i != items.end(); i++) {
    this->Push(*i);
  }
}

template <class T, class Container>
Queue<T, Container>::Queue(const Queue &o) {
  *this = o;
}

template <class T, class Container>
Queue<T, Container>::Queue(Queue &&o) {
  *this = o;
  o.~Queue();
}

template <class T, class Container>
Queue<T, Container> &Queue<T, Container>::operator=(const Queue &o) {
  if (this != &o) {
    list_ = o.list_;
  }
  return *this;
}

template <class T, class Container>
Queue<T, Container> &Queue<T, Container>::operator=(Queue &&o) noexcept {
  if (this != &o) {
    *this = o;
    o.~Queue();
  }
  return *this;
}

template <class T, class Container>
Queue<T, Container>::~Queue() {
  list_.Clear();
}
}  // namespace s21