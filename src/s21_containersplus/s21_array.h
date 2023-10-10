#ifndef CPP2_S21_CONTAINERS_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  // Определение типов
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Конструкторы и деструктор
  array();  // Конструктор по умолчанию
  array(std::initializer_list<value_type> const
            &items);  // Конструктор с инициализатором
  array(const array &a);      // Конструктор копирования
  array(array &&a) noexcept;  // Конструктор перемещения
  ~array() = default;         // Деструктор

  // Итераторы
  iterator begin();                   // начало массива
  iterator end();                     // конец массива
  const_iterator cbegin(void) const;  // начало массива (const)
  const_iterator cend(void) const;    // конец массива (const)

  // Доступ к элементам
  reference at(size_type pos);  // доступ по индексу с проверкой
  const_reference at(
      size_type pos) const;  // константный доступ по индексу с проверкой
  reference front();              // первый элемент
  reference back();               // последний элемент
  const_reference front() const;  // первый элемент (const)
  const_reference back() const;   // последний элемент (const)

  // Информация о массиве
  bool empty();          // пуст ли массив
  size_type size();      // размер массива
  size_type max_size();  // максимальный размер

  // Операции
  void swap(array &a);               // обмен массивов
  void fill(const_reference value);  // заполнение массива

  // Операторы
  array &operator=(const array &a);  // оператор присваивания
  array &operator=(array &&a) noexcept;  // оператор присваивания с перемещением
  reference operator[](size_type pos);  // доступ по индексу
  const_reference operator[](
      size_type pos) const;  // константный доступ по индексу

 private:
  // Хранилище элементов и размер
  value_type elems_[N] = {};
  size_type size_ = N;
};

}  // namespace s21

#include "s21_array.tpp"

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
