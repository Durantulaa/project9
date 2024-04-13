/*
Team Members: Steph Borla , Daisy , And Fady Youssef
Course: CPSC122
Date Submitted: 4/07/2024
Assignment Name: Project 9
*/

#include <climits>
#include <iostream>
using namespace std;

#include "main.h"

ListD::ListD() { InitializeVars(); } // done

ListD::~ListD() {
  // Delete every node in list
  doubleNode *curr = head->next;
  doubleNode *tmp = curr;

  while (curr != tail) {
    curr = curr->next;
    delete tmp;
  }

  delete tail;
  delete head;
  length = 0;

  cout << "destructor called \n";
} // done

void ListD::InitializeVars() {
  length = 0;

  // create dummy nodes;
  head = new doubleNode;
  tail = new doubleNode;

  // set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  // set values for tail dummy node;
  tail->prev = head;
  tail->item = INT_MAX;
  tail->next = NULL;
} // done

ListD::ListD(ListD *lst) {
  InitializeVars();
  // returns a pointer to the first node, which is what we want here
  doubleNode *cur = lst->FindPosition(2);
  for (int i = 1; i <= lst->length; i++) {
    cout << cur->item << endl;
    Insert(cur->item, i);
    cur = cur->next;
  }
} // done

doubleNode *ListD::FindPosition(int pos) {
  // Inserting at the tail is a special case.  It can be made much more
  // efficient than this.

  // if (pos < 1 || pos > length){
  //   cout << "invalid pos \n";
  //   return nullptr;
  // }

  doubleNode *cur = head;
  int i = 0; // begin at the dummy node
  while (i < pos - 1) {
    cur = cur->next;
    i++;
  }
  return cur;
} // done

void ListD::Insert(itemType item, int pos) {
  doubleNode *tmp = new doubleNode;
  // new node goes between these two nodes
  doubleNode *insertPtA = FindPosition(pos);
  doubleNode *insertPtB = insertPtA->next;

  tmp->item = item;
  insertPtA->next = tmp;
  insertPtB->prev = tmp;
  tmp->prev = insertPtA;
  tmp->next = insertPtB;

  // set pointers for nodes before and after the insertion point
  //  insertPtA -> next = tmp;
  //  insertPtB -> prev = tmp;
  length++;
} // done

void ListD::Delete(int pos) {
  doubleNode *ptA = FindPosition(pos);
  
  // if (ptA == nullptr) {
  //   cout << "Invalid position for deletion" << endl;
  //   return;
  // }
  
  doubleNode *delptB = ptA->next;
  doubleNode *ptC = delptB->next;

  ptA->next = ptC;
  ptC->prev = ptA;
  delete delptB;
  length--;
  
} // done

int ListD::DeleteAll(itemType item) {
  int count = 0;
  doubleNode *cur = head->next;

  while (cur != tail) {
    if (cur->item == item) {
      doubleNode *tmp = cur;
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

void ListD::Sort() {
  doubleNode *curr = head->next;

  if (length == 1 || length == 0) {
    cout << "List is sorted\n";
    return;
  }
  
  while (curr->next != nullptr) {
    doubleNode *min = curr;
    doubleNode *tmp = curr->next;

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
}//done

void ListD::PrintForward() {
  doubleNode *cur = head->next;

  int i = 0;
  while (i < length) {
    cout << cur->item << endl;
    cur = cur->next;
    i++;
  }
  cout << endl;

} // done

void ListD::PrintBackward() {
  doubleNode *cur = tail->prev;

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