/*
Team Members: Liya Tekie, Steph Borla , Daisy Barajas , And Fady Youssef
Course: CPSC122
Date Submitted: 4/07/2024
Assignment Name: Project 9
*/

#include <climits>
#include <iostream>
using namespace std;

#include "main.h"

template <typename T> 
ListD<T>::ListD() { InitializeVars(); } // done

template <typename T> 
ListD<T>::~ListD() {
  // Delete every node in list
  doubleNode<T> *curr = head->next;
  doubleNode<T> *tmp = curr;

  while (curr != tail) {
    curr = curr->next;
    delete tmp;
  }

  delete tail;
  delete head;
  length = 0;

  cout << "destructor called \n";
} // done

template <typename T> 
void ListD<T>::InitializeVars() {
  length = 0;

  // create dummy nodes;
  head = new doubleNode<T>;
  tail = new doubleNode<T>;

  // set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  // set values for tail dummy node;
  tail->prev = head;
  tail->item = INT_MAX;
  tail->next = NULL;
} // done

template <typename T> 
ListD<T>::ListD(const ListD<T> &lst) {
  InitializeVars();
  // returns a pointer to the first node, which is what we want here
  doubleNode<T> *cur = lst->FindPosition(2);
  for (int i = 1; i <= lst->length; i++) {
    cout << cur->item << endl;
    Insert(cur->item, i);
    cur = cur->next;
  }
} // done

template <typename T> 
doubleNode<T> *ListD<T>::FindPosition(int pos) {
  // Inserting at the tail is a special case.  It can be made much more
  // efficient than this.

  // if (pos < 1 || pos > length){
  //   cout << "invalid pos \n";
  //   return nullptr;
  // }

  doubleNode<T> *cur = head;
  int i = 0; // begin at the dummy node
  while (i < pos - 1) {
    cur = cur->next;
    i++;
  }
  return cur;
} // done

template <typename T> 
void ListD<T>::Insert(T item, int pos) {
  doubleNode<T> *tmp = new doubleNode<T>;

  // new node goes between these two nodes
  doubleNode<T> *insertPtA = FindPosition(pos);
  doubleNode<T> *insertPtB = insertPtA->next;

  tmp->item = item;

  // set pointers for nodes before and after the insertion point
  insertPtA->next = tmp;
  insertPtB->prev = tmp;

  tmp->prev = insertPtA;
  tmp->next = insertPtB;

  length++;
} // done

template <typename T> 
void ListD<T>::Delete(int pos) {
  doubleNode<T> *ptA = FindPosition(pos);

  // if (ptA == nullptr) {
  //   cout << "Invalid position for deletion" << endl;
  //   return;
  // }

  doubleNode<T> *delptB = ptA->next;
  doubleNode<T> *ptC = delptB->next;

  ptA->next = ptC;
  ptC->prev = ptA;
  delete delptB;
  length--;

} // done

template <typename T> 
int ListD<T>::DeleteAll(T item) {
  int count = 0;
  doubleNode<T> *cur = head->next;

  while (cur != tail) {
    if (cur->item == item) {
      doubleNode<T> *tmp = cur;
      cur = cur->next;
      delete tmp;
      count++;
      length--;
    } else {
      cur = cur->next;
    }
  }

  return count;
} // done

template <typename T> 
void ListD<T>::Sort() {
  doubleNode<T> *curr = head->next;

  if (length == 1 || length == 0) {
    cout << "List is sorted\n";
    return;
  }

  while (curr->next != nullptr) {
    doubleNode<T> *min = curr;
    doubleNode<T> *tmp = curr->next;

    while (tmp != nullptr) {
      if (tmp->item < min->item) {
        min = tmp;
      }
      tmp = tmp->next;
    }
    itemType tmpI = curr->item;
    curr->item = min->item;
    min->item = tmpI;
    curr = curr->next;
  }
} // done

template <typename T> 
void ListD<T>::PrintForward() {
  doubleNode<T> *cur = head->next;

  int i = 0;
  while (i < length) {
    cout << cur->item << endl;
    cur = cur->next;
    i++;
  }
  cout << endl;

} // done

template <typename T> 
void ListD<T>::PrintBackward() {
  doubleNode<T> *cur = tail->prev;

  int i = 0;
  while (i < length) {
    cout << cur->item << endl;
    cur = cur->prev;
    i++;
  }
  cout << endl;
} // done

// https://docs.google.com/document/d/189EUPz9t83PKBPAtBK05MzyNtTs74_CLYAPEx-lGeyw/edit
// https://www.youtube.com/watch?v=2ybLD6_2gKM
// make sure to use template