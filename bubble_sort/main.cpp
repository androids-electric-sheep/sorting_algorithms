#include <cassert>
#include <iostream>
#include <vector>

template <typename T> void display_vector(const std::vector<T> &input_vec) {
  for (const auto &i : input_vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T> void bubble_sort(std::vector<T> &input_vec) {
  for (auto i = input_vec.begin(); i != input_vec.end(); ++i) {
    for (auto j = i + 1; j < input_vec.end(); ++j) {
      if (*i > *j) {
        std::iter_swap(i, j);
      }
    }
  }
}

int main() {
  std::vector<int> x = {1, 5, 10, 4, 3, 2, 1};
  display_vector(x);
  bubble_sort(x);
  display_vector(x);
  assert(x == std::vector<int>({1, 1, 2, 3, 4, 5, 10}));
}
