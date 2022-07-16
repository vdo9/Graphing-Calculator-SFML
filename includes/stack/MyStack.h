#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Stack
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Stack;

    //Default CTOR
    Iterator(){ 
        _ptr = nullptr;
    }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ 
        _ptr = p;
    }
    
    //dereference operator
    T& operator *(){ 
        return _ptr->_item;
    }               
    //member access operator
    T* operator ->(){ 
        return Iterator(_ptr+1);
    }
    //true if _ptr is NULL
    bool is_null(){ 
        if(_ptr == nullptr){
            return true;
        }
        return false;
    }   

    //true if left != right
    friend bool operator !=(const Iterator &left, const Iterator &right){ 
        return left._ptr != right._ptr;
    }
    //true if left == right
    friend bool operator ==(const Iterator &left, const Iterator &right){ 
        return !(left._ptr != right._ptr);
    }

    //member operator:  ++it; or ++it = new_value
    Iterator& operator ++(){ 
        // _ptr++; // ptr = ptr.next
        _ptr = _ptr->_next;

        return *this;
    }                 
    //friend operator: it++
    friend Iterator operator ++(Iterator &it, int unused){ 
        Iterator hold = it;

        it._ptr = it._ptr->_next;
        return hold;
    }
  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //CTOR
  Stack();

  //BIG 3:
  Stack(const Stack<T>& copyMe);
  ~Stack();
  Stack<T>& operator =(const Stack<T>& RHS);

  //Operations:
  void push(T item);

  //Accessors:
  Iterator begin() const;            //Iterator to the head node
  Iterator end() const;              //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T top();
  T pop();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Stack<U>& printMe);
  
private:
  node<T>* _top;
  int _size;
};

//Definition

//TODO

//CTOR
template<typename T>
Stack<T>::Stack(){
    _top = nullptr;
    _size = 0;
};

  //BIG 3:
template<typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
};
  
template<typename T>
Stack<T>::~Stack(){
    _clear_list(_top);
};

template<typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& RHS){
    if(this == &RHS){
        return *this;
    }

    // if(_top)
    //     delete _top; //

    // node<T>* _top = new node<T>();
    _top = _copy_list(RHS._top);
    _size = RHS._size;

    return *this;
};

//Operations:
template<typename T>
void Stack<T>::push(T item){
    _size++;
    _insert_head(_top, item);
};

//Accessors:
//Iterator to the head node
template<typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    return Iterator(_top);
};            
  
//Iterator to NULL
template<typename T>
typename Stack<T>::Iterator Stack<T>::end() const{
    return Iterator(nullptr);
};             

//Checkers:
template<typename T>
int Stack<T>::size() const { 
    return _size;
}

template<typename T>
bool Stack<T>::empty(){
    return _top == nullptr;
};

template<typename T>
T Stack<T>::top(){
    if(_top){
        return _top->_item;
    }
};

template<typename T>
T Stack<T>::pop(){
    _size--;
    node<T>* temp = _top; // must make this temp first to grab value but then actually move to remove the first top
    _top = _top->_next;
    return temp->_item;
};

template<typename U>
ostream& operator <<(ostream& outs, const Stack<U>& printMe){
    node<U>* temp = printMe._top ;
    outs << "Stack:Head->";
    while (temp != nullptr) {
        outs << *temp; // cout node and is used in node.h outstream
        temp = temp->_next;
    }
    outs << "|||\n"; // ending mark
    // outs << "[" << printMe.head->_item << "]->";
    return outs;
};

#endif // MYSTACK_H