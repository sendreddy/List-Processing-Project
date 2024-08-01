/* Name       : Srujana Endreddy 
 * Date       : October 21, 2022 
 * File Name  : List.h
 * Description: In this List.h file, a List<T> template class is written to manage a linked list of connected Node<T> classes. This List<T> class
 * forms the final managed doubly linked list. In addition, the List <T> object also maintains two Node<T>* variables, an int _size field to hold
 * the current number of Node<T> objects that are linked together, inserts Node<T> object or after existing Node<T> in the linked list, and finally
 * deletes a Node<T> object from the linked list. The functions, erase, insert_after, insert_before are from Lab 05 but have been expanded for this
 * project to print the expected output. In addition, push_front, push_back, pop_front, and pop_back functions are also added to this file. 
 * Finally, with the given Project2.cpp file, the List.h can be tested to print the output to the terminal. */


// List.h
#ifndef _LIST_H_
#define _LIST_H_
using namespace std;

// Templated Node class
template <class T>
class Node {
public:
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
    Node() {};                          // Constructors
    Node(T data) { this->data = data; }
    // ~Node() { std::cout << "X"; };   // For debugging
};



// Templated List class
template <class T>
class List {
private:
    Node<T> *_first = nullptr;          // Always points to first list Node<T>
    Node<T> *_last  = nullptr;          // Always points to last list Node<T>
    int _size  = 0;                     // Always holds the size of the List<T>
public:
    List() {};                          // Constructor
    ~List() {                           // Destructor loops through all Nodes<T>s and invokes this->pop_front() while Node<T>s are in the List.
        while (this-> _size > 0) {
            this->pop_front();
        }
    }
    int size() const {                 // Get List size (_size). This is a getter method and it returns size
      return _size; 
    }
    Node<T> *first() const {            // This is a getter method and returns _first, a pointer to first Node<T>  
         return _first; 
    }
    Node<T> *last() const{              // Getter method and returns _last, a pointer to last Node<T> 
        return _last;
    }              
    T &front() const {                  // This is a getter method. It gets ref to data in first element
       return data;
    }
    T &back() const {                   // Get ref to data in last element
       return data;
    }

    
    

    /*This new template function deletes Node<T> from List<T>. It also adjusts all pointers as needed. */
    // Erase n from a list and reconnect adjacent Nodes                          
    void erase(Node<T> *n) {             // Delete Node<T> from List<T>

    //If n->prev IS NOT nullptr, then this is not the first Node. Reassign n->prev->next to n->next 
    //If n->next IS NOT nullptr, then n is not the last Node. Reassign n->next->prev to n->prev. 
    if (!(n->prev == nullptr || n-> next == nullptr)) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    
  }

    else {
    //If n->next IS nullptr, then n was the last Node. Reassign this->_last to n->prev 
    if (n->next == nullptr) {
        n->prev->next = nullptr; 
        this->_last = n->prev; 
    }
        //If n->prev IS nullptr, then n was the first Node. Reassign this->_first = n->next 
        else if (n->prev == nullptr) {
            n->next->prev == nullptr;
            this->_first = n->next;  
        }
    }


    delete n; 
    --_size;    //decrement size 

    };
    


/*This template function inserts data into the list which dynamically creates a new Node<T> object that encapsulates data. After, it inserts 
that new Node<T> object after n; this adjusts the pointers as needed, and returns to this new Node<T> object. */
// Insert a new Node containing data after n 
//create a new Node<T> on heap to hold data and assign a pointer to temp

  Node<T>* insert_after(Node<T> *n, const T &data) {
  Node<T> *temp = new Node<T>;  
  temp->data = data;

  //If temp->next is not nullptr then it IS NOT the last Node, set temp->next->prev to temp 
  //Assign temp->next to n->next and temp->prev to n
  if (n->next != nullptr) {
     temp->next = n->next;
     n->next = temp;             //Assign n->next to temp
     temp->prev = n;
  }
  
  else {
   temp->next = nullptr;
   n->next = temp;
   temp->prev = n;
   this->_last = temp;

  }

  if(temp->next != nullptr) {
   temp->next->prev = temp;
  }


++_size; 
return temp; 

};


/*This new template function dynamically creates a new Node<T> object which encapsulates data and inserts it before n. It also adjusts the 
pointers as necessary, and reutns a pointer to this new Node<T> object. */
// Insert a new Node containing data before n 
//Create a new Node<T> on heap to hold data and assign a pointer to temp 
Node<T>* insert_before(Node<T> *n, const T &data) {     // Insert Node<T> into List<T>
Node<T> *temp = new Node<T>;
temp->data = data;

//Assign tmp->next to n and tmp->prev to n->prev 
if(n->prev != nullptr) {
  temp->prev = n->prev;
  temp->next = n;
  n->prev = temp;  //Assign n->prev to etmp 
}

   else {
      temp->prev = nullptr;
      temp->next = n;
      n->prev = temp;
      this->_first = temp;
   }

   //If tmp->prev is not nullptr then it IS NOT the first Node, set temp->prev->next to temp 
   if (temp->prev != nullptr) {
      temp->prev->next = temp; 
   }

   ++_size;   //increment size 
   return temp;

};



 //This function adds data items to the front of the list 
Node<T>* push_front(const T &data) {// Add data item to front of List

//if the List is empty, then create a new Node containing data and initialize a pointer temp and also assign both _first and _last to tmp, and set _size to 1 
if (this->_size == 0) { 
    Node<T> *temp = new Node<T>(data); 
    _first = temp; 
    _last = temp; 
    _size = 1; 
 
    return temp; 

 }

   //if the List IS NOT empty, invoke insert_after() with this->_last and data, and return the new Node.  
 else {
    return this->insert_before(this->_first, data);   
    }
 };



//This function adds data items to the end of the list
Node<T>* push_back(const T &data) { // Add data item to end of List

//If the List IS empty, create a new Node containing data and initialize a pointer tmp. Assign both _first and _last to tmp, and set _size to 1 
    if (this->_size == 0) {
      Node<T> *temp = new Node<T>(data); 
     _first = temp; 
     _last = temp; 
     _size = 1; 
 
        return temp; 

    }

//If the List IS NOT empty, invoke insert_after() with this->_last and data, and return the new Node. 
  else {
        return this->insert_after(this->_last, data); 
      }
    };





//This function removes the first Node<T> from List<T>
void pop_front(){                // Remove first Node<T> from List<T>

    //if the List IS NOT empty, invoke erase() with this->_first.
    if (this->_size != 0) {
        return this->erase(this->_first); 
    }
 }


//This function removes the last Node<T> from List<T>
void pop_back() {                 // Remove last Node<T> from List<T>

     //if the List IS NOT empty, invoke erase() with this->_last. 
     if (this->_size != 0) {
        return this->erase(this->_last); 
    }
 }

    

};




// Include source code
#include "List.cpp"

// Overload ostream insertion operator for List
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    Node<T> *n = list.first();
    os << "[";
    if (n != nullptr) {
        os << n->data;
        n = n->next;
    }
    while (n != nullptr) {
        os << ", " << n->data;
        n = n->next;
    }
    os << "]";
    return os;
}

#endif
