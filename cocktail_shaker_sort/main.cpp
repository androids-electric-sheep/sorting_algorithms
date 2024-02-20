#include <cassert>
#include <iostream>
#include <vector>

template <typename T> void display_vector(const std::vector<T> input_vec) {
  for (const auto &i : input_vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

template <typename T> void cocktail_shaker_sort(std::vector<T> &input_vec) {
  bool swapped = false;
  do {
    for (auto it = input_vec.begin(); it != input_vec.end() - 1;
         ++it) { // left to right pass
      if (*it > *(it + 1)) {
        std::iter_swap(it, it + 1);
        swapped = true;
      }
    }
    if (!swapped)
      break;
    swapped = false;
    for (auto it = input_vec.rbegin(); it != input_vec.rend() - 1;
         ++it) { // right to left pass
      if (*(it + 1) > *it) {
        std::iter_swap(it, it + 1);
        swapped = true;
      }
    }
  } while (swapped);
}

int main() {
  std::vector<int> x{7, 6, 4, 5, 3, 2, 1};
  display_vector(x);
  cocktail_shaker_sort(x);
  display_vector(x);
  assert(x == std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
  return 0;
}
