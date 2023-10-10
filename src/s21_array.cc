// Copyright (C) 2023 Perryell - All Rights Reserved

#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_CC
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_CC
# include "./s21_array.h"

  // Default constructor
  template <typename T, std::size_t N>
  array<T, N>::array(){
    size = N;
    T arr[N];
  }

#endif
