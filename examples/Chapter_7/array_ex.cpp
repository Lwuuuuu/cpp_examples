#include <iostream>
using namespace std;

int main() {
    //char* p = "Plato"; //Forbidden from converting a string constant to char*
    char p[] = "Plato"; //Works, placed in a non-const array 
    p[4] = 'e'; 
    cout << p << endl; //Able to print out the whole array of chars

    int x[4] {1,2,3,4};
    x[2] = 10;
    cout << x[2] << endl;

    const char* g = "Heraclitus";
    const char* h = "Heraclitus";
    if (g == h) cout << "one!\n";

    int d1 = 10;
    int d2 = 10;
    int* v1 = &d1;
    int* v2 = &d2;
    cout << *v1 << " " << *v2 << endl;
    if (*v1 == *v2) cout << "Two\n";

    //Using reference
    int d3 = 10;
    int d4 = 10;
    int& v3 = d3;
    int& v4 = d4;
    cout << v3 << " " << v4 << "\n";
    if (v3 == v4) cout << "Two\n";
}