#include <algorithm>
#include <array>
#include <iostream>

template <typename T, size_t N>
void display_array(const std::array<T, N> &input_array) {
  for (const auto &i : input_array) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T, size_t N>
void merge(std::array<T, N> &input_array, size_t l, size_t m, size_t r) {
  auto left_array_len = m - l + 1;
  auto right_array_len = r - m;

  // Copy subarrays over
  int *left_array = new int[left_array_len];
  int *right_array = new int[right_array_len];
  std::copy(input_array.begin() + l, input_array.begin() + l + left_array_len,
            left_array);
  std::copy(input_array.begin() + m + 1,
            input_array.begin() + m + 1 + right_array_len, right_array);

  // Merge two array together in size order
  size_t left_array_index = 0;
  size_t right_array_index = 0;
  size_t merged_array_index = l;
  while (left_array_index < left_array_len &&
         right_array_index < right_array_len) {
    if (left_array[left_array_index] <= right_array[right_array_index]) {
      input_array[merged_array_index++] = left_array[left_array_index++];
    } else {
      input_array[merged_array_index++] = right_array[right_array_index++];
    }
  }

  // Finish off left array
  while (left_array_index < left_array_len) {
    input_array[merged_array_index++] = left_array[left_array_index++];
  }

  // Finish off right array
  while (right_array_index < right_array_len) {
    input_array[merged_array_index++] = right_array[right_array_index++];
  }
}

template <typename T, size_t N>
void merge_sort(std::array<T, N> &input_array, size_t l, size_t r) {
  if (l >= r) {
    return;
  }
  auto m = l + (r - l) / 2;
  merge_sort(input_array, l, m);
  merge_sort(input_array, m + 1, r);
  merge(input_array, l, m, r);
}

int main() {
  std::array<int, 11> x = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  display_array(x);
  merge_sort(x, 0, x.size() - 1);
  display_array(x);
  return 0;
}
