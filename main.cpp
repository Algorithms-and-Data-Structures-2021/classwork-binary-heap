#include <iostream>

#include "binary_heap.hpp"

using namespace itis;

int main(int argc, char **argv) {

  MinBinaryHeap heap{7};

  heap.Insert(5);
  heap.Insert(0);
  heap.Insert(2);
  heap.Insert(4);
  heap.Insert(6);
  heap.Insert(3);
  heap.Insert(1);

  std::cout << heap << std::endl;

  heap.Remove(0);

  std::cout << heap << std::endl;

  return 0;
}