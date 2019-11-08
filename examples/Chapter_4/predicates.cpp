#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <functional>
#include <map>
using namespace std;

struct Greater_than {
    int val;
    Greater_than(int v) :val{v} {}
    bool operator()(const pair<string,int>& r) { return r.second>val;}
};


map<string, int>::const_iterator f(const map<string,int>& m){ 
    auto p = find_if(m.begin(), m.end(), Greater_than{400000});
    return p;
}

int main() {
    const map<string, int> phone_book { //Container of pairs of values optimized for lookup
        {"David Hume", 523456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678},
        {"Asta", 9999999}
    };
    map<string, int>::const_iterator z = f(phone_book);
    for (auto ii = phone_book.begin(); ii != phone_book.end(); ++ii) {
        cout << ii->first << " " << ii->second << endl; 
    }
    cout << "First Val found " << z->first << " " << z->second; 

}