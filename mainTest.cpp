#include <iostream>
using namespace std;

#include "main.h"

// All tests are controlled by a dedicated function
void TestInsert();
void TestCopyConstructor();
void TestDelete();

int main() {
  TestInsert();
  TestCopyConstructor();
  TestDelete();
}

void TestInsert() {

  ListD *lst = new ListD;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i, i);

  cout << "test general case insert \n" << endl;
  cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines \n";
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the head" << endl;
  lst->Insert(0, 1);
  cout << "Passed Insert Test 2 if 0 appears in position 1" << endl;
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the tail" << endl;
  lst->Insert(100, 7);
  cout << "Passed Insert Test 3 if 100 appears in final position" << endl;
  lst->PrintForward();
  cout << endl;

  cout << "test insert within the list" << endl;
  lst->Insert(50, 5);
  cout << "Passed Insert Test 4 if 50 appears in middle position" << endl;
  lst->PrintForward();
  cout << endl;
  // delete lst;
}

void TestCopyConstructor() {
  ListD *lst1 = new ListD;
  for (int i = 1; i <= 3; i++)
    lst1->Insert(i, i);

  ListD *lst2(lst1);

  cout << "Test Copy Constructor" << endl;
  cout << "Test passed if copy is indentical to initial list" << endl;
  cout << "Traverse inital list: " << endl;
  lst1->PrintForward();
  cout << endl;
  cout << "Traverse copy: " << endl;
  lst2->PrintForward();
  cout << endl;
  cout << "Reveresed Copy: " << endl;
  lst2->PrintBackward();

  // delete lst1;
  // delete lst2;
}

void TestDelete() {
  ListD *lst2 = new ListD;
  // int i=0;
  // while ( i <= 10){
  //   lst2->Insert(i, i);
  //   i++;
  // }

  cout << "Passed if  0, 50, and 100 get deleted from the list \n" << endl;
  lst2->Delete(50);
  lst2->Delete(100);
  lst2->Delete(0);
  lst2->PrintForward();

  //   cout << "if this works everything in the list will be deleted \n";
  //   while ( i != 10){
  //   lst2->DeleteAll(i);
  //   i++;
  //   }
  //   lst2->PrintForward();
}

void testSort() {
  ListD *lst3 = new ListD;
  // lst3->Sort(lst3);
}

// fix deleteall and delete function
//  make a function to check sort
