#include "s21_list.h"

namespace s21 {
template <class T>
List<T>::ListConstIterator::ListConstIterator(typename List::Node* ptr,
                                              typename List::Node* head,
                                              typename List::Node* fake)
    : ptr_(ptr), head_(head), fake_(fake){};

template <class T>
typename List<T>::ListConstIterator& List<T>::ListConstIterator::operator++() {
  if (ptr_ == fake_ && fake_) {
    ptr_ = fake_->next;
  } else if (ptr_) {
    ptr_ = ptr_->next;
  }
  return *this;
}

template <class T>
typename List<T>::ListConstIterator List<T>::ListConstIterator::operator++(
    value_type) {
  ListConstIterator tmp(*this);
  ++(*this);
  return tmp;
}

template <class T>
typename List<T>::ListConstIterator& List<T>::ListConstIterator::operator--() {
  if (ptr_ == fake_->next && fake_) {
    ptr_ = fake_;
  } else if (ptr_) {
    ptr_ = ptr_->prev;
  }
  return *this;
}

template <class T>
typename List<T>::ListConstIterator List<T>::ListConstIterator::operator--(
    value_type) {
  ListConstIterator tmp(*this);
  --(*this);
  return tmp;
}

template <class T>
bool List<T>::ListConstIterator::operator==(ListConstIterator o) const {
  return o.ptr_ == ptr_;
}

template <class T>
bool List<T>::ListConstIterator::operator!=(ListConstIterator o) const {
  return o.ptr_ != ptr_;
}

template <class T>
typename List<T>::const_reference List<T>::ListConstIterator::operator*()
    const {
  return ptr_->data;
}

template <class T>
void List<T>::ListConstIterator::Display() {
  std::cout << ptr_->data << "\n";
}
}  // namespace s21