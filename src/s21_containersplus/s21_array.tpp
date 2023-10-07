#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_TPP
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_TPP

namespace s21
{

  // Конструктор по умолчанию
  template <typename T, std::size_t N>
  array<T, N>::array() : size_(N) {}

  // Конструктор с инициализатором
  template <typename T, std::size_t N>
  array<T, N>::array(const std::initializer_list<value_type> &items)
  {
    std::copy(items.begin(), items.end(), elems_);
  }

  // Конструктор копирования
  template <typename T, std::size_t N>
  array<T, N>::array(const array<T, N> &a)
  {
    std::copy(a.elems_, a.elems_ + N, elems_);
  }

  // Конструктор перемещения
  template <typename T, std::size_t N>
  array<T, N>::array(array<T, N> &&a) noexcept
  {
    std::move(a.elems_, a.elems_ + N, elems_);
  }

  // Итератор на начало массива
  template <typename T, std::size_t N>
  typename array<T, N>::iterator array<T, N>::begin()
  {
    return elems_;
  }

  // Итератор на конец массива
  template <typename T, std::size_t N>
  typename array<T, N>::iterator array<T, N>::end()
  {
    return elems_ + size_;
  }

  // Константный итератор на начало массива
  template <typename T, std::size_t N>
  typename array<T, N>::const_iterator array<T, N>::cbegin() const
  {
    return elems_;
  }

  // Константный итератор на конец массива
  template <typename T, std::size_t N>
  typename array<T, N>::const_iterator array<T, N>::cend() const
  {
    return elems_ + size_;
  }

  // Доступ к элементу по индексу с проверкой
  template <typename T, std::size_t N>
  typename array<T, N>::reference array<T, N>::at(size_type pos)
  {
    return (*this)[pos];
  }

  // Константный доступ к элементу по индексу с проверкой
  template <typename T, std::size_t N>
  typename array<T, N>::const_reference array<T, N>::at(size_type pos) const
  {
    return (*this)[pos];
  }

  // Доступ к первому элементу массива
  template <typename T, std::size_t N>
  typename array<T, N>::reference array<T, N>::front()
  {
    return elems_[0];
  }

  // Доступ к последнему элементу массива
  template <typename T, std::size_t N>
  typename array<T, N>::reference array<T, N>::back()
  {
    return elems_[N - 1];
  }

  // Константный доступ к первому элементу массива
  template <typename T, std::size_t N>
  typename array<T, N>::const_reference array<T, N>::front() const
  {
    return elems_[0];
  }

  // Константный доступ к последнему элементу массива
  template <typename T, std::size_t N>
  typename array<T, N>::const_reference array<T, N>::back() const
  {
    return elems_[N - 1];
  }

  // Проверка на пустоту массива
  template <typename T, std::size_t N>
  bool array<T, N>::empty()
  {
    return !size_;
  }

  // Получение размера массива
  template <typename T, std::size_t N>
  typename array<T, N>::size_type array<T, N>::size()
  {
    return size_;
  }

  // Получение максимального размера массива
  template <typename T, std::size_t N>
  typename array<T, N>::size_type array<T, N>::max_size()
  {
    return size();
  }

  // Обмен содержимого массивов
  template <typename T, std::size_t N>
  void array<T, N>::swap(array<T, N> &a)
  {
    std::swap_ranges(elems_, elems_ + N, a.elems_);
  }

  // Заполнение массива одним значением
  template <typename T, std::size_t N>
  void array<T, N>::fill(const_reference value)
  {
    std::fill(elems_, elems_ + N, value);
  }

  // Оператор присваивания
  template <typename T, std::size_t N>
  typename array<T, N>::array &array<T, N>::operator=(const array<T, N> &a)
  {
    std::copy(a.elems_, a.elems_ + N, elems_);

    return *this;
  }

  // Оператор присваивания с перемещением
  template <typename T, std::size_t N>
  typename array<T, N>::array &array<T, N>::operator=(array<T, N> &&a) noexcept
  {
    for (size_t i = 0; i < N; ++i)
    {
      elems_[i] = std::move(a.elems_[i]);
    }

    return *this;
  }

  // Оператор доступа по индексу с проверкой
  template <typename T, std::size_t N>
  typename array<T, N>::reference array<T, N>::operator[](size_type pos)
  {
    if (pos >= N)
    {
      throw std::out_of_range("OutOfRangeError: Индекс ошибки выходит за пределы диапазона массива");
    }

    return elems_[pos];
  }

  // Константный оператор доступа по индексу с проверкой
  template <typename T, std::size_t N>
  typename array<T, N>::const_reference array<T, N>::operator[](
      size_type pos) const
  {
    if (pos >= N)
    {
      throw std::out_of_range("OutOfRangeError: Индекс ошибки выходит за пределы диапазона массива");
    }

    return elems_[pos];
  }

} // namespace s21

#endif
