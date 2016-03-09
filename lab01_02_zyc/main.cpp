#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout<<"the largest value of char="<<(int)numeric_limits<char>::max()<<endl
        <<"the smallest value of char="<<(int)numeric_limits<char>::min()<<endl
        <<"the largest value of wchar_t="<<numeric_limits<wchar_t>::max()<<endl
        <<"the smallest value of wchar_t="<<numeric_limits<wchar_t>::min()<<endl
        <<"the largest value of short="<<numeric_limits<short>::max()<<endl
        <<"the smallest value of short="<<numeric_limits<short>::min()<<endl
        <<"the largest value of int="<<numeric_limits<int>::max()<<endl
        <<"the smallest value of int="<<numeric_limits<int>::min()<<endl

        <<"the largest value of long="<<numeric_limits<long>::max()<<endl
        <<"the smallest value of long="<<numeric_limits<long>::min()<<endl
        <<"the largest value of float="<<numeric_limits<float>::max()<<endl
        <<"the smallest value of float="<<-numeric_limits<float>::max()<<endl
        <<"the largest value of double="<<numeric_limits<double>::max()<<endl
        <<"the smallest value of double="<<-numeric_limits<double>::max()<<endl
        <<"the largest value of unsigned="<<numeric_limits<unsigned>::max()<<endl
        <<"the smallest value of unsigned="<<numeric_limits<unsigned>::min()<<endl
        <<"the largest value of long long="<<numeric_limits<long long>::max()<<endl

        <<"the smallest value of long long="<<numeric_limits<long long>::min()<<endl;
    return 0;
}
