namespace s21 {
template <class T>
void List<T>::CopyList(const List& o) {
  Node* sourceNode = o.head;
  while (sourceNode != o.fake && sourceNode != nullptr) {
    this->PushBack(sourceNode->data);
    sourceNode = sourceNode->next;
  }
  this->FakeMerge();
  size = o.size;
}

template <class T>
List<T>::List() : tail(nullptr), size(0) {
  fake = new Node();
  head = fake;
  fake->next = head;
}

template <class T>
List<T>::List(std::initializer_list<value_type> const& items)
    : tail(nullptr), size(0) {
  fake = new Node();
  head = fake;
  for (auto i = items.begin(); i != items.end(); i++) {
    this->PushBack(*i);
  }
}

template <class T>
List<T>::List(const List& o) : tail(nullptr), size(0) {
  fake = new Node();
  head = fake;
  this->CopyList(o);
}

template <class T>
List<T>::List(List&& o) : tail(nullptr), size(0) {
  fake = new Node();
  head = fake;
  this->CopyList(o);
  o.~List();
}

template <class T>
List<T>& List<T>::operator=(const List& o) {
  if (this != &o) {
    this->Clear();
    this->CopyList(o);
  }
  return *this;
}

template <class T>
List<T>& List<T>::operator=(List&& o) noexcept {
  if (this != &o) {
    *this = o;
    o.~List();
  }
  return *this;
}

template <class T>
List<T>::~List() {
  this->Clear();
  if (fake) {
    delete fake;
  }
  fake = nullptr;
  head = nullptr;
}

template <class T>
void List<T>::Clear() {
  while (!this->Empty()) {
    this->PopBack();
  }
  tail = nullptr;
  head = fake;
  if (fake) {
    fake->prev = tail;
  }
}
}  // namespace s21