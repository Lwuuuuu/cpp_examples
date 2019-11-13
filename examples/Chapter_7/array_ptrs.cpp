#include <iostream>
using namespace std;

void f(char v[], int size) {
    for (int i = 0; i != size; ++ i)
        cout << v[i] << endl;
    char xz[10];
    for (int x : xz) { //Works because the size of the array is known within this function 
        cout << x << endl;
    }
}

int main() {
    int v[] {1,2,3,4};
    int* p1 = v;
    int* p2 = &v[0];
    int* p3 = v+4;
    cout << *p1 << " " << *p2 << " " << *p3 << endl;
    char x[] = "Hello";
    f(x, 5);
}