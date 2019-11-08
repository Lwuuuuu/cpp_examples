#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
struct Entry {
    string name;
    int number;
    //Entry(string x, int y) :name{x}, number{y} {}
};
ostream& operator<<(ostream& os, const Entry& e){ 
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e){ 
    char c, c2;
    if(is>>c && c == '{' && is>>c2 && c2 == '"') { //is>>c skips whitespace, eliminates the readings of { and the first " from cin 
        string name;
        while(is.get(c) && c != '"') //Does not skip whitespace, so skips whitespace outside the name string, but not within. Reads the next bytes off the stream till "
            name += c;
        if (is >> c && c == ',') { 
            int number = 0 ;
            if (is >> number >> c && c == '}') {
                e = {name,number};
                return is;
            }
        }
    }
    is.setstate(ios_base::failbit);
    return is;
}

int get_number(const list<Entry>& book, string s){
    for(const auto& x : book) { 
        if (x.name == s)
            return x.number;
    }
    return 0;
}

void add_and_delete(list<Entry>& book, const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q) {
    advance(p, 1);
    advance(q, -1);
    book.insert(p, ee);
    book.erase(q);
}

int main() {
    list<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}
    };
    int ans = get_number(phone_book, "Karl Popper");
    auto start = phone_book.begin();
    auto last = phone_book.end();
    cout << start->name;
    advance(last, -1);
    cout << last->name;
    add_and_delete(phone_book, {"Lawrence Wu", 98787}, start, last);
    // auto a = phone_book.begin();
    // auto b = phone_book.end();
    // for (auto l_front = a; l_front != b; ++l_front) {

    //     cout << l_front->name << l_front->number << endl;
    // }
}