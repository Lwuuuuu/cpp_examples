#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;


bool has_c(const string& s, char c) {
    auto p = find(s.begin(), s.end(), c); //find would return end() to indicate not found
    if (p != s.end())
        return true;
    else
        return false;
}

vector<string::iterator> find_all(string& s, char c) { //Vector of iterators on strings where the string the iterator refers to is char c 
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); ++p) { 
        if (*p == c) {
            res.push_back(p);
        }
    }
    return res;
}

void test() { 
    string m = "Mary had a little lamb";
    for (auto p: find_all(m, 'a')) {
        if (*p != 'a') 
            cout << "a bug\n";
    }
}

int main() {
    string v = "Hello";
    char c = 'l';
    // int ans = has_c(v, c);
    // cout << ans << endl;
    // vector<string::iterator> x = find_all(v, c);
    test();
}