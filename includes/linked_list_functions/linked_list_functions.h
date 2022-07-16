#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <cassert>

#include "../node/node.h"

using namespace std;

// Declaration
//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T>* head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this);

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this);

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this);

//duplicate the list
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>* &head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

// //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
// //      Sorted List Routines. order: 0: ascending, order: other: descending
// //                              Assume a Sorted List
// //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

// //insert
// template <typename T>
// node<T>* _insert_sorted(node<T>* &head, T item, bool ascending=true);

// //insert or add if a dup
// template <typename T>
// node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);

// //node after which this item goes order: 0 ascending
// template <typename T>
// node<T>* _where_this_goes(node<T>* head, T item, bool ascending=true);

//Last node in the list, never use this function.
template <typename T>
node<T>* _last_node(node<T>* head);

// Definition

// TODO

template <typename T>
void _print_list(node<T>* head){
    // while (head != NULL) {
    //     cout << "[" << head->_item << "]->";
    //     head = head->_next;
    // }
    // cout << "|||" << endl;

    node<T>* temp = head;
    while (temp != nullptr) {
        cout << *temp; // cout node and is used in node.h outstream
        temp = temp->_next;
    }
    cout << "|||\n"; // ending mark
};

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T>* head){
     // initialize pointers
    node<T>* current = head;
    node<T>* prev = NULL; 
    node<T>* next = NULL;

    while (current != NULL) {
        // store next
        next = current->next;
        // reverse current node's pointer
        current->next = prev;
        // move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
};

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key){
    node<T>* current = head; 
    while (current != nullptr) 
    { 
        if (current->_item == key) 
            return current; 
        else{
            current = current->_next;  
        }
    } 
    return nullptr; 
};

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this){
    node<T>* newNode = new node<T>();
    newNode->_item = insert_this;
    newNode->_next = head; // points at the next address where head is pointing at
    head = newNode; // makes head pointer point at the new node address

    return newNode;
};

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this){
    node<T>* temp = head;
    node<T>* newNode = new node<T>();
    newNode->_item = insert_this;
    newNode->_next = nullptr;

    if (temp == nullptr) {
        head = newNode;
    }

    else if(temp->_next == nullptr){
        temp->_next = newNode;
    }

    else{
        while(temp != after_this){
            temp = temp->_next;
        }
        newNode->_next = temp->_next;
        temp->_next = newNode;
        //
    }

    // ------scraping this cause it doesn't work in MyQueue.h-----//
    // node<T>* newNode = new node<T>(); // it is also fine to not include parameters -- item will be 0, default
    // newNode->_item = insert_this;
    // newNode->_next = head;

    // node<T>* temp = head;

    // if(temp == nullptr){
    //     newNode->_next = head;
    //     head = newNode;
    //     return newNode;
    // }

    // else{
    //     while(temp != nullptr){ 
    //         if(temp == after_this){
    //             newNode->_next = after_this->_next;
    //             after_this->_next = newNode;
    //             temp = temp->_next->_next;
    //             return newNode;
    //         }
    //     temp = temp->_next;
    //     }
    // }
    
    return newNode;

};

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this){
    // cout << "working b0" << endl;
    node<T>* newNode = new node<T>();
    newNode->_item = insert_this;

    node<T>* temp = head;

    // insert head
    // differ from insert_after by switching while and if statement
    if(temp == nullptr){ // must address head directly for changes in the beginning
        // cout << "working b1" << endl;
        newNode->_next = nullptr;
        head = newNode;
        return newNode;
    }
    // if there is only one node
    else if(temp->_next == nullptr){
        newNode->_next = temp;
        head = newNode;
        return newNode;
    }
 
    while(temp->_next != nullptr){
        // !!! don't use temp to change the beginning because temp just gives info 
        // for linked list, you must change the head directly because it is the main pointer holding the connection with other data
        // if(temp == before_this){ 
        //     newNode->_next = temp;
        //     temp = newNode;
        //     temp->_next = newNode;
        //     return temp;
        // }
        // cout << "working b2" << endl;
        // insert before head node
        if(temp == before_this && before_this == head){ 
            newNode->_next = temp;
            head = newNode;      
            return newNode;
        }
        else if(temp->_next == before_this){
            newNode->_next = temp->_next;
            temp->_next = newNode;
            return newNode;
        }
        // ^
        // else if(temp->_next->_next == nullptr){
        //     newNode->_next = temp->_next; // value
        //     // vs. pointer
        //     temp->_next = newNode;
        // }
        temp = temp->_next;
    }

    // // address last node
    // if (temp->_next == nullptr){
    //     newNode->_next = temp;
    //     temp->_next = newNode;
    //     return newNode;
    // }

    return nullptr;
};

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this){
    struct node<T>* temp = head;
    while(temp->_next->_next != prev_to_this){
        temp = temp->_next;
    }
    return temp->_next;
};

//delete, return item
//Traverse to element before the element to be deleted
//Change next pointers to exclude the node from the chain
template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this){ 
    node<T>* temp = head; // this is the mover!

    while(temp->_next != delete_this){
        // cout << "moved " << endl;
        temp = temp->_next;
    }

    if(delete_this->_next == nullptr){
        temp->_next = nullptr;
    }
    else{
        temp->_next = delete_this->_next;
    }

    // for pointer object, we can only use arrow to access variables
    return delete_this->_item; // (*delete_this)._item  // (*delete_this) is a object, so we need the dot operator to access
};

//duplicate the list
template <typename T>
node<T>* _copy_list(node<T>* head)
{
    node<T>* dest = nullptr;
    dest = _copy_list(dest, head);
    return dest;
}


//duplicate list and return the last node of the copy
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src){
    // if (dest) // dest != nullptr
    // if (!dest) // dest == nullptr

    if (!src) { // src == nullptr
        dest = nullptr;
        return dest;
    }

    // my src is not nullptr
    node<T>* linkedNode = new node<T>();
    dest = linkedNode;

    node<T>* temp = src;  // walker through src    
    node<T>* walker = dest;

    dest->_item = temp->_item;

    temp = temp->_next;

    while(temp != nullptr){
        node<T>* newNode = new node<T>();
        newNode->_item = temp->_item;

        walker->_next = newNode; // HAVE TO MAKE WALKER WHICH IS POINTING AT THE ADDRESS EQUAL THE NEW NODE...!!!!
        walker = walker->_next;
        
        temp = temp->_next;
    }
    // can't leave the last hanging without pointing 
    walker->_next = nullptr;

    return dest; 
}

//delete all the nodes
template <typename T>
void _clear_list(node<T>* &head){
    if(!head){ // head == null == false, !head = !false = true
        return;
    }

    node<T>* temp = head;
    node<T>* walker = head;
    
    while(temp->_next != nullptr){
        temp = temp->_next;
        delete walker;
        walker = temp; 
        
    }
    head = nullptr;
}

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos){
    node<T>* temp = head;

    for(int i = 0; i < pos; i++){
        temp = temp->_next;
    }

    return temp->_item;
}

//Last node in the list, never use this function.
template <typename T>
node<T>* _last_node(node<T>* head){
    node<T>* temp = head;

    while(temp->_next != nullptr){
        temp = temp->_next;
    }

    return temp;
};

#endif // LINKED_LIST_FUNCTIONS_H