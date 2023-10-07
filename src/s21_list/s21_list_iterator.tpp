#include "s21_list.h"

namespace s21 {
template <class T>
List<T>::ListIterator::ListIterator(typename List::Node* ptr,
                                    typename List::Node* head,
                                    typename List::Node* fake)
    : ptr_(ptr), head_(head), fake_(fake){};

template <class T>
typename List<T>::ListIterator& List<T>::ListIterator::operator++() {
  if (ptr_ == fake_ && fake_) {
    ptr_ = fake_->next;
  } else if (ptr_) {
    ptr_ = ptr_->next;
  }
  return *this;
}

template <class T>
typename List<T>::ListIterator List<T>::ListIterator::operator++(value_type) {
  ListIterator tmp(*this);
  ++(*this);
  return tmp;
}

template <class T>
typename List<T>::ListIterator& List<T>::ListIterator::operator--() {
  if (ptr_ == fake_->next && fake_) {
    ptr_ = fake_;
  } else if (ptr_) {
    ptr_ = ptr_->prev;
  }
  return *this;
}

template <class T>
typename List<T>::ListIterator List<T>::ListIterator::operator--(value_type) {
  ListIterator tmp(*this);
  --(*this);
  return tmp;
}

template <class T>
bool List<T>::ListIterator::operator==(ListIterator o) const {
  return o.ptr_ == ptr_;
}

template <class T>
bool List<T>::ListIterator::operator!=(ListIterator o) const {
  return o.ptr_ != ptr_;
}

template <class T>
typename List<T>::reference List<T>::ListIterator::operator*() const {
  return ptr_->data;
}

template <class T>
void List<T>::ListIterator::Display() {
  std::cout << ptr_->data << "\n";
}

template <class T>
typename List<T>::const_iterator List<T>::Begin() const {
  const_iterator it(head, head, fake);
  if (Empty()) {
    it.head_ = fake;
  }
  return it;
}

template <class T>
typename List<T>::iterator List<T>::Begin() {
  iterator it(head, head, fake);
  if (Empty()) {
    it.head_ = fake;
  }
  return it;
}

template <class T>
typename List<T>::const_iterator List<T>::End() const {
  return const_iterator(fake, head, fake);
}

template <class T>
typename List<T>::iterator List<T>::End() {
  return iterator(fake, head, fake);
}

}  // namespace s21