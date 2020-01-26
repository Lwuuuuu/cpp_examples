#include <iostream>
using namespace std;


int main() {
    int x[] {1,2,3,4,5};
    for (int& z : x) {
        ++z;
        cout << z << endl;
    }
    for (int z : x) {
        cout << z << endl;
    }
}