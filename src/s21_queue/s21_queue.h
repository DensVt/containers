#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_

#include "../s21_list/s21_list.h"

namespace s21 {
template <class T, class Container = List<T>>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Queue();
  Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &o);
  Queue(Queue &&o);
  ~Queue();

  Queue<T, Container> &operator=(const Queue &o);
  Queue<T, Container> &operator=(Queue &&o) noexcept;

  const_reference Front() const;
  const_reference Back() const;

  bool Empty() const;
  size_type Size() const;

  void Push(const_reference value);
  void Pop();
  void Swap(Queue &o);

  void Display();

 private:
  Container list_;
};
}  // namespace s21

#include "s21_queue_basic.tpp"
#include "s21_queue_constructor.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_