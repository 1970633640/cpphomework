//----------------------------------------------------------------------
//
// intsetTest.cpp : Test program for Lab 7.
//
//----------------------------------------------------------------------

#include <iostream>


#include "intset.h"  // your header file for class intset
using namespace std;
int main(int argc,char**argv)
{


    // ***** test for initialization *****

    intset a{100};  // an integer set with 100 maximum elements
    intset b{30};  // an integer set with 30 maximum elements

    // ***** test for printing *****

    cout << "Set a after initialization: " << endl;
    a.print();     // display set
    cout << endl;

    // ***** test for counting *****

    cout << "The number of elements in Set a : " << a.count() <<endl;

    cout << "Set b after initialization: " << endl;
    b.print();         // display set
    cout << endl;
    cout << "The number of elements in Set b : " << b.count() <<endl;
    cout << endl;

    // ***** test for inserting *****

    for (int i{100};i<150;i++)
      a.insert(i);        // insert 50 elements from 100 to 149
    for (int i{130};i<160;i++)
      b.insert(i);        // insert 30 elements from 130 to 159

    cout << "Set a after insertion: " << endl;
    a.print();         // display set
    cout << endl;
    cout << "The number of elements of Set a : " << a.count() <<endl;
    cout << "Set b after insertion: " << endl;
    b.print();         // display set
    cout << endl;
    cout << "The number of elements of Set b : " << b.count() <<endl;
    cout << endl;

    // ***** test for union *****

    cout << "Union of two integer sets a and b: " << endl;
    a.print();         // display set
    cout << " ∪ ";
    b.print();         // display set
    cout << " = ";
    intset r1{a.setunion(b)};   // compute union of two integer sets
    r1.print();                 // display union result
    cout << endl;
    cout << endl;

    // ***** test for intersection *****

    cout << "intersection of two integer sets a and b: " << endl;
    a.print();
    cout << " ∩ ";
    b.print();
    cout << " = ";
    intset r2{a.setintsection(b)};    // compute intersection of two integer sets
    r2.print();
    cout << endl;
    cout << endl;

    // ***** test for difference *****

    cout << "difference of two integer sets a and b: " << endl;
    a.print();
    cout << " － ";
    b.print();
    cout << " = ";
    intset r3{a.setdifference(b)};     // compute difference of two integer sets
    r3.print();
    cout << endl;
    cout << endl;

    cout << "difference of two integer sets b and a: " << endl;
    b.print();
    cout << " － ";
    a.print();
    cout << " = ";
    intset r4{b.setdifference(a)};     // compute difference of two integer sets
    r4.print();
    cout << endl;
    cout << endl;

    // ***** test for symmetric difference *****

    cout << "symmetric difference of two integer sets a and b: " << endl;
    a.print();
    cout << " symmetric－ ";
    b.print();
    cout << " = ";
    intset r5{a.setsymmetricdifference(b)};   // compute symmetric difference of two integer sets
    r5.print();
    cout << endl;
    cout << endl;

    // ***** test for assignment *****

    cout << "Set a after assignment a=b : " << endl;
    a=b;
    a.print();
    cout << endl;
    cout << endl;

    // ***** test for "clear" *****

    cout << "Set b after erasing all elements : " << endl;
    b.clear();
    b.print();
    cout << endl;
    cout << endl;

    // ***** test for "empty" *****

    if (a.empty()) cout << "Set a is empty " << endl;
    else cout << "Set a is not empty " << endl;
    cout << endl;

    if (b.empty()) cout << "Set b is empty " << endl;
    else cout << "Set b is not empty " << endl;
    cout << endl;

    // ***** test for "erase" *****

    cout << "Set a after erasing an element 140 : " << endl;
    a.erase(140);
    a.print();
    cout << endl;
    cout << endl;
    cout << "Set a after erasing an element 250 : " << endl;
    a.erase(250);
    a.print();
    cout << endl;
    cout << endl;

    // ***** test for "subset" *****

    if (a.subset(b)) cout << "Set b is a subset of a" << endl;
    else cout << "Set b is not a subset of a" << endl;
    cout << endl;

    cout << "insert an element 500 into set b : " << endl;
    b.insert(500);

    cout << "Set b : " << endl;
    b.print();
    cout << endl;

    cout << endl;

    if (a.subset(b)) cout << "Set b is a subset of a" << endl;
    else cout << "Set b is not a subset of a" << endl;
    cout << endl;


    // ***** test for exception throwing *****

    cout << "insert 500 elements from 1000 to 1499 into set a : " << endl;
    for (int i{1000};i<1500;i++)
      a.insert(i);        // insert 500 elements from 1000 to 1499

    return 0;
  }



