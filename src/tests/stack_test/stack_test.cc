#include <stack>

#include "../main_test.h"

TEST(StackConstructor, TestInt1) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  EXPECT_EQ(s21_stack.Empty(), std_stack.empty());
}

TEST(StackConstrustor, TestCopyInt1) {
  s21::Stack<int> s21_stack = {3, 1, 2, 4};
  std::stack<int> std_stack({3, 1, 2, 4});

  s21::Stack<int> s21_stack_1(s21_stack);
  std::stack<int> std_stack_1(std_stack);

  EXPECT_EQ(s21_stack_1.Top(), std_stack_1.top());
  EXPECT_TRUE(s21_stack_1.Size() == std_stack_1.size());
}

TEST(StackConstrustor, TestMoveInt1) {
  s21::Stack<int> s21_stack = {3, 1, 2, 4};
  std::stack<int> std_stack({3, 1, 2, 4});

  s21::Stack<int> s21_stack_1(std::move(s21_stack));
  std::stack<int> std_stack_1(std::move(std_stack));

  EXPECT_EQ(s21_stack_1.Top(), std_stack_1.top());
  EXPECT_TRUE(s21_stack_1.Size() == std_stack_1.size());
  EXPECT_EQ(s21_stack.Empty(), std_stack.empty());
}

TEST(StackOperator, TestCopyInt1) {
  s21::Stack<int> s21_stack = {3, 1, 2, 4};
  std::stack<int> std_stack({3, 1, 2, 4});

  s21::Stack<int> s21_stack_1;
  std::stack<int> std_stack_1;

  s21_stack_1 = s21_stack;
  std_stack_1 = std_stack;

  EXPECT_EQ(s21_stack_1.Top(), std_stack_1.top());
  EXPECT_TRUE(s21_stack_1.Size() == std_stack_1.size());
}

TEST(StackOperator, TestMoveInt1) {
  s21::Stack<int> s21_stack = {3, 1, 2, 4};
  std::stack<int> std_stack({3, 1, 2, 4});

  s21::Stack<int> s21_stack_1;
  std::stack<int> std_stack_1;

  s21_stack_1 = std::move(s21_stack);
  std_stack_1 = std::move(std_stack);

  EXPECT_EQ(s21_stack_1.Top(), std_stack_1.top());
  EXPECT_TRUE(s21_stack_1.Size() == std_stack_1.size());
  EXPECT_EQ(s21_stack.Empty(), std_stack.empty());
}

TEST(StackOperator, TestMoveInt2) {
  // Оригинал удаляет из себя всё
  s21::Stack<int> s21_stack_1({3, 1, 2, 4});
  std::stack<int> std_stack_1({3, 1, 2, 4});

  s21_stack_1 = std::move(s21_stack_1);
  std_stack_1 = std::move(std_stack_1);

  EXPECT_EQ(s21_stack_1.Top(), 4);
  EXPECT_EQ(s21_stack_1.Size(), 4);
}

TEST(StackPush, PushIntTest1) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  s21_stack.Push(5);
  s21_stack.Push(3);
  s21_stack.Push(4);

  std_stack.push(5);
  std_stack.push(3);
  std_stack.push(4);

  EXPECT_EQ(s21_stack.Top(), std_stack.top());
  EXPECT_TRUE(s21_stack.Size() == std_stack.size());
}

TEST(StackPop, PopIntTest1) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  s21_stack.Push(5);
  s21_stack.Push(3);
  s21_stack.Push(4);

  std_stack.push(5);
  std_stack.push(3);
  std_stack.push(4);

  s21_stack.Pop();
  std_stack.pop();

  EXPECT_EQ(s21_stack.Top(), std_stack.top());
  EXPECT_TRUE(s21_stack.Size() == std_stack.size());
}

TEST(StackOther, SizeTest1) {
  s21::Stack<int> s21_stack = {3, 1, 2, 4};
  std::stack<int> std_stack({3, 1, 2, 4});

  EXPECT_EQ(s21_stack.Top(), std_stack.top());
  EXPECT_TRUE(s21_stack.Size() == std_stack.size());
}

TEST(StackOther, SwapTest) {
  s21::Stack<int> s21_stack_1({3, 1, 2, 4});
  std::stack<int> std_stack_1({3, 1, 2, 4});

  s21::Stack<int> s21_stack_2;
  std::stack<int> std_stack_2;

  s21_stack_2.Swap(s21_stack_1);
  std_stack_2.swap(std_stack_1);

  EXPECT_EQ(s21_stack_2.Top(), std_stack_2.top());
  EXPECT_TRUE(s21_stack_1.Empty() == std_stack_1.empty());
  EXPECT_TRUE(s21_stack_2.Size() == std_stack_2.size());
}

TEST(StackOther, SwapTest1) {
  s21::Stack<int> s21_stack_1;
  std::stack<int> std_stack_1;

  s21::Stack<int> s21_stack_2;
  std::stack<int> std_stack_2;

  s21_stack_2.Swap(s21_stack_1);
  std_stack_2.swap(std_stack_1);

  EXPECT_TRUE(s21_stack_1.Empty() == std_stack_1.empty());
  EXPECT_TRUE(s21_stack_2.Empty() == std_stack_2.empty());
}

TEST(StackOther, SwapTest2) {
  s21::Stack<int> s21_stack_1({3, 1, 2, 4});
  std::stack<int> std_stack_1({3, 1, 2, 4});

  s21::Stack<int> s21_stack_2;
  std::stack<int> std_stack_2;

  s21_stack_2.Swap(s21_stack_1);
  std_stack_2.swap(std_stack_1);

  EXPECT_TRUE(s21_stack_2.Size() == std_stack_2.size());
  EXPECT_TRUE(s21_stack_1.Empty() == std_stack_1.empty());
}

TEST(StackOther, SwapTest3) {
  s21::Stack<int> s21_stack_1({3, 1, 2, 4});
  std::stack<int> std_stack_1({3, 1, 2, 4});

  s21::Stack<int> s21_stack_2({1, 3, 4, 5});
  std::stack<int> std_stack_2({1, 3, 4, 5});

  s21_stack_2.Swap(s21_stack_1);
  std_stack_2.swap(std_stack_1);

  EXPECT_TRUE(s21_stack_2.Size() == std_stack_2.size());
  EXPECT_TRUE(s21_stack_2.Size() == std_stack_2.size());
}