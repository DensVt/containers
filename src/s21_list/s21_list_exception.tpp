namespace s21 {
template <class T>
void List<T>::NullException() const {
  if (this->Empty()) {
    throw std::out_of_range("List is NULL");
  }
}
}  // namespace s21