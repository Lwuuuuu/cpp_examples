#include <array>
#include <iostream>
using namespace std;


int main() {
    array<int, 3> x {1,2,3}; //Disadvantage of std::array is that we can't deduce the number of elements from the length of the initializer 
    cout << x.size() << endl;

}