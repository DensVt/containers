// Copyright (C) 2023 Perryell - All Rights Reserved
#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_

#include <iostream>
#include <limits>

template <typename T, std::size_t N>
class array{
    public:
        array();
    private:
       T arr[N];
       std::size_t size = N;
};

#endif // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_H_
