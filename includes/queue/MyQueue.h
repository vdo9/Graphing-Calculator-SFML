#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Queue
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Queue;

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
        return Iterator(_ptr + 1);
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
  Queue();

  //BIG 3:
  Queue(const Queue<T>& copyMe);
  ~Queue();
  Queue<T>& operator =(const Queue<T>& RHS);

  //Operations:
  void push(T item);
  T pop();

  //Accessors:
  Iterator begin() const;             //Iterator to the head node
  Iterator end() const;               //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T front();
  T back();
  
  template<typename U>
  friend ostream& operator <<(ostream& outs, const Queue<U>& printMe);
  
private:
  node<T>* _front;
  node<T>* _rear;
  int _size;
};


//Definition

//TODO

//CTOR
template <typename T>
Queue<T>::Queue(){
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
};

  //BIG 3:
template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe){
    _front = _copy_list(copyMe._front);
    _size = copyMe._size;
    // _rear = _copy_list(copyMe._rear);
    _rear = _last_node(_front);
};

template <typename T>
Queue<T>::~Queue(){ 
    // delete _rear;
    _clear_list(_front);
   
};

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue<T>& RHS){
    if(this == &RHS){
        return *this;
    }
    // if (_front)
        // delete RHS._front;
    // delete RHS._rear;

    // node<T>* _front = new node<T>();
    _front = _copy_list(RHS._front);
    _size = RHS._size;
    _rear = RHS._rear; 

    return *this;
};

//Operations:
template <typename T>
void Queue<T>::push(T item){
    _size++;
    _rear =_insert_after(_front, _rear, item);

    // --- insert_head already satisfies this ---//
    // node<T>* temp = _front;
    // node<T>* newNode = new node<T>();
    // newNode->_item = item;
    // newNode->_next = nullptr;

    // if (temp == nullptr && _size == 0) {
    //     _front = newNode;
    // }
    
    // else if(temp->_next == nullptr && _size == 1){
    //     temp->_next = newNode;
    // }

    // else{
    //     while(temp->_next != nullptr){
    //         temp = temp->_next;
    //     }
    //     temp->_next = newNode;
    // }
};

template <typename T>
T Queue<T>::pop(){
    _size--;

    // --- tried calling lower level function but didnt work, call function delete instead --- //
    node<T>* temp = _front; // must make this temp first to grab value but then actually move to remove the first top
    _front = _front->_next;
    return temp->_item;
};

//Accessors:

//Iterator to head node
template<typename T>
typename Queue<T>::Iterator Queue<T>::begin() const{
  return Iterator(_front);
};            

//Iterator to NULL
template<typename T>
typename Queue<T>::Iterator Queue<T>::end() const{
    return Iterator(nullptr);
};              

//Checkers:
template<typename T>
int Queue<T>::size() const { 
    return _size; 
}

template<typename T>
bool Queue<T>::empty(){
    if(_front == nullptr){
        return true;
    }
    return false;
};

template<typename T>
T Queue<T>::front(){
    return _front->_item;
};

template<typename T>
T Queue<T>::back(){
    return _rear->_item;
};
  
template<typename U>
ostream& operator <<(ostream& outs, const Queue<U>& printMe){
    node<U>* temp = printMe._front;
    outs << "Queue:Head->";
    while (temp != nullptr) {
        outs << *temp; // cout node and is used in node.h outstream
        temp = temp->_next;
    }
    outs << "|||\n"; // ending mark
    // outs << "[" << printMe.head->_item << "]->";
    return outs;
};
  

#endif //MYQUEUE_H
