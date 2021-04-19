#pragma once

#include <climits>
#include <optional>
#include <ostream>
#include <stdexcept> // runtime_error
#include <utility>   // swap

namespace itis {

struct MinBinaryHeap final {

  explicit MinBinaryHeap(int capacity) : capacity_{capacity} {
    data_ = new int[capacity_]{}; // [0, 0, ..., 0]
  }

  void Insert(int key) {
    if (size_ == capacity_) {
      throw std::runtime_error("Heap has reached max capacity");
    }

    // insert element to the rightmost free space in the array
    int index = size_;
    data_[index] = key;
    size_++;

    siftUp(index);
  }

  std::optional<int> Extract() {
    if (size_ == 0) {
      return std::nullopt;
    }

    const int root = data_[0];

    if (size_ == 1) {
      size_--;
      data_[0] = std::numeric_limits<int>::max();
      return root;
    }

    data_[0] = data_[size_ - 1];
    data_[size_ - 1] = std::numeric_limits<int>::max();
    size_--;
    heapify(0);
    return root;
  }

  void Remove(int index) {
    data_[index] = std::numeric_limits<int>::min();
    siftUp(index);
    Extract();
  }

  // TODO: Search(key) => index, Remove(key)

private:
  int *data_{nullptr};

  int size_{0};
  int capacity_{0};

  void siftUp(int index) {
    while (index != 0 && data_[parentId(index)] > data_[index]) {
      std::swap(data_[index], data_[parentId(index)]);
      index = parentId(index);
    }
  }

  void heapify(int index) {
    const int left = leftId(index);
    const int right = rightId(index);
    int smallest = index;

    if (left < size_ && data_[left] < data_[index]) {
      smallest = left;
    }

    if (right < size_ && data_[right] < data_[smallest]) {
      smallest = right;
    }

    if (smallest != index) {
      std::swap(data_[index], data_[smallest]);
      heapify(smallest);
    }
  }

  static int leftId(int node_id) { return node_id * 2 + 1; }

  static int rightId(int node_id) { return leftId(node_id) + 1; }

  static int parentId(int node_id) { return (node_id - 1) / 2; }

  friend std::ostream &operator<<(std::ostream &, const MinBinaryHeap &);
};

} // namespace itis