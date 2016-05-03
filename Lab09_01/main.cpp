//----------------------------------------------------------------------
//
// intset2Test.cpp : Test program for Lab 9.
//
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "intset.h"  // your header file for new class intset

int main(int argc,char**argv)
try
{
    // ***** test for initialization *****
    intset a{100};  // an integer set with 100 maximum elements
    intset b{100};  // an integer set with 100 maximum elements

    // ***** test for output operator <<  *****
    cout << "Set a after initialization: " << endl
         << a         // display set a
         << endl;

    // ***** test for function call operator () using as elements counting *****
    cout << "The number of elements of Set a: " << a() <<endl;

    cout << "Set b after initialization: " << endl
         << b         // display set b
         << endl;
    cout << "The number of elements of Set b: " << b() <<endl << endl;


    // ***** test for inserting *****

    for (int i{100};i<150;i++)
        a.insert(i);        // insert 50 elements from 100 to 149
    for (int i{120};i<160;i++)
        b.insert(i);        // insert 40 elements from 120 to 159

    cout << "Set a after insertion: " << endl
         << a         // display set a
         << endl;
    cout << "The number of elements of Set a: " << a() <<endl;
    cout << "Set b after insertion: " << endl
         << b         // display set b
         << endl;
    cout << "The number of elements of Set b: " << b() <<endl;
    cout << endl;

    // ***** test for union operator | *****

    cout << "Union of two integer sets a and b: " << endl
         << a << " ¡È " << b << " = " << (a|b) << endl << endl;

    // ***** test for intersection operator & *****

    cout << "Intersection of two integer sets a and b: " << endl
         << a << " ¡É " << b << " = " << (a&b) << endl << endl;

    // ***** test for difference operator - *****

    cout << "Difference of two integer sets a and b: " << endl
         << a << " £­ " << b << " = " << a-b << endl << endl;

    cout << "Difference of two integer sets b and a: " << endl
         << b << " £­ " << a << " = " << b-a << endl << endl;

    // ***** test for symmetric difference *****

    cout << "Symmetric difference of two integer sets a and b: " << endl
         << a << " symmetric£­ " << b << " = "
         << a.setsymmetricdifference(b) << endl << endl;

    // ***** test for assignment operator = *****

    cout << "Set a after assignment a=b: " << endl;
    a = b;
    cout << a << endl << endl;

    // ***** test for clear *****

    cout << "Set b after erasing all elements: " << endl;
    b.clear();
    cout << b << endl << endl;

    // ***** test for empty *****

    if (a.empty()) cout << "Set a is empty " << endl << endl;
    else cout << "Set a is not empty " << endl << endl;

    if (b.empty()) cout << "Set b is empty " << endl << endl;
    else cout << "Set b is not empty " << endl << endl;

    // ***** test for erase *****

    cout << "Set a after erasing an element 150: " << endl;
    a.erase(150);
    cout << a << endl << endl;

    cout << "Set a after erasing an element 250: " << endl;
    a.erase(250);
    cout << a << endl << endl;

    // ***** test for subset *****

    if (a.subset(b)) cout << "Set b is a subset of a" << endl << endl;
    else cout << "Set b is not a subset of a" << endl << endl;

    cout << "Insert an element 500 into set b: " << endl;
    b.insert(500);
    cout << endl;

    if (a.subset(b)) cout << "Set b is a subset of a" << endl << endl;
    else cout << "Set b is not a subset of a" << endl << endl;


    intset c{200}, d{200},e{200};

    // ***** test for input operator >> *****

    cout << "Input intset c and d with form "
            "\"NumberOfElements element1 element2 ...\"" << endl;
    cin >> c >> d;
    cout << endl;
    cout << " c = " << c << endl << " d = " << d << endl << endl;

    cout << " a=c,b=d " << endl;
    a = c, b = d;
    cout << " a = " << a << endl << " b = " << b << endl << endl;

    // ***** test for operator |= *****

    cout << " e=c|=d " << endl;
    e = c |= d;
    cout << " c = " << c << endl << " d = " << d << endl
         << " e = " << e << endl << endl;

    cout << " c=a,d=b " << endl;
    c = a, d = b;
    cout << " c = " << a << endl << " d = " << b << endl << endl;

    // ***** test for operator &= *****

    cout << " e=c&=d " << endl;
    e = c &= d;
    cout << " c = " << c << endl << " d = " << d << endl
         << " e = " << e << endl << endl;

    cout << " c=a,d=b " << endl;
    c = a, d = b;
    cout << " c = " << a << endl << " d = " << b << endl << endl;

    // ***** test for operator -= *****

    cout << " e=c-=d " << endl;
    e = c -= d;
    cout << " c = " << c << endl << " d = " << d << endl
         << " e = " << e << endl << endl;

   cout << " c=a,d=b " << endl;
   c = a, d = b;
   cout << " c = " << a << endl << " d = " << b << endl << endl;

   cout << " e=d-=c " << endl;
   e = d -= c;
   cout << " c = " << c << endl << " d = " << d << endl
        << " e = " << e << endl << endl;

    // ***** test for exception throwing *****

    cout << "Insert 500 elements from 1000 to 1499 into set a: " << endl;
    for (int i{1000};i<1500;i++)
        a.insert(i);        // insert 500 elements from 1000 to 1499
    return 0;

}

  // ***** exception handling *****

catch(intset::bad_intset bi)  // catch exceptions related to integer set
{ switch (bi.errnum)          // # of exceptions
  { case 1: cerr << "bad intset: constructor parameter<1 , exit " << endl;
			                // error of constructor parameter
            break;
    case 2: cerr << "bad intset: maximum elements reached, exit " << endl;
 		                       // overflow of integer set
            break;
  }
  return 0;
}
