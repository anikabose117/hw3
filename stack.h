#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// default implementation
template <typename T>
Stack<T>::Stack() : std::vector<T>(){
}

// default implementation
template <typename T>
Stack<T>::~Stack(){   
}

// can use vector function because inherits from vector
template <typename T>
bool Stack<T>::empty() const{
    return std::vector<T>::empty();  
}

// can use vector function because inherits from vector
template <typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size();   
}

// can use vector function because inherits from vector
template <typename T>
void Stack<T>::push(const T& item){
    std::vector<T>::push_back(item);    
}

// can use vector function because inherits from vector
template <typename T>
void Stack<T>::pop(){
    if (empty()){
        throw std::underflow_error("Error -- Empty");
    }
    std::vector<T>::pop_back();
}

// can use vector function because inherits from vector
template <typename T>
const T& Stack<T>::top() const{
    if (empty()){
        throw std::underflow_error("Error -- Empty");
    }
    return std::vector<T>::back();
}
#endif