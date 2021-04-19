#include "binary_heap.hpp"

#include <cassert>

namespace itis {

MinBinaryHeap::MinBinaryHeap(int capacity) : capacity_{capacity} {
  assert(capacity > 0);
  data_ = new int[capacity_]{}; // [0, 0, ..., 0]
}

void MinBinaryHeap::Insert(int key) {
  if (size_ == capacity_) {
    throw std::runtime_error("Heap has reached max capacity");
  }

  // insert element to the rightmost free space in the array
  int index = size_;
  data_[index] = key;
  size_++;

  // "поднять" элемент вверх по дереву (если необходимо)
  siftUp(index);
}

std::optional<int> MinBinaryHeap::Extract() {
  // case 1: empty heap
  if (size_ == 0) {
    return std::nullopt;
  }

  const int root = data_[0];

  if (size_ == 1) {

    // case 2: heap with a single element
    size_--;

  } else {

    // case 3: heap with multiple elements
    data_[0] = data_[size_ - 1]; // the rightmost element
    size_--;

    // reorganize the heap
    heapify(0);
  }

  return root;
}

void MinBinaryHeap::Remove(int key) {
  // find the index and remove
  const int index = search(key);
  remove(index);
}

bool MinBinaryHeap::IsEmpty() const { return size_ == 0; }

void MinBinaryHeap::siftUp(int index) {
  assert(index >= 0 && index <= size_);

  while (index != 0 && data_[index] < data_[parentId(index)]) {
    // swap a child with its parent
    std::swap(data_[index], data_[parentId(index)]);
    index = parentId(index);
  }
}

void MinBinaryHeap::heapify(int index) {
  const int left_index = leftId(index);
  const int right_index = rightId(index);

  // index of the smallest element in the sub-tree
  int smallest_index = index;

  if (left_index < size_ && data_[left_index] < data_[index]) {
    smallest_index = left_index;
  }

  if (right_index < size_ && data_[right_index] < data_[smallest_index]) {
    smallest_index = right_index;
  }

  if (smallest_index != index) {
    std::swap(data_[index], data_[smallest_index]);
    heapify(smallest_index);
  }
}

void MinBinaryHeap::remove(int index) {
  // set removed element to the most minimal value and sift it up to the top
  data_[index] = std::numeric_limits<int>::min();
  siftUp(index);
  Extract();
}

int MinBinaryHeap::search(int key) const {
  // TODO: implement me, pls
  return -1;
}
int MinBinaryHeap::leftId(int index) { return index * 2 + 1; }
int MinBinaryHeap::parentId(int index) { return (index - 1) / 2; }
int MinBinaryHeap::rightId(int index) { return leftId(index) + 1; }

} //  namespace itis