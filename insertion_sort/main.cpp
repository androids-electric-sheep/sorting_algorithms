#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>

template <typename T> void display_vector(const std::vector<T> &input_vec) {
  for (const T &i : input_vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T> void insertion_sort(T &&input_vec) {
  for (auto i = input_vec.begin() + 1; i < input_vec.end(); ++i) {
    for (auto j = i - 1; j >= input_vec.begin(); --j) {
      while (*j > *i) {
        std::iter_swap(j, i--);
      }
    }
  }
}

int main() {
  std::vector<int> x{7, 8, 1, 3, 2, 4, 6, 5};
  display_vector(x);
  insertion_sort(x);
  display_vector(x);
  assert(x == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
}
