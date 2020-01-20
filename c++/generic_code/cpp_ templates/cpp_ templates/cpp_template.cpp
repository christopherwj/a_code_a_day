// function template
#include <iostream>
using namespace std;

//code is heavily borrowed from:http://www.cplusplus.com/doc/oldtutorial/templates/

template <class T>
T GetMax(T a, T b) {
    T result;
    result = (a > b) ? a : b;
    return (result);
}

template <class T>
T Average(T a, T b) {
    T result;
    result = a + b;
    result /= 2;
    return (result);

}

int main() {
    int i = 10, j = 15, k;
    long l = 10, m = 5, n;
    k = GetMax<int>(i, j);
    n = GetMax<long>(l, m);
    cout << k << endl;
    cout << n << endl;

    /*
    int function variant 
    due to int data type, value is always casted down to nearest int
    thus code should be added for protection of values.
    */

    int a = 5, b = 5, c;    
    float d = 12.4, e = 6.0, f;
    f = Average<float>(d, e);
    cout << f << endl;

    if ((a+b) % 2 != 0) {
        cout << "Please enter in two numbers whose sum is divisible by 2.";
        exit;
    }
    else {
        c = Average<int>(a, b);
        cout << c << endl;
    }
    return 0;
}


