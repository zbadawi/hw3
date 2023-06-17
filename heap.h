#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  PComparator comp_; //to store the comparator
  int m_; //to hold arity
  std::vector<T> items_; //to hold heap
  void heapify (int idx);
  int parentIdx(int childIdx); //to find parent of given index
};



// Add implementation of member functions here
//CONSTRUCTOR
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c), items_()
{} //initializing members

//DESTRUCTOR
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  items_.std::vector<T>::clear();
}
//PUSH(item)
template <typename T, typename PComparator>
void Heap<T, PComparator> :: push(const T& item)
{
  items_.push_back(item); // Add item to end of vector
  int currentIdx = items_.std::vector<T>::size() - 1; // Index of the new item

  // Heapify up to restore the heap property
  while (currentIdx > 0 && comp_(items_[currentIdx], items_[parentIdx(currentIdx)])) {
    std::swap(items_[currentIdx], items_[parentIdx(currentIdx)]);
    currentIdx = parentIdx(currentIdx);
  }
}

// TOP()
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }

  return items_[0];
}

// POP()
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }

  std::swap(items_[0], items_.back());
  items_.pop_back();
  heapify(0);
}

//PARENTIDX(childIdx)
template <typename T, typename PComparator>
int Heap<T, PComparator>::parentIdx(int childIdx)
{
  return (childIdx - 1) / m_;
}

//HEAPIFY()
template <typename T, typename PComparator>
void Heap<T, PComparator> :: heapify (int idx)
{
  int size = items_.std::vector<T>::size();
  int toChange = idx; //smaller or larger depending on comparator

  for (int child = 1; child <= m_; ++child) {
    int childIdx = m_ * idx + child;
    if (childIdx < size && comp_(items_[childIdx], items_[toChange])) {
      toChange = childIdx;
    }
  }

  if (toChange != idx) {
    std::swap(items_[idx], items_[toChange]);
    heapify(toChange);
  }
}

//EMPTY()
template <typename T, typename PComparator>
bool Heap<T, PComparator> :: empty() const
{
  return items_.std::vector<T>::empty();
}

//SIZE()
template <typename T, typename PComparator>
size_t Heap<T, PComparator> :: size() const
{
  return items_.std::vector<T>::size();
}

#endif