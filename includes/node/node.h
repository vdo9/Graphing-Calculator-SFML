#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

// ------------- declaration --------------//

template <typename T>
struct node
{
public:
    node(const T& item = T(), node* next = nullptr);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const node<T> &printMe);

    T _item;
    node* _next;
};

// ------------definition -------------//

template <typename T>
node<T>::node(const T& item, node<T>* next){
    _item = item;
    _next = next; 
};

template <typename U>
ostream& operator << (ostream& outs, const node<U> &printMe)
{
  outs << "[" << printMe._item << "]->";
  return outs;
}

#endif