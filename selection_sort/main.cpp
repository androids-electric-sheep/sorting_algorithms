#include <cassert>
#include <iostream>
#include <vector>

template <typename T> void display_vector(const std::vector<T> &input_vec) {
  for (const T &i : input_vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T> void selection_sort(std::vector<T> &input_vec) {
  for (auto i = input_vec.begin(); i != input_vec.end(); ++i) {
    auto min_val_place = i;
    for (auto j = i; j != input_vec.end(); ++j) {
      if (*j < *min_val_place) {
        min_val_place = j;
      }
    }
    std::iter_swap(i, min_val_place);
  }
}

int main() {
  std::vector<int> x = {5, 4, 3, 2, 1, 10, 1};
  display_vector(x);
  selection_sort(x);
  display_vector(x);
  assert(x == std::vector<int>({1, 1, 2, 3, 4, 5, 10}));
}
