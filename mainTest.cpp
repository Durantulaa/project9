#include <climits>
#include <iostream>
#include <string>

using namespace std;

#include "main.h"

// All tests are controlled by a dedicated function
void TestInsert();
void TestCopyConstructor();
void TestDelete();
void TestSort();

int main() {
  TestInsert();
  TestCopyConstructor();
  TestSort();
  TestDelete();
}

void TestInsert() {

  ListD *lst = new ListD;
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

void TestSort() {
  ListD *lst3 = new ListD;
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

void TestCopyConstructor() {
  ListD *lst1 = new ListD;
  for (int i = 1; i <= 5; i++)
    lst1->Insert(i, i);

  ListD *lst2(lst1);

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

// void TestDelete() {
//   ListD *lst2 = new ListD;
//   int i = 0;
//   while (i <= 10) {
//     lst2->Insert(i, i);
//     i++;
//   }
  
//   cout << "Before delete: \n";
//   lst2->PrintForward();

//   // lst2->Delete(50);
//   // lst2->Delete(100);
//   // lst2->Delete(0);
//   cout << "Passed if  0, 50, and 100 get deleted from the list \n" << endl;
//   lst2->PrintForward();

//     while ( i != 10){
//     lst2->DeleteAll(i);
//     i++;
//     }
//     lst2->PrintForward();  
//   cout << "if this works everything in the list will be deleted \n";

//   delete lst2; 
// }

void TestDelete() {
  ListD *lst2 = new ListD;
  int i = 0;
  while (i <= 10) {
    lst2->Insert(i, i);
    i++;
  }

  cout << "Before delete: \n";
  lst2->PrintForward();

  // Attempt to delete elements that may or may not exist
  cout << "Attempting to delete elements 0, 50, and 100:\n";
  lst2->Delete(0);
  lst2->Delete(50);
  lst2->Delete(100);

  cout << "List after attempted deletions:\n";
  lst2->PrintForward();

  // Delete all elements from the list
  i = 0;
  while (i <= 10) {
    lst2->DeleteAll(i);
    i++;
  }

  cout << "List after deleting all elements:\n";
  lst2->PrintForward();

  // Deallocate memory
  delete lst2;
}



// fix deleteall and delete function
