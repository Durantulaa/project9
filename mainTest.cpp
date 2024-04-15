#include <climits>
#include <iostream>
#include <string>

using namespace std;

#include "main.cpp"
#include "main.h"

// All tests are controlled by a dedicated function
template <typename T> void TestInsert();
template <typename T> void TestCopyConstructor();
template <typename T> void TestDelete();
template <typename T> void TestSort();

int main() {
  TestInsert<int>();
  TestCopyConstructor<int>();
  TestSort<int>();
  TestDelete<int>();
}

template <typename T> 
void TestInsert() {

  ListD<T> *lst = new ListD<T>;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i, i);

  cout << "test general case insert:" << endl;
  cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines \n";
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the head" << endl;
  cout << "Passed Insert Test 2 if 0 appears in position 1" << endl;
  lst->Insert(0, 1);
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the tail" << endl;
  cout << "Passed Insert Test 3 if 100 appears in final position" << endl;
  lst->Insert(100, 7);
  lst->PrintForward();
  cout << endl;

  cout << "test insert within the list" << endl;
  lst->Insert(50, 5);
  cout << "Passed Insert Test 4 if 50 appears in middle position" << endl;
  lst->PrintForward();
  cout << endl;
  // delete lst;
}

template <typename T> 
void TestSort() {
  ListD<T> *lst3 = new ListD<T>;
  cout << "test sort within the list" << endl;
  // for (int i = 20; i <= 200; i += 10) {
  //   for (int j = 1; i <= 6; j++) {
  //     lst3->Insert(i, j);
  //   }
  // }
  int i = 0;
  while (i <= 10) {
    lst3->Insert(i, i);
    i++;
  }

  lst3->Sort();
  lst3->PrintForward();
  cout << endl;
}

template <typename T> 
void TestCopyConstructor() {
  ListD<T> *lst1 = new ListD<T>;
  for (int i = 1; i <= 5; i++)
    lst1->Insert(i, i);

  ListD<T> *lst2(lst1);

  cout << "Test Copy Constructor" << endl;
  cout << "Test passed if copy is indentical to initial list" << endl;
  cout << "Traverse inital list: " << endl;
  lst1->PrintForward();
  cout << "Traverse copy: " << endl;
  lst2->PrintForward();
  cout << "Reveresed Copy: " << endl;
  lst2->PrintBackward();

  // delete lst1;
  // delete lst2;
}

template <typename T> 
void TestDelete() {
  ListD<T> *lst2 = new ListD<T>;
  int i, j = 0;
  while (i <= 10) {
    lst2->Insert(i, i);
    i++;
  }

  cout << "Before delete: \n";
  lst2->Sort();
  lst2->PrintForward();

  // Attempt to delete elements that may or may not exist
  cout << "Attempting to delete element 3, 6, 9:\n";
  lst2->Delete(3); // deletes 3
  lst2->Delete(5); // deletes 6
  lst2->Delete(7); // deletes 9

  cout << "List after element deletion:\n";
  lst2->Sort();
  lst2->PrintForward();

  // Delete all elements from the list
  while (j <= 10) {
    lst2->DeleteAll(j);
    j++;
  }

  cout << "List after deleting all elements:\n";
  lst2->PrintForward();

  // Deallocate memory
  // delete lst2;
}

// find out why delete has issues with 0
// put in template form
