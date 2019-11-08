#include <iostream>
#include <vector>
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

void print_book(const vector<Entry>& book){
    for(const auto& v: book) { 
        cout << v << endl;
    }
}

void input(vector<Entry>& phone_book) {
    for (Entry e; cin >> e;)
        phone_book.push_back(e);
}

int main() {
    vector<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}
    };
    input(phone_book);
    print_book(phone_book);
}