#include <map>
#include <iostream>
using namespace std;

int get_number(map<string, int> phone_book, const string& s){
    return phone_book[s];
}


int main() {
    map<string, int> phone_book { //Container of pairs of values optimized for lookup
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}
    };  //Container of pairs of values optimized for lookup
    //When indexed by a value of its first type (called key) a map returns the corresponding value of the second type called the value
    int ans = get_number(phone_book, "David Hume");
    cout << ans << endl;
}