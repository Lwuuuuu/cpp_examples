#include <iostream>
#include <vector>
#include <memory>
using namespace std;


void f(int i, int j) {
    double* p = new double;
    unique_ptr<double> sp {new double}; //ensures that its object is properly destroyed whichever way we exit f()
    if (i < 99) throw out_of_range("Not really");
    if (j < 77) return 
    delete p;


}

int main() {
    // f(100, 50);

}