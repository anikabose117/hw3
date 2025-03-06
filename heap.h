#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

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
  std::vector<T> data_;
  int m_;
  // we don't know what we are comparing (if best is larger or smaller) until implementation
  PComparator c_; 

  // helper function
  void heapify(size_t index);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
// recursive function, makes sure element at index is in correct position
void Heap<T,PComparator>::heapify(size_t index){
  // uses m_ to ensure if works for any size tree, not just a binary
  int leftChild = m_ * index + 1; 
  int bestChild = leftChild; 
  
  // base case: no children, so return
  if (leftChild >= data_.size()){
    return; 
  }

  // iterate over all possible children (up to m-ary heap)  
  for (int i = 0; i < m_; ++i){
    int nextChild = leftChild + i;
    // update best child, i.e. trickle down if true
    if (nextChild < data_.size() && c_(data_[nextChild], data_[bestChild])) {
      bestChild = nextChild; 
  }
  }

  if (data_[index] != data_[bestChild]) { 
    // swap if parent is not in correct position
      std::swap(data_[index], data_[bestChild]);
      heapify(bestChild); 
  }
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  // update data members
  m_ = m;
  c_ = c;
}

// default
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){   
}

// pushes a new element onto the heap while maintaining the heap property
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  // insert item at end of heap
    data_.push_back(item);
    size_t index = data_.size() - 1;
    // trickle up
    while (index != 0) {
        size_t parentIndex = (index - 1) / m_;
        if (!c_(data_[index], data_[parentIndex])) {
            break;
        }
        std::swap(data_[index], data_[parentIndex]);
        index = parentIndex;
    }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
// get best element
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error -- Empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
// get rid of best element
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error -- Empty");
  }
  std::swap(data_[0], data_.back());
  data_.pop_back();
  if (!empty()){
    // trickle down element swapped to top
    heapify(0);
  }
}

// calls vector function because it is a data member
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data_.empty();
}

// calls vector function because it is a data member
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data_.size();
}


#endif

