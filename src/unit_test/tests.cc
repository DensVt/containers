#include <gtest/gtest.h>

#include <vector>
#include <array>
#include "../s21_containers.h"
#include "../s21_containersplus.h"


TEST(VectorTest, constructor_default_size) {
  s21::Vector<char> test_vector;
  std::vector<char> std_test_vector;
  EXPECT_EQ(std_test_vector.size(), test_vector.size());
}

TEST(VectorTest, constructor_default_capacity) {
  s21::Vector<char> test_vector;
  std::vector<char> std_test_vector;
  EXPECT_EQ(std_test_vector.capacity(), test_vector.capacity());
}

TEST(VectorTest, constructor_default_capacity_1) {
  s21::Vector<char> test_vector;
  std::vector<char> std_test_vector;
  test_vector.push_back(1);
  std_test_vector.push_back(1);
  EXPECT_EQ(std_test_vector.capacity(), test_vector.capacity());
}

TEST(VectorTest, constructor_parametrized) {
  s21::Vector<int> test_vector(5);
  std::vector<int> std_test_vector(5);
  EXPECT_EQ(std_test_vector.size(), test_vector.size());
}

TEST(VectorTest, constructor_initializer_list) {
  std::initializer_list<int> il1{1, 2, 3, 4, 5};
  s21::Vector<int> test_vector(il1);
  std::vector<int> std_test_vector(il1);
  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
  EXPECT_EQ(test_vector.at(3), std_test_vector.at(3));
  EXPECT_EQ(test_vector.at(4), std_test_vector.at(4));
}

TEST(VectorTest, constructor_copy) {
  std::initializer_list<int> il1{1, 2, 3, 4, 5};
  s21::Vector<int> test_vector(il1);
  s21::Vector<int> copy_vector(test_vector);
  std::vector<int> std_test_vector(il1);
  std::vector<int> std_copy_vector(std_test_vector);
  EXPECT_EQ(copy_vector.at(0), std_copy_vector.at(0));
  EXPECT_EQ(copy_vector.at(1), std_copy_vector.at(1));
  EXPECT_EQ(copy_vector.at(2), std_copy_vector.at(2));
  EXPECT_EQ(copy_vector.at(3), std_copy_vector.at(3));
  EXPECT_EQ(copy_vector.at(4), std_copy_vector.at(4));
}

TEST(VectorTest, constructor_move) {
  std::initializer_list<int> il1{1, 2, 3, 4, 5};
  s21::Vector<int> test_vector(il1);
  s21::Vector<int> copy_vector(std::move(test_vector));
  std::vector<int> std_test_vector(il1);
  std::vector<int> std_copy_vector(std::move(std_test_vector));
  EXPECT_EQ(copy_vector.at(0), std_copy_vector.at(0));
  EXPECT_EQ(copy_vector.at(1), std_copy_vector.at(1));
  EXPECT_EQ(copy_vector.at(2), std_copy_vector.at(2));
  EXPECT_EQ(copy_vector.at(3), std_copy_vector.at(3));
  EXPECT_EQ(copy_vector.at(4), std_copy_vector.at(4));
}

TEST(VectorTest, constructor_operator) {
  s21::Vector<int> test_vector_1 = {1, 2, 3, 4, 5};
  s21::Vector<int> test_vector_2;
  test_vector_2 = std::move(test_vector_1);
  std::vector<int> std_test_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector_2.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector_2.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector_2.at(2), std_test_vector.at(2));
  EXPECT_EQ(test_vector_2.at(3), std_test_vector.at(3));
  EXPECT_EQ(test_vector_2.at(4), std_test_vector.at(4));
}

TEST(VectorTest, at_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
  EXPECT_EQ(test_vector.at(3), std_test_vector.at(3));
  EXPECT_EQ(test_vector.at(4), std_test_vector.at(4));
}

TEST(VectorTest, at_func_throw) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  EXPECT_ANY_THROW(test_vector.at(1));
  EXPECT_ANY_THROW(std_test_vector.at(1));
}

TEST(VectorTest, square_brackets_operator) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
  EXPECT_EQ(test_vector.at(3), std_test_vector.at(3));
  EXPECT_EQ(test_vector.at(4), std_test_vector.at(4));
}

TEST(VectorTest, front_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.front(), std_test_vector.front());
}

TEST(VectorTest, back_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.back(), std_test_vector.back());
}

TEST(VectorTest, data_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(*test_vector.data(), *std_test_vector.data());
}

TEST(VectorTest, empty) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  EXPECT_EQ(test_vector.empty(), std_test_vector.empty());
}

TEST(VectorTest, size_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.size(), std_test_vector.size());
}

TEST(VectorTest, max_size_func) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;

  EXPECT_EQ(test_vector.max_size(), std_test_vector.max_size());
}

TEST(VectorTest, reserve_func) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  test_vector.reserve(10);
  std_test_vector.reserve(10);
  EXPECT_EQ(test_vector.capacity(), std_test_vector.capacity());
}

TEST(VectorTest, reserve_func_1) {
  s21::Vector<int> test_vector(10);
  std::vector<int> std_test_vector(10);
  test_vector.reserve(2);
  std_test_vector.reserve(2);
  EXPECT_EQ(test_vector.capacity(), std_test_vector.capacity());
}

TEST(VectorTest, reserve_func_except) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  EXPECT_THROW(test_vector.reserve(2305843009213693952), std::length_error);
  EXPECT_THROW(std_test_vector.reserve(2305843009213693952), std::length_error);
}

TEST(VectorTest, capacity_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.capacity(), std_test_vector.capacity());
}

TEST(VectorTest, shrink_to_fit_func) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  test_vector.reserve(10);
  std_test_vector.reserve(10);
  test_vector.shrink_to_fit();
  std_test_vector.shrink_to_fit();
  EXPECT_EQ(test_vector.capacity(), std_test_vector.capacity());
}

TEST(VectorTest, clear_func) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;
  test_vector.clear();
  std_test_vector.clear();
  EXPECT_EQ(test_vector.size(), std_test_vector.size());
}

TEST(VectorTest, insert_func) {
  s21::Vector<int> test_vector{1, 2, 3};
  std::vector<int> std_test_vector{1, 2, 3};
  test_vector.insert(test_vector.begin() + 1, 5);
  std_test_vector.insert(std_test_vector.begin() + 1, 5);

  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
}

TEST(VectorTest, erase_func) {
  s21::Vector<int> test_vector{1, 2, 3, 4};
  std::vector<int> std_test_vector{1, 2, 3, 4};

  test_vector.erase(test_vector.begin() + 1);
  std_test_vector.erase(std_test_vector.begin() + 1);

  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
}

TEST(VectorTest, push_back_func) {
  s21::Vector<int> test_vector;
  std::vector<int> std_test_vector;

  test_vector.push_back(2);
  test_vector.push_back(3);
  test_vector.push_back(4);
  test_vector.push_back(5);

  std_test_vector.push_back(2);
  std_test_vector.push_back(3);
  std_test_vector.push_back(4);
  std_test_vector.push_back(5);

  EXPECT_EQ(test_vector.at(0), std_test_vector.at(0));
  EXPECT_EQ(test_vector.at(1), std_test_vector.at(1));
  EXPECT_EQ(test_vector.at(2), std_test_vector.at(2));
  EXPECT_EQ(test_vector.at(3), std_test_vector.at(3));
}

TEST(VectorTest, pop_back_func) {
  s21::Vector<int> test_vector{1, 2};

  test_vector.pop_back();
  test_vector.pop_back();
  test_vector.pop_back();
  test_vector.pop_back();

  EXPECT_EQ(test_vector.size(), 0);
  EXPECT_EQ(test_vector.capacity(), 2);
}

TEST(VectorTest, swap_func) {
  s21::Vector<int> test_vector;
  s21::Vector<int> test_vector_copy;

  std::vector<int> std_test_vector;
  std::vector<int> std_test_vector_copy;

  test_vector_copy.swap(test_vector);
  std_test_vector_copy.swap(std_test_vector);

  EXPECT_EQ(test_vector.size(), std_test_vector.size());
  EXPECT_EQ(test_vector.capacity(), std_test_vector.capacity());

  EXPECT_EQ(test_vector_copy.size(), std_test_vector_copy.size());
  EXPECT_EQ(test_vector_copy.capacity(), std_test_vector_copy.capacity());
}

TEST(VectorTest, iterator_operator_minus_minus) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(2)--, std_test_vector.at(2)--);
}
TEST(VectorTest, iterator_operator_plus_plus) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(1)++, std_test_vector.at(1)++);
}
TEST(VectorTest, iterator_operator_plus) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(0) + test_vector.at(1),
            std_test_vector.at(0) + std_test_vector.at(1));
}
TEST(VectorTest, iterator_operator_minus) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(2) - test_vector.at(1),
            std_test_vector.at(2) - std_test_vector.at(1));
}
TEST(VectorTest, iterator_operator_eq) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(4) == std_test_vector.at(4), 1);
}
TEST(VectorTest, iterator_operator_not_eq) {
  s21::Vector<int> test_vector{1, 2, 3, 4, 5};
  std::vector<int> std_test_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(test_vector.at(3) != std_test_vector.at(4), 1);
}



TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> arr;
  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that all elements are initialized to their default value (0 for int)
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 0);
  }
}

TEST(ArrayTest, InitListConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that each element is initialized correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, CopyConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrCopy(arr);

  // Check that the size is correct
  EXPECT_EQ(arrCopy.size(), 5);

  // Check that the elements are copied correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arrCopy[i], arr[i]);
  }
}

TEST(ArrayTest, MoveConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrMoved(std::move(arr));

  // Check that the size is correct
  EXPECT_EQ(arrMoved.size(), 5);

  // Check that the elements are moved correctly
  for (size_t i = 0; i < arrMoved.size(); ++i) {
    EXPECT_EQ(arrMoved[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Begin) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.begin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the array is updated
  *it = 10;
  EXPECT_EQ(arr[0], 10);
}

TEST(ArrayTest, End) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.end();
  // end() iterator should not be dereferenced; comparing it to another iterator
  // should work
  auto beginIt = arr.begin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, CBegin) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.cbegin();
  EXPECT_EQ(*it, 1);
  // Attempting to modify data through a const_iterator should result in a
  // compilation error Uncommenting the following line should result in a
  // compilation error. *it = 10;
}

TEST(ArrayTest, CEnd) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.cend();
  // cend() iterator should not be dereferenced; comparing it to another
  // iterator should work
  auto beginIt = arr.cbegin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, At_ValidIndex) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, At_OutOfBounds) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  // Attempting to access an out-of-bounds index using at() should throw an
  // exception
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, ConstAt_ValidIndex) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, ConstAt_OutOfBounds) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  // Attempting to access an out-of-bounds index using const at() should throw
  // an exception
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, Front) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, Back) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, ConstFront) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, ConstBack) {
  const s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, Empty_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_FALSE(arr.empty());
}

TEST(ArrayTest, Empty_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, Size_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, Size_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 5> arr;
  // The max size of an array with a specified size is the same as its declared
  // size
  EXPECT_EQ(arr.max_size(), 5);
}

TEST(ArrayTest, Swap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1.swap(arr2);

  // Check that the elements of arr1 are now from arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }

  // Check that the elements of arr2 are now from arr1
  for (size_t i = 0; i < arr2.size(); ++i) {
    EXPECT_EQ(arr2[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 5> arr;
  arr.fill(10);

  // Check that all elements are filled with the specified value
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 10);
  }
}

TEST(ArrayTest, CopyAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1 = arr2;

  // Check that arr1 now contains the same elements as arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], arr2[i]);
  }
}

TEST(ArrayTest, MoveAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1 = std::move(arr2);

  // Check that arr1 now contains the same elements as arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }
}

TEST(ArrayTest, OperatorBracket) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that elements can be accessed using the [] operator
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }

  // Modify an element using the [] operator and check if the array is updated
  arr[2] = 10;
  EXPECT_EQ(arr[2], 10);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
#ifdef __APPLE__
  free(__cxxabiv1::__cxa_get_globals());
#endif
  return RUN_ALL_TESTS();
}