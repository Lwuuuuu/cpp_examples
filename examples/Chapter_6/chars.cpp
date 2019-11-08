#include <iostream>
using namespace std;


int main() {
    for (int i = 0; i != 10; ++i) {
        cout << static_cast<int>('0' + i) << "\n\n";
    }
}