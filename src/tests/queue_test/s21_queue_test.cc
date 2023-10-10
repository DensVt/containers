#include <queue>

#include "../main_test.h"

TEST(QueueConstructor, TestInt1) {
  s21::Queue<int> s21_Queue;
  std::queue<int> std_queue;

  EXPECT_EQ(s21_Queue.Empty(), std_queue.empty());
}

TEST(QueueConstructor, TestCopy) {
  s21::Queue<int> s21_queue({3, 1, 2, 4});
  std::queue<int> std_queue({3, 1, 2, 4});

  s21::Queue<int> s21_queue_1(s21_queue);
  std::queue<int> std_queue_1(std_queue);

  EXPECT_EQ(s21_queue_1.Front(), std_queue_1.front());
  EXPECT_TRUE(s21_queue_1.Size() == std_queue_1.size());
}

TEST(QueueConstructor, TestMove1) {
  s21::Queue<int> s21_queue = {3, 1, 2, 4};
  std::queue<int> std_queue({3, 1, 2, 4});

  s21::Queue<int> s21_queue_1(std::move(s21_queue));
  std::queue<int> std_queue_1(std::move(std_queue));

  EXPECT_EQ(s21_queue_1.Front(), std_queue_1.front());
  EXPECT_TRUE(s21_queue_1.Size() == std_queue_1.size());
  EXPECT_EQ(s21_queue.Empty(), std_queue.empty());
}

TEST(QueueOperator, TestCopyInt1) {
  s21::Queue<int> s21_queue = {3, 1, 2, 4};
  std::queue<int> std_queue({3, 1, 2, 4});

  s21::Queue<int> s21_queue_1;
  std::queue<int> std_queue_1;

  s21_queue_1 = s21_queue;
  std_queue_1 = std_queue;

  EXPECT_EQ(s21_queue_1.Front(), std_queue_1.front());
  EXPECT_TRUE(s21_queue_1.Size() == std_queue_1.size());
  EXPECT_TRUE(s21_queue_1.Size() == s21_queue.Size());
}

TEST(QueueOperator, TestMoveInt1) {
  s21::Queue<int> s21_queue = {3, 1, 2, 4};
  std::queue<int> std_queue({3, 1, 2, 4});

  s21::Queue<int> s21_queue_1;
  std::queue<int> std_queue_1;

  s21_queue_1 = std::move(s21_queue);
  std_queue_1 = std::move(std_queue);

  EXPECT_EQ(s21_queue_1.Front(), std_queue_1.front());
  EXPECT_TRUE(s21_queue_1.Size() == std_queue_1.size());
  EXPECT_EQ(s21_queue.Empty(), std_queue.empty());
}

TEST(QueueOperator, TestMoveInt2) {
  // Оригинал удаляет из себя всё
  s21::Queue<int> s21_queue_1({3, 1, 2, 4});
  std::queue<int> std_queue_1({3, 1, 2, 4});

  s21_queue_1 = std::move(s21_queue_1);
  std_queue_1 = std::move(std_queue_1);

  EXPECT_EQ(s21_queue_1.Front(), 3);
  EXPECT_EQ(s21_queue_1.Back(), 4);
  EXPECT_EQ(s21_queue_1.Size(), 4);
}

TEST(QueueOther, TestPush1) {
  s21::Queue<int> s21_Queue({1, 2, 3, 4});
  std::queue<int> std_queue({1, 2, 3, 4});

  s21_Queue.Push(66);
  std_queue.push(66);

  EXPECT_EQ(s21_Queue.Back(), std_queue.back());
}

TEST(QueueOther, TestPop1) {
  s21::Queue<int> s21_Queue({1, 2, 3, 4});
  std::queue<int> std_queue({1, 2, 3, 4});

  s21_Queue.Pop();
  std_queue.pop();

  EXPECT_EQ(s21_Queue.Front(), std_queue.front());
}

TEST(QueueOther, SizeTest1) {
  s21::Queue<int> s21_queue = {3, 1, 2, 4};
  std::queue<int> std_queue({3, 1, 2, 4});

  EXPECT_EQ(s21_queue.Front(), std_queue.front());
  EXPECT_TRUE(s21_queue.Size() == std_queue.size());
}

TEST(QueueOther, TestSwap) {
  s21::Queue<int> s21_queue_1({3, 1, 2, 4});
  std::queue<int> std_queue_1({3, 1, 2, 4});

  s21::Queue<int> s21_queue_2;
  std::queue<int> std_queue_2;

  s21_queue_2.Swap(s21_queue_1);
  std_queue_2.swap(std_queue_1);

  EXPECT_EQ(s21_queue_2.Front(), std_queue_2.front());
  EXPECT_TRUE(s21_queue_1.Empty() == std_queue_1.empty());
  EXPECT_TRUE(s21_queue_2.Size() == std_queue_2.size());
}

TEST(QueueOther, SwapTest1) {
  s21::Queue<int> s21_queue_1;
  std::queue<int> std_queue_1;

  s21::Queue<int> s21_queue_2;
  std::queue<int> std_queue_2;

  s21_queue_2.Swap(s21_queue_1);
  std_queue_2.swap(std_queue_1);

  EXPECT_TRUE(s21_queue_1.Empty() == std_queue_1.empty());
  EXPECT_TRUE(s21_queue_2.Empty() == std_queue_2.empty());
}

TEST(QueueOther, SwapTest2) {
  s21::Queue<int> s21_queue_1({3, 1, 2, 4});
  std::queue<int> std_queue_1({3, 1, 2, 4});

  s21::Queue<int> s21_queue_2;
  std::queue<int> std_queue_2;

  s21_queue_2.Swap(s21_queue_1);
  std_queue_2.swap(std_queue_1);

  EXPECT_TRUE(s21_queue_2.Size() == std_queue_2.size());
  EXPECT_TRUE(s21_queue_1.Empty() == std_queue_1.empty());
}

TEST(QueueOther, SwapTest3) {
  s21::Queue<int> s21_queue_1({3, 1, 2, 4});
  std::queue<int> std_queue_1({3, 1, 2, 4});

  s21::Queue<int> s21_queue_2({1, 3, 4, 5});
  std::queue<int> std_queue_2({1, 3, 4, 5});

  s21_queue_2.Swap(s21_queue_1);
  std_queue_2.swap(std_queue_1);

  EXPECT_TRUE(s21_queue_2.Size() == std_queue_2.size());
  EXPECT_TRUE(s21_queue_2.Size() == std_queue_2.size());
}