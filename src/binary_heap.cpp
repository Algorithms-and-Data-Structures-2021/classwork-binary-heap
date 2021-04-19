#include "binary_heap.hpp"

namespace itis {

std::ostream &operator<<(std::ostream &os, const MinBinaryHeap &heap) {
  for (int index = 0; index < heap.capacity_ - 1; index++) {
    os << heap.data_[index] << '\t';
  }

  os << heap.data_[heap.capacity_ - 1] << '\n';
  return os;
}
} //  namespace itis