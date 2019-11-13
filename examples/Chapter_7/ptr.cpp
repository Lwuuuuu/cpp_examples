#include <iostream>
#include <vector>
using namespace std;


void f(int n) {
    int v1[n];
    cout << v1[0] << endl;
    vector<int> v2(n);
    cout << v2[0] << endl;
}

int main() {
    char* a[32];
    char c = 'a';
    a[20] = &c;
    cout << *a[20] << endl;
    char b[32];
    b[10] = 'l';
    cout << "-----------------" << endl;
    cout << b[10] << endl;
    int n = 10;
    f(n);
}