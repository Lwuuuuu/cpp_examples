#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <iterator>
using namespace std;

ostream_iterator<string> oo {cout};
istream_iterator<string> li {cin};
istream_iterator<string> eos {};

int main() {
    *oo = "Hello, "; //The effect of assigning values to *oo is that they will be cout 
    ++oo; //Mimics  writing into an array through a pointer
    *oo = "world!\n";
}