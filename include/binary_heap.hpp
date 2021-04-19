#pragma once

#include <climits>
#include <optional>
#include <ostream>
#include <stdexcept> // runtime_error
#include <utility>   // swap

namespace itis {

struct BinaryHeap {
  virtual ~BinaryHeap() = default;

  virtual void Insert(int key) = 0;
  virtual std::optional<int> Extract() = 0;
  virtual void Remove(int key) = 0;
  virtual bool IsEmpty() const = 0;
};

struct MinBinaryHeap : BinaryHeap {
private:
  int size_{0};
  int capacity_{0};
  int *data_{nullptr};

public:
  explicit MinBinaryHeap(int capacity);

  void Insert(int key) override;

  std::optional<int> Extract() override;

  void Remove(int key) override;

  bool IsEmpty() const override;

private:
  void siftUp(int index);

  void heapify(int index);

  void remove(int index);

  int search(int key) const;

  // static methods
  static int parentId(int index);

  static int leftId(int index);
  static int rightId(int index);

  // output operator
  friend std::ostream &operator<<(std::ostream &, const MinBinaryHeap &);
};

inline std::ostream &operator<<(std::ostream &os, const MinBinaryHeap &heap) {
  for (int index = 0; index < heap.size_ - 1; index++) {
    os << heap.data_[index] << '\t';
  }

  os << heap.data_[heap.size_ - 1] << '\n';
  return os;
}

} // namespace itis