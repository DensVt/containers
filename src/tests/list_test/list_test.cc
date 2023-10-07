#include <list>

#include "../main_test.h"

TEST(ListConstructor, TestInt1) {
  s21::List<int> list({1, 2, 3});
  list.PushBack(1);
  list.PushBack(2);
  list.PushBack(3);

  EXPECT_TRUE(3 == list.Back());
}

TEST(ListConstructor, TestChar1) {
  s21::List<char> list;

  list.PushBack(65);
  list.PushBack(55);
  list.PushBack(48);

  EXPECT_TRUE(48 == list.Back());
}

TEST(ListConstructor, TestCopy1) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2(list1);

  EXPECT_TRUE(list1.Back() == list2.Back());
}

TEST(ListConstructor, TestMove1) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2(std::move(list1));

  EXPECT_TRUE(list2.Back() == 30);
  EXPECT_ANY_THROW(list1.Back());
}

TEST(ListConstructor, TestInit1) {
  s21::List<int> list = {99, 77, 30, 40};
  EXPECT_TRUE(list.Back() == 40);
}

TEST(ListOperator, TestCopy1) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2 = list1;

  EXPECT_TRUE(list1.Back() == list2.Back());
}

TEST(ListOperator, TestCopy2) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2;
  list2 = list1;

  EXPECT_TRUE(list1.Back() == list2.Back());
}

TEST(ListOperator, TestCopy3) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2;
  list2.PushBack(2);
  list2.PushBack(3);
  list2.PushBack(4);
  list2 = list1;

  EXPECT_TRUE(list1.Back() == list2.Back());
}

TEST(ListOperator, TestMove1) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2 = std::move(list1);

  EXPECT_TRUE(list2.Back() == 30);
  EXPECT_ANY_THROW(list1.Back());
}

TEST(ListOperator, TestMove2) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2;
  list2 = std::move(list1);

  EXPECT_TRUE(list2.Back() == 30);
  EXPECT_ANY_THROW(list1.Back());
  // EXPECT_TRUE(list1.Back() == 0);
}

TEST(ListOperator, TestMove3) {
  s21::List<int> list1;
  list1.PushBack(10);
  list1.PushBack(20);
  list1.PushBack(30);

  s21::List<int> list2;
  list2.PushBack(2);
  list2.PushBack(3);
  list2.PushBack(4);
  list2 = std::move(list1);

  EXPECT_TRUE(list2.Back() == 30);
  EXPECT_ANY_THROW(list1.Back());
}

TEST(ListMethods, TestPopBack1) {
  s21::List<int> list1 = {23, 2, 4, 7};

  list1.PopBack();

  EXPECT_TRUE(list1.Back() == 4);
}

TEST(ListMethods, TestPopBack2) {
  s21::List<int> list1 = {23};

  list1.PopBack();

  EXPECT_TRUE(list1.Empty());
}

TEST(ListMethods, TestPopBack3) {
  s21::List<int> list1 = {23};

  list1.PopBack();

  EXPECT_TRUE(list1.Empty());
  EXPECT_ANY_THROW(list1.PopBack());
}

TEST(ListMethods, TestPopFront1) {
  s21::List<int> list1 = {23, 2, 4, 7};

  list1.PopFront();

  EXPECT_TRUE(list1.Front() == 2);
}

TEST(ListMethods, TestPopFront2) {
  s21::List<int> list1 = {23};

  list1.PopFront();

  EXPECT_TRUE(list1.Empty());
}

TEST(ListMethods, TestPopFront3) {
  s21::List<int> list1 = {23};

  list1.PopFront();

  EXPECT_TRUE(list1.Empty());
  EXPECT_ANY_THROW(list1.PopFront());
}

TEST(ListMethods, TestPushFront1) {
  s21::List<int> list1 = {23, 2, 4, 7};

  list1.PushFront(77);

  EXPECT_TRUE(list1.Front() == 77);
}

TEST(ListMethods, TestSwap1) {
  s21::List<int> list1 = {23, 2, 4, 7};
  s21::List<int> list2 = {123, 68, 123, 789};

  list1.Swap(list2);

  EXPECT_TRUE(list1.Front() == 123);
  EXPECT_TRUE(list2.Front() == 23);
}

TEST(ListMethods, TestSwapNull2) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};
  s21::List<int> list2 = {};

  list1.Swap(list2);

  EXPECT_TRUE(list2.Back() == 6);
  EXPECT_ANY_THROW(list1.Front());
}

TEST(ListIterator, TestConst1) {
  s21::List<int> s21_list;
  s21::List<int>::const_iterator iter = s21_list.Begin();
  ++iter;
  EXPECT_TRUE(iter == s21_list.End());
  ++iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  --iter;
  EXPECT_TRUE(iter == s21_list.End());
  --iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  EXPECT_TRUE(s21_list.Begin() == s21_list.End());
  std::list<int> std_list;
  EXPECT_TRUE(std_list.begin() == std_list.end());
}

// TEST(ListIterator, TestConst2) {
//   s21::List<int> s21_list;
//   std::list<int> std_list;
//   auto std_iter = std_list.begin();
//   // std::list<int>::iterator std_iter();
//   s21::List<int>::iterator iter = s21_list.Begin();
//   *iter = 5;
//   *std_iter = 5;
//   std_list.push_back(55);
//   s21_list.PushBack(55);

//   EXPECT_TRUE(s21_list.Front() == std_list.front());
// }

TEST(ListIterator, TestPopBack2) {
  s21::List<int> s21_list = {1};
  s21_list.PopBack();
  auto iter = s21_list.Begin();
  ++iter;
  EXPECT_TRUE(iter == s21_list.End());
  ++iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  --iter;
  EXPECT_TRUE(iter == s21_list.End());
  --iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  EXPECT_TRUE(s21_list.Begin() == s21_list.End());
}

TEST(ListIterator, TestPopFront3) {
  s21::List<int> s21_list = {1};
  s21_list.PopFront();
  auto iter = s21_list.Begin();
  ++iter;
  EXPECT_TRUE(iter == s21_list.End());
  ++iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  --iter;
  EXPECT_TRUE(iter == s21_list.End());
  --iter;
  EXPECT_TRUE(iter == s21_list.Begin());
  EXPECT_TRUE(s21_list.Begin() == s21_list.End());
}

// TEST(ListIterator, TestConstructor1) { s21::List<int>::const_iterator it; }

TEST(ListIterator, TestEq1) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};

  typename s21::List<int>::iterator iter1 = list1.Begin();
  typename s21::List<int>::iterator iter2 = list1.Begin();

  EXPECT_TRUE(iter1 == iter2);
}

TEST(ListIterator, TestNonEq1) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};

  typename s21::List<int>::iterator iter1 = list1.Begin();
  typename s21::List<int>::iterator iter2 = list1.End();

  EXPECT_TRUE(iter1 != iter2);
}

TEST(ListIterator, TestChange1) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};
  typename s21::List<int>::iterator iter1 = list1.Begin();

  ++iter1;
  *iter1 = 23;

  EXPECT_TRUE(*iter1 == 23);
}

TEST(ListIterator, TestInsert1) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};
  std::list<int> list2 = {1, 2, 3, 5, 6};

  typename s21::List<int>::iterator iter1 = list1.Begin();
  auto iter2 = list2.begin();

  list1.Insert(iter1, 5);
  list2.insert(iter2, 5);

  EXPECT_TRUE(list1.Front() == list2.front());
}

TEST(ListIterator, TestInsert2) {
  s21::List<int> list1 = {1, 2, 3, 5, 6};
  std::list<int> list2 = {1, 2, 3, 5, 6};

  typename s21::List<int>::iterator iter1 = list1.Begin();
  auto iter2 = list2.begin();

  ++iter1;
  ++iter2;

  list1.Insert(iter1, 5);
  list2.insert(iter2, 5);

  EXPECT_TRUE(*iter1 == *iter2);

  iter1++;
  iter2++;

  EXPECT_TRUE(*iter1 == *iter2);
}

TEST(ListIterator, TestInsert3) {
  s21::List<int> list1 = {1, 2, 3, 5, 62};
  std::list<int> list2 = {1, 2, 3, 5, 6};

  typename s21::List<int>::iterator iter1 = list1.End();
  auto iter2 = list2.end();

  list2.insert(iter2, 77);

  list1.Insert(iter1, 77);

  EXPECT_TRUE(list1.Back() == list2.back());
}

TEST(ListIterator, TestInsert4) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.End();
  auto std_iter = std_list.end();

  s21_iter++;
  std_iter++;

  s21_list.Insert(s21_iter, 777);
  std_list.insert(std_iter, 777);

  EXPECT_TRUE(*s21_iter == *std_iter);
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestInsert5) {
  s21::List<int> s21_list;
  std::list<int> std_list;

  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();

  s21_list.Insert(s21_iter, 777);
  std_list.insert(std_iter, 777);

  EXPECT_TRUE(s21_list.Front() == std_list.front());

  ++s21_iter;
  ++std_iter;

  s21_list.Insert(s21_iter, 666);
  std_list.insert(std_iter, 666);

  EXPECT_TRUE(s21_list.Back() == std_list.back());
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestInsert6) {
  s21::List<int> s21_list = {1};
  std::list<int> std_list = {1};

  s21_list.PopBack();
  std_list.pop_back();

  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();

  s21_list.Insert(s21_iter, 777);
  std_list.insert(std_iter, 777);

  EXPECT_TRUE(s21_list.Front() == std_list.front());

  ++s21_iter;
  ++std_iter;

  s21_list.Insert(s21_iter, 666);
  std_list.insert(std_iter, 666);

  EXPECT_TRUE(s21_list.Back() == std_list.back());
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestInsert7) {
  s21::List<int> s21_list = {1};
  std::list<int> std_list = {1};

  s21_list.PopFront();
  std_list.pop_front();

  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();

  s21_list.Insert(s21_iter, 777);
  std_list.insert(std_iter, 777);

  EXPECT_TRUE(s21_list.Front() == std_list.front());

  ++s21_iter;
  ++std_iter;

  s21_list.Insert(s21_iter, 666);
  std_list.insert(std_iter, 666);

  EXPECT_TRUE(s21_list.Back() == std_list.back());
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestErase1) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();

  s21_list.Erase(s21_iter);
  std_list.erase(std_iter);

  ++s21_iter;
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestErase2) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();

  ++s21_iter;
  ++std_iter;

  s21_list.Erase(s21_iter);
  std_list.erase(std_iter);

  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListIterator, TestErase2_1) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.End();

  EXPECT_ANY_THROW(s21_list.Erase(s21_iter));
}

TEST(ListIterator, TestErase3) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.End();
  auto std_iter = std_list.end();

  s21_iter--;
  std_iter--;

  s21_list.Erase(s21_iter);
  std_list.erase(std_iter);

  EXPECT_TRUE(s21_list.Back() == std_list.back());
}

TEST(ListIterator, TestErase4) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  auto s21_iter = s21_list.End();
  auto std_iter = std_list.end();

  s21_iter--;
  std_iter--;

  s21_iter--;
  std_iter--;

  s21_list.Erase(s21_iter);
  std_list.erase(std_iter);

  auto s21_iter_1 = s21_list.End();
  auto std_iter_1 = std_list.end();

  s21_iter_1--;
  std_iter_1--;

  s21_iter_1--;
  std_iter_1--;

  EXPECT_TRUE(*s21_iter_1 == *std_iter_1);
}

TEST(ListIterator, TestErase5) {
  s21::List<int> s21_list = {12};
  auto s21_iter = s21_list.Begin();

  s21_list.Erase(s21_iter);
  EXPECT_TRUE(s21_list.Empty());
}

TEST(ListIteratorTests, IterAfterAppend1) {
  std::list<int> std_list;
  auto std_iter = std_list.begin();
  std_list.push_back(5);
  ++std_iter;

  s21::List<int> s21_list;
  auto s21_iter = s21_list.Begin();
  s21_list.PushBack(5);
  ++s21_iter;

  EXPECT_TRUE(*std_iter == *s21_iter);
}

TEST(ListIteratorTests, IterAfterDeletingList1) {
  std::list<int> *std_list = new std::list<int>({34, 50, 209, 23});
  s21::List<int> *s21_list = new s21::List<int>({34, 50, 209, 23});

  auto std_iter = std_list->begin();
  auto s21_iter = s21_list->Begin();

  delete std_list;
  delete s21_list;

  s21_list++;
  s21_list--;
  s21_list--;
}

TEST(ListIteratorTests, OutOfRangeFake1) {
  s21::List<int> s21_list = {82, 32, 12};
  auto s21_iter = s21_list.End();

  ++s21_iter;
  EXPECT_TRUE(s21_iter == s21_list.Begin());
}

TEST(ListIteratorTests, OutOfRangeHead1) {
  s21::List<int> s21_list = {82, 32, 12};
  auto s21_iter = s21_list.Begin();

  --s21_iter;
  EXPECT_TRUE(s21_iter == s21_list.End());
}
TEST(ListConstIterator, Test1) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  s21::List<int>::const_iterator const_iter = s21_list.Begin();

  std::list<int> std_list = {12, 2, 3, 5, 62};
  std::list<int>::const_iterator std_const = std_list.begin();

  ++const_iter;
  ++std_const;
  EXPECT_TRUE(*const_iter == *std_const);
}
TEST(ListCommon, TestReverse1) {
  s21::List<int> s21_list = {12, 2, 3, 5, 62};
  std::list<int> std_list = {12, 2, 3, 5, 62};

  s21_list.Reverse();
  std_list.reverse();

  EXPECT_TRUE(s21_list.Back() == std_list.back());
  EXPECT_TRUE(s21_list.Front() == std_list.front());
}

TEST(ListCommon, TestMerge1) {
  s21::List<int> s21_list_1 = {1, 2};
  s21::List<int> s21_list_2 = {4};

  std::list<int> std_list_1 = {1, 2};
  std::list<int> std_list_2 = {4};

  s21_list_1.Merge(s21_list_2);
  std_list_1.merge(std_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }

  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestMerge2) {
  s21::List<int> s21_list_1 = {4};
  s21::List<int> s21_list_2 = {1, 2};

  std::list<int> std_list_1 = {4};
  std::list<int> std_list_2 = {1, 2};

  s21_list_1.Merge(s21_list_2);
  std_list_1.merge(std_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }

  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestMerge3) {
  s21::List<int> s21_list_1;
  s21::List<int> s21_list_2 = {1, 2};

  std::list<int> std_list_1;
  std::list<int> std_list_2 = {1, 2};

  s21_list_1.Merge(s21_list_2);
  std_list_1.merge(std_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }

  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestMerge4) {
  s21::List<int> s21_list_1 = {1};
  s21::List<int> s21_list_2 = {1, 2};
  s21_list_1.PopBack();
  s21_list_1.Merge(s21_list_2);
}

TEST(ListCommon, TestMerge5) {
  s21::List<int> s21_list_1 = {1, 3};
  s21::List<int> s21_list_2;

  std::list<int> std_list_1 = {1, 3};
  std::list<int> std_list_2;

  s21_list_1.Merge(s21_list_2);
  std_list_1.merge(std_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }

  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestMerge6) {
  s21::List<int> s21_list_1 = {1, 3};
  s21::List<int> s21_list_2 = {2};
  s21_list_2.PopFront();
  s21_list_1.Merge(s21_list_2);
}

TEST(ListCommon, TestMerge7) {
  s21::List<int> s21_list_1 = {1, 5, 24, 35};
  s21::List<int> s21_list_2 = {2, 7, 20, 36};

  std::list<int> std_list_1 = {1, 5, 24, 35};
  std::list<int> std_list_2 = {2, 7, 20, 36};

  s21_list_1.Merge(s21_list_2);
  std_list_1.merge(std_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }

  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestMerge8) {
  s21::List<int> s21_list_1 = {4};
  s21::List<int> s21_list_2 = {2};
  s21::List<int> s21_list_3 = {2};
  s21_list_1.Merge(s21_list_2);
  s21_list_2.Merge(s21_list_3);
}

TEST(ListCommon, TestSort1) {
  s21::List<int> s21_list = {4, 2, 1, 3};
  std::list<int> std_list = {4, 2, 1, 3};
  s21_list.Sort();
  std_list.sort();
  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list.begin();
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
}

TEST(ListCommon, TestSplice1) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};
  s21::List<int> s21_list_2 = {7, 8, 9};

  std::list<int> std_list_1 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2 = {7, 8, 9};

  s21::List<int>::const_iterator iter = s21_list_1.Begin();
  auto std_iter_1 = std_list_1.begin();

  ++std_iter_1;
  ++std_iter_1;
  ++std_iter_1;

  ++iter;
  ++iter;
  ++iter;

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty());
}

TEST(ListCommon, TestSplice2) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};
  s21::List<int> s21_list_2 = {7, 8, 9};

  std::list<int> std_list_1 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2 = {7, 8, 9};

  s21::List<int>::const_iterator iter = s21_list_1.Begin();
  auto std_iter_1 = std_list_1.begin();

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestSplice3) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};
  s21::List<int> s21_list_2 = {7, 8, 9};

  std::list<int> std_list_1 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2 = {7, 8, 9};

  s21::List<int>::const_iterator iter = s21_list_1.End();
  auto std_iter_1 = std_list_1.end();
  --iter;
  --std_iter_1;

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestSplice4) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};
  s21::List<int> s21_list_2 = {7, 8, 9};

  std::list<int> std_list_1 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2 = {7, 8, 9};

  s21::List<int>::const_iterator iter = s21_list_1.End();
  auto std_iter_1 = std_list_1.end();

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestSplice5) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};
  s21::List<int> s21_list_2;

  std::list<int> std_list_1 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2;

  s21::List<int>::const_iterator iter = s21_list_1.End();
  auto std_iter_1 = std_list_1.end();

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestSplice6) {
  s21::List<int> s21_list_1;
  s21::List<int> s21_list_2 = {7, 8, 9};

  std::list<int> std_list_1;
  std::list<int> std_list_2 = {7, 8, 9};

  s21::List<int>::const_iterator iter = s21_list_1.End();
  auto std_iter_1 = std_list_1.end();

  std_list_1.splice(std_iter_1, std_list_2);
  s21_list_1.Splice(iter, s21_list_2);

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
  EXPECT_TRUE(s21_list_2.Empty() == std_list_2.empty());
}

TEST(ListCommon, TestSplice7) {
  s21::List<int> s21_list_1 = {1, 2, 3, 4, 5};

  auto s21_iter = s21_list_1.Begin();

  ++s21_iter;
  ++s21_iter;
  ++s21_iter;

  s21_list_1.Splice(s21_iter, s21_list_1);
  EXPECT_TRUE(s21_list_1.Empty() == 1);
  EXPECT_TRUE(s21_list_1.Size() == 0);
}

TEST(ListCommon, TestUnique1) {
  s21::List<int> s21_list_1 = {3, 4, 7, 10, 10, 12};
  std::list<int> std_list_1 = {3, 4, 7, 10, 10, 12};

  std_list_1.unique();
  s21_list_1.Unique();

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
}

TEST(ListCommon, TestUnique2) {
  s21::List<int> s21_list_1 = {3, 4, 10, 7, 10, 12};
  std::list<int> std_list_1 = {3, 4, 10, 7, 10, 12};

  std_list_1.unique();
  s21_list_1.Unique();

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();
  while (s21_iter != s21_list_1.End() && std_iter != std_list_1.end()) {
    EXPECT_TRUE(*s21_iter == *std_iter);
    ++std_iter;
    ++s21_iter;
  }
}

TEST(ListCommon, TestUniqueNull3) {
  s21::List<int> s21_list_1;
  std::list<int> std_list_1;

  std_list_1.unique();
  s21_list_1.Unique();

  auto s21_iter = s21_list_1.Begin();
  auto std_iter = std_list_1.begin();

  EXPECT_TRUE(s21_list_1.Empty() == std_list_1.empty());
}

TEST(ListCommon, MaxSize1) {
  s21::List<int> s21_list_1 = {1, 2, 3};
  std::list<int> std_list_1 = {1, 2, 3};
  auto max = s21_list_1.MaxSize();
  auto max1 = std_list_1.max_size();
  EXPECT_TRUE(max == max1);
}

TEST(ListCommon, MaxSize2) {
  s21::List<char> s21_list_1 = {1, 2, 3};
  std::list<char> std_list_1 = {1, 2, 3};
  auto max = s21_list_1.MaxSize();
  auto max1 = std_list_1.max_size();
  EXPECT_TRUE(max == max1);
}