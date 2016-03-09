#include <iostream>
#include <limits>
#include <float.h>
using namespace std;

int main()
{
    cout << "char " <<(int)numeric_limits<char>::max()
         << "\nchar " <<(int)numeric_limits<char>::min()
         << "\nwchar_t " <<numeric_limits<wchar_t>::max()
         << "\nwchar_t " <<numeric_limits<wchar_t>::min()
         << "\nshort " <<numeric_limits<short>::max()
         << "\nshort " <<numeric_limits<short>::min()
         << "\nint " <<numeric_limits<int>::max()
         << "\nint " <<numeric_limits<int>::min()
         << "\nlong " <<numeric_limits<long>::max()
         << "\nlong " <<numeric_limits<long>::min()
         << "\nfloat " <<FLT_MAX
         << "\nfloat " <<-FLT_MAX
         << "\ndouble " <<numeric_limits<double>::max()
         << "\ndouble " <<-numeric_limits<double>::max()
         << "\nunsigned " <<numeric_limits<unsigned>::max()
         << "\nunsigned " <<numeric_limits<unsigned>::min()
         << "\nlonglong " <<LONG_LONG_MAX
         << "\nlonglong " <<LONG_LONG_MIN
         << endl;
    return 0;
}
