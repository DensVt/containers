// Объявление пространства имён s21 для изоляции кода
namespace s21 {

// Реализация шаблонного класса Vector
template <typename value_type>

// Конструктор по умолчанию
Vector<value_type>::Vector() : size_(0), capacity_(0), data_(nullptr) {}

// Конструктор с заданным размером
template <typename value_type>
Vector<value_type>::Vector(size_type n) {
  // Проверка на превышение максимального размера
  if (n > max_size()) {
    throw std::length_error(
        "Невозможно создать s21::Vector больше максимального размера()");
  }
  size_ = n;
  capacity_ = n;
  // Выделение памяти под данные
  data_ = new value_type[capacity_];
}

// Конструктор с инициализацией через список
template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const &items)
    : size_(items.size()),
      capacity_(items.size()),
      data_(new value_type[capacity_]) {
  // Копирование элементов из списка инициализаторов
  std::copy(items.begin(), items.end(), data_);
}

// Конструктор копирования
template <typename value_type>
Vector<value_type>::Vector(const Vector &v)
    : size_(v.size_), capacity_(v.capacity_), data_(new value_type[capacity_]) {
  // Копирование данных из другого Vector
  for (size_type i = 0; i < size_; i++) {
    data_[i] = v.data_[i];
  }
}

// Конструктор перемещения
template <typename value_type>
Vector<value_type>::Vector(Vector &&v)
    : size_(v.size_), capacity_(v.capacity_), data_(v.data_) {
  // Обнуление состояния исходного объекта
  v.bring_to_zero();
}

// Деструктор
template <typename value_type>
Vector<value_type>::~Vector() {
  remove();
}

// Операторы присваивания

// Присваивание копированием
template <typename value_type>
typename s21::Vector<value_type> &Vector<value_type>::operator=(
    const Vector &v) {
  if (this != &v) {
    // Освобождение текущих данных
    remove();
    size_ = v.size_;
    capacity_ = v.capacity_;
    // Выделение памяти и копирование данных
    data_ = new value_type[capacity_];
    for (size_type i = 0; i < size_; i++) {
      data_[i] = v.data_[i];
    }
  }
  return *this;
}

// Присваивание перемещением
template <typename value_type>
typename s21::Vector<value_type> &Vector<value_type>::operator=(Vector &&v) {
  if (this != &v) {
    // Освобождение текущих данных
    remove();
    size_ = v.size_;
    capacity_ = v.capacity_;
    data_ = v.data_;
    // Обнуление состояния исходного объекта
    v.bring_to_zero();
  }
  return *this;
}

// Доступ к элементам

// Доступ с проверкой границ
template <typename value_type>
typename Vector<value_type>::reference_type Vector<value_type>::at(
    size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("Индекс выходит за пределы диапазона");
  }
  return data_[pos];
}

// Доступ без проверки границ
template <typename value_type>
typename Vector<value_type>::reference_type Vector<value_type>::operator[](
    size_type pos) {
  return data_[pos];
}

// Доступ к первому элементу
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() {
  return *data_;
}

// Доступ к последнему элементу
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() {
  return *(data_ + size_ - 1);
}

// Получение указателя на данные
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::data() {
  return data_;
}

// Итераторы

// Итератор на начало
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
  return iterator(data_);
}

// Итератор на конец
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
  return iterator(data_ + size_);
}

// Информация о ёмкости

// Проверка на пустоту
template <typename value_type>
bool Vector<value_type>::empty() {
  return (size_ == 0);
}

// Получение размера
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() {
  return size_;
}

// Получение максимального размера
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() {
  int bits = 63;
  if (sizeof(void *) == 4) {
    bits = 31;
  }
  return static_cast<size_type>(pow(2, bits)) / sizeof(value_type) - 1;
}

// Изменение ёмкости вектора
template <typename value_type>
void Vector<value_type>::reserve(size_type size) {
  // Проверка на превышение максимального размера
  if (size > max_size()) {
    throw std::length_error("Размер слишком большой");
  }
  // Если новая ёмкость больше текущего размера, выделяем новую память
  if (size > size_) {
    allocate(size);
  }
}

// Получение текущей ёмкости вектора
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() {
  return capacity_;
}

// Уменьшение ёмкости до текущего размера
template <typename value_type>
void Vector<value_type>::shrink_to_fit() {
  if (size_ < capacity_) {
    allocate(size_);
  }
}

// Очистка вектора
template <typename value_type>
void Vector<value_type>::clear() {
  size_ = 0;
}

// Вставка элемента в позицию pos
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(
    iterator pos, const_reference value) {
  // Определение индекса позиции
  size_type position = &(*pos) - data_;
  size_type zero = 0;
  // Проверка границ
  if (position < zero || position > size_) {
    throw std::out_of_range("Индекс выходит за пределы диапазона");
  }
  // Проверка ёмкости и выделение памяти при необходимости
  if (size_ + 1 >= capacity_) {
    allocate(size_ * 2);
  }
  // Вставка элемента
  value_type replace = data_[position];
  size_++;
  data_[position] = value;
  for (size_type i = position + 1; i < size_; ++i) {
    value_type next = data_[i];
    data_[i] = replace;
    replace = next;
  }
  return data_ + position;
}

// Удаление элемента на позиции pos
template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  // Определение индекса позиции
  size_type position = &(*pos) - data_;
  size_type zero = 0;
  if (position < zero || position > size_) {
    throw std::out_of_range("Индекс выходит за пределы диапазона");
  }
  // Удаление элемента
  for (size_type i = position + 1; i < size_; i++) {
    data_[i - 1] = data_[i];
  }
  size_--;
}

// Добавление элемента в конец вектора
template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  // Проверка ёмкости и выделение памяти при необходимости
  if (size_ >= capacity_) {
    if (!size_) {
      allocate(1);
    } else {
      allocate(size_ * 2);
    }
  }
  // Добавление элемента
  data_[size_++] = value;
}

// Удаление последнего элемента
template <typename value_type>
void Vector<value_type>::pop_back() {
  if (size_ > 0) {
    size_--;
  }
}

// Обмен значений с другим вектором
template <typename value_type>
void Vector<value_type>::swap(Vector &other) {
  using std::swap;
  swap(size_, other.size_);
  swap(capacity_, other.capacity_);
  swap(data_, other.data_);
}

// Вспомогательные методы

// Выделение новой памяти с заданной ёмкостью
template <typename value_type>
void Vector<value_type>::allocate(size_type new_cap) {
  value_type *new_data = new value_type[new_cap];
  for (size_type i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  data_ = new_data;
  capacity_ = new_cap;
}

// Обнуление всех полей вектора
template <typename value_type>
void Vector<value_type>::bring_to_zero() {
  size_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

// Очистка памяти и обнуление полей
template <typename value_type>
void Vector<value_type>::remove() {
  delete[] this->data_;
  bring_to_zero();
}

}  // namespace s21
