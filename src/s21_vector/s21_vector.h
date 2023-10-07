#ifndef CPP2_S21_CONTAINERS_SRC_S21_VECTOR_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_SRC_S21_VECTOR_VECTOR_S21_VECTOR_H_

// Библиотеки для математических функций и списков инициализации
#include <cmath>
#include <initializer_list>
#include <iostream>

// Объявление пространства имен s21
namespace s21
{
  // Объявление предварительных классов для итераторов
  template <typename T>
  class VectorIterator;
  template <typename T>
  class VectorConstIterator;

  // Основной класс Vector
  template <typename T>
  class Vector
  {
  public:
    // Типы данных, используемые в классе Vector
    using value_type = T;
    using reference_type = T &;
    using const_reference = const T &;
    using iterator = VectorIterator<T>;
    using const_iterator = VectorConstIterator<T>;
    using size_type = std::size_t;

    // Конструкторы и деструктор
    Vector();
    Vector(size_type n);
    Vector(std::initializer_list<value_type> const &items);
    Vector(const Vector &v);
    Vector(Vector &&v);
    ~Vector();

    // Операторы присваивания
    Vector &operator=(const Vector &v);
    Vector &operator=(Vector &&v);

    // Доступ к элементам
    reference_type at(size_type pos);
    reference_type operator[](size_type pos);
    const_reference front();
    const_reference back();
    iterator data();

    // Итераторы
    iterator begin();
    iterator end();

    // Информация о вместимости
    bool empty();
    size_type size();
    size_type max_size();
    void reserve(size_type size);
    size_type capacity();
    void shrink_to_fit();

    // Модификация вектора
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void swap(Vector &other);

  private:
    // Приватные переменные класса
    size_type size_;
    size_type capacity_;
    value_type *data_;

    // Вспомогательные функции
    void allocate(size_type new_cap);
    void bring_to_zero();
    void remove();
  };

  // Класс для итератора Vector
  template <typename T>
  class VectorIterator
  {
    friend class Vector<T>;
    friend class VectorConstIterator<T>;

  public:
    // Типы данных для итератора
    using value_type = T;
    using pointer_type = T *;
    using reference_type = T &;

    // Конструкторы для итератора
    VectorIterator() : ptr_(){};
    VectorIterator(pointer_type ptr) : ptr_(ptr) {}

    // Перегрузка операторов для инкремента
    VectorIterator &operator++()
    {
      ptr_++;
      return *this;
    }

    VectorIterator operator++(int)
    {
      VectorIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    // и для декремента
    VectorIterator &operator--()
    {
      ptr_--;
      return *this;
    }

    VectorIterator operator--(int)
    {
      VectorIterator tmp = *this;
      --(*this);
      return tmp;
    }

    // Операторы для сложения и вычитания
    VectorIterator operator+(const size_t value)
    {
      VectorIterator tmp(this->ptr_ + value);
      return tmp;
    }

    VectorIterator operator-(const size_t value)
    {
      VectorIterator tmp(this->ptr_ - value);
      return tmp;
    }

    // Операторы сравнения
    bool operator==(const VectorIterator &other) const
    {
      return ptr_ == other.ptr_;
    }

    bool operator!=(const VectorIterator &other) const
    {
      return ptr_ != other.ptr_;
    }

    // Операторы разыменования и доступа к членам
    reference_type operator*() const { return (*ptr_); }
    pointer_type operator->() { return ptr_; }

    // Преобразование типа к VectorConstIterator
    operator VectorConstIterator<T>() const
    {
      return VectorConstIterator<T>(ptr_);
    }

  private:
    // Указатель на текущий элемент
    pointer_type ptr_;
  };

  template <typename T>
  class VectorConstIterator
  {
    friend class Vector<T>;
    friend class VectorIterator<T>;

  public:
    // Определение типов для удобства
    using value_type = T;
    using pointer_type = T *;
    using reference_type = T &;

    // Конструкторы
    VectorConstIterator() : ptr_(){};                    // Конструктор по умолчанию
    VectorConstIterator(pointer_type ptr) : ptr_(ptr) {} // Конструктор с параметром

    // Операторы инкремента и декремента
    VectorConstIterator &operator++()
    {
      ptr_++;
      return *this;
    }

    VectorConstIterator operator++(int)
    {
      VectorConstIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    VectorConstIterator &operator--()
    {
      ptr_--;
      return *this;
    }

    VectorConstIterator operator--(int)
    {
      VectorConstIterator tmp = *this;
      --(*this);
      return tmp;
    }

    // Операторы сравнения
    bool operator==(const VectorConstIterator &other)
    {
      return ptr_ == other.ptr_;
    }

    bool operator!=(const VectorConstIterator &other)
    {
      return ptr_ != other.ptr_;
    }

    // Операторы разыменования и доступа к членам
    reference_type operator*() const { return (*ptr_); }
    pointer_type operator->() { return ptr_; }

    // Преобразование типа в VectorIterator
    operator VectorIterator<T>() const { return VectorIterator<T>(ptr_); }

  private:
    // Указатель на текущий элемент
    pointer_type ptr_;
  };
} // namespace s21

#include "s21_vector.tpp"

#endif // CPP2_S21_CONTAINERS_SRC_S21_VECTOR_VECTOR_S21_VECTOR_H_
