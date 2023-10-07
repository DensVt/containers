#ifndef CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_

#include <cstdint>
#include <iostream>

namespace s21 {
template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;

  class ListIterator {
    friend class List<T>;
    friend class ListConstIterator;

   public:
    ListIterator(typename List::Node* ptr, typename List::Node* head,
                 typename List::Node* fake);

    ListIterator& operator++();
    ListIterator operator++(value_type);
    ListIterator& operator--();
    ListIterator operator--(value_type);
    bool operator==(ListIterator o) const;
    bool operator!=(ListIterator o) const;
    reference operator*() const;

    operator typename List<T>::const_iterator() {
      return List<T>::const_iterator(ptr_, head_, fake_);
    }

    void Display();

   protected:
    typename List::Node* ptr_;
    typename List::Node* head_;
    typename List::Node* fake_;
  };

  using iterator = ListIterator;

  class ListConstIterator {
    friend class List<T>;
    friend class ListIterator;

   public:
    ListConstIterator(typename List::Node* ptr, typename List::Node* head,
                      typename List::Node* fake);

    ListConstIterator& operator++();
    ListConstIterator operator++(value_type);
    ListConstIterator& operator--();
    ListConstIterator operator--(value_type);
    bool operator==(ListConstIterator o) const;
    bool operator!=(ListConstIterator o) const;
    const_reference operator*() const;

    operator typename List<T>::iterator() {
      return List<T>::iterator(ptr_, head_, fake_);
    }

    void Display();

   protected:
    typename List::Node* ptr_;
    typename List::Node* head_;
    typename List::Node* fake_;
  };

  using const_iterator = ListConstIterator;

  using size_type = std::size_t;

  List();
  List(std::initializer_list<value_type> const& items);
  List(const List& o);
  List(List&& o);
  ~List();
  List<T>& operator=(const List& o);
  List<T>& operator=(List&& o) noexcept;

  const_reference Back() const;
  const_reference Front() const;

  iterator Begin();
  iterator End();

  const_iterator Begin() const;
  const_iterator End() const;

  void Clear();

  bool Empty() const;
  size_type Size() const;
  size_type MaxSize() const;

  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void PushBack(const_reference value);
  void PopBack();
  void PushFront(const_reference value);
  void PopFront();
  void Swap(List& o);
  void Merge(List& o);
  void Splice(const_iterator pos, List<T>& o);
  void Reverse();
  void Unique();
  void Sort();

  void Display();

 protected:
  struct Node {
    value_type data;
    Node* next;
    Node* prev;

    Node() : prev(nullptr), next(nullptr) {}
    Node(value_type value) : data(value), prev(nullptr), next(nullptr) {}
  };
  Node* head;
  Node* tail;
  Node* fake;

  size_type size;

  void CopyList(const List& o);
  void InitList(const_reference value);
  void FakeMerge();
  void LeftP(iterator left, iterator curr);
  void RightP(iterator right, iterator curr);
  void ListToNull();

  Node* GetMid();
  void NullException() const;
};
}  // namespace s21

#include "s21_list_basic.tpp"
#include "s21_list_const_iterator.tpp"
#include "s21_list_constructor.tpp"
#include "s21_list_exception.tpp"
#include "s21_list_iterator.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_