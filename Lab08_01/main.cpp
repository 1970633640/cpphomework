//----------------------------------------------------------------------
//
// testSQ.cpp : Test program for Lab 8.
//
//----------------------------------------------------------------------

#include "queue2.h" // copy from squeue1.h or squeue2.h

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()

{ StrQueue sq;
  cout << "Enqueue:  " << endl;
  string a[]{"Str1","Str2","Str3","Str4","Str5","Str6"};
  int i;
  for (i=0;i<6;i++)
  {
      sq.enqueue(a[i]);
  cout << a[i] << endl;
  }
  cout << endl;

  cout << "Dequeue:  " << endl;
  while (!sq.isEmpty()) cout << sq.dequeue() << endl;
  cout << endl;

  cout << "Enter a sequence of strings to enqueue(^Z to end): " << endl;
  string s; while (cin >> s) sq.enqueue(s);
  cout << endl;

  cout << "Dequeue:  " << endl;
  while (!sq.isEmpty()) cout << sq.dequeue() << endl;
  cout << endl;
  return 0;
}
