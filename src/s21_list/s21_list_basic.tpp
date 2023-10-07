namespace s21 {
template <class T>
typename List<T>::const_reference List<T>::Back() const {
  this->NullException();
  return tail->data;
}

template <class T>
typename List<T>::const_reference List<T>::Front() const {
  this->NullException();
  return head->data;
}

template <class T>
typename List<T>::size_type List<T>::Size() const {
  return size;
}

template <class T>
typename List<T>::size_type List<T>::MaxSize() const {
  size_type MaxSize = std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
  return MaxSize;
}

template <class T>
void List<T>::FakeMerge() {
  if (tail) {
    tail->next = fake;
  }
  fake->prev = tail;
  fake->next = head;
}

template <class T>
void List<T>::InitList(const_reference value) {
  Node* newNode = new Node(value);
  tail = newNode;
  head = tail;
  head->prev = nullptr;
  this->FakeMerge();
}

template <class T>
void List<T>::ListToNull() {
  tail = nullptr;
  head = fake;
  if (fake) {
    fake->next = head;
  }
  size = 0;
}

template <class T>
bool List<T>::Empty() const {
  bool output = false;
  if (tail == nullptr) {
    output = true;
  }
  return output;
}

template <class T>
typename List<T>::iterator List<T>::Insert(iterator pos,
                                           const_reference value) {
  if (pos == this->Begin()) {
    this->PushFront(value);
  } else if (pos == this->End()) {
    this->PushBack(value);
  } else {
    Node* curr = pos.ptr_;
    Node* newNode = new Node(value);
    newNode->next = pos.ptr_;
    newNode->prev = pos.ptr_->prev;
    pos.ptr_->prev->next = newNode;
    pos.ptr_->prev = newNode;
  }
  size += 1;
  return ++pos;
}

template <class T>
void List<T>::Erase(iterator pos) {
  if (pos == Begin()) {
    PopFront();
  } else if (pos.ptr_ == tail) {
    PopBack();
  } else if (pos == End()) {
    throw std::out_of_range("Erasing fake node is forbidden!");
  } else {
    Node* tmpPrev = pos.ptr_->prev;
    Node* tmpNext = pos.ptr_->next;
    tmpPrev->next = tmpNext;
    tmpNext->prev = tmpPrev;
    delete pos.ptr_;
  }
  size -= 1;
}

template <class T>
void List<T>::PushBack(const_reference value) {
  if (!tail) {
    this->InitList(value);
  } else {
    Node* newNode = new Node(value);
    newNode->prev = tail;
    tail->next = newNode;
    tail = tail->next;
    this->FakeMerge();
  }
  size += 1;
}

template <class T>
void List<T>::PopBack() {
  this->NullException();
  Node* tmp = tail;
  tail = tail->prev;
  if (tail) {
    tail->next = fake;
  } else {
    head = fake;
    fake->next = head;
  }
  fake->prev = tail;
  delete tmp;
  size -= 1;
}

template <class T>
void List<T>::PushFront(const_reference value) {
  if (!tail) {
    this->InitList(value);
  } else {
    Node* newNode = new Node(value);
    newNode->prev = nullptr;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    fake->next = head;
  }
  size += 1;
}

template <class T>
void List<T>::PopFront() {
  this->NullException();
  Node* tmp = head;
  head = head->next;
  if (head != fake) {
    head->prev = nullptr;
  } else {
    tail = nullptr;
  }
  fake->next = head;
  delete tmp;
  size -= 1;
}

template <class T>
void List<T>::Swap(List& o) {
  if (this != &o) {
    List<T> buff_this = *this;
    List<T> buff_o = o;
    this->Clear();
    o.Clear();
    this->CopyList(buff_o);
    o.CopyList(buff_this);
  }
}

template <class T>
void List<T>::Reverse() {
  Node* curr = tail;
  Node* tmp = tail->prev;
  while (curr != nullptr) {
    tmp = curr->prev;
    curr->prev = curr->next;
    curr->next = tmp;
    curr = curr->next;
  }
  tmp = tail;
  tail = head;
  head = tmp;
  if (head) {
    head->prev = nullptr;
  }
  FakeMerge();
}

template <class T>
void List<T>::Merge(List& o) {
  if (this != &o) {
    typename List::iterator left = Begin();
    typename List::iterator right = o.Begin();

    if (*left > *right) {
      head = right.ptr_;
      if (o.tail == nullptr) {
        head = left.ptr_;
        ++left;
      }
      ++right;
    } else {
      head = left.ptr_;
      if (tail == nullptr) {
        head = right.ptr_;
        ++right;
      }
      ++left;
    }

    head->prev = nullptr;
    typename List::iterator curr(head, head, fake);

    while (left != End() && right != o.End()) {
      if (*left > *right) {
        RightP(right, curr);
        ++right;
      } else {
        LeftP(left, curr);
        ++left;
      }
      curr.ptr_ = curr.ptr_->next;
    }

    while (right != o.End()) {
      RightP(right, curr);
      curr.ptr_ = curr.ptr_->next;
      ++right;
    }
    while (left != End()) {
      LeftP(left, curr);
      curr.ptr_ = curr.ptr_->next;
      ++left;
    }
    tail = curr.ptr_;

    o.ListToNull();
    FakeMerge();
  }
}

template <class T>
void List<T>::LeftP(iterator left, iterator curr) {
  curr.ptr_->next = left.ptr_;
  left.ptr_->prev = curr.ptr_;
}

template <class T>
void List<T>::RightP(iterator right, iterator curr) {
  curr.ptr_->next = right.ptr_;
  right.ptr_->prev = curr.ptr_;
}

template <class T>
void List<T>::Sort() {
  if (head != fake && head->next != fake) {
    List<T>* left = new List<T>;
    List<T>* right = new List<T>;

    left->head = head;
    right->head = GetMid();
    left->tail = right->head;
    auto tmp = right->head->next;
    right->head = tmp;
    right->tail = tail;
    left->FakeMerge();
    right->FakeMerge();

    left->Sort();
    right->Sort();

    left->Merge(*right);

    head = left->head;
    tail = left->tail;
    FakeMerge();

    left->ListToNull();

    delete right;
    delete left;
  }
}

template <class T>
typename List<T>::Node* List<T>::GetMid() {
  typename List<T>::iterator slow = Begin();
  typename List<T>::iterator fast = Begin();
  ++fast;
  while (fast != End() && ++fast != End()) {
    ++slow;
    ++fast;
  }
  return slow.ptr_;
}

template <class T>
void List<T>::Splice(const_iterator pos, List<T>& o) {
  if (this == &o) {
    this->Clear();
  } else if (!o.Empty()) {
    Node* tmp = pos.ptr_->prev;
    if (tmp) {
      tmp->next = o.head;
      o.head->prev = tmp;
    } else {
      head = o.head;
    }
    o.tail->next = pos.ptr_;
    pos.ptr_->prev = o.tail;
    if (pos == End()) {
      tail = o.tail;
      FakeMerge();
    }
    o.ListToNull();
  }
}

template <class T>
void List<T>::Unique() {
  typename List<T>::iterator slow = Begin();
  typename List<T>::iterator fast = Begin();
  typename List<T>::iterator tmp = Begin();
  ++fast;
  while (fast != End()) {
    if (*slow == *fast) {
      tmp = fast;
      ++fast;
      Erase(tmp);
    } else {
      ++fast;
      ++slow;
    }
  }
}

template <class T>
void List<T>::Display() {
  Node* current = head;
  std::cout << "nullptr";
  while (current != fake && current != nullptr) {
    std::cout << ">" << current->data;
    current = current->next;
  }
  std::cout << "\n";
}
}  // namespace s21