#include<string>
#include<iostream>
using namespace std;

//User-defined Types 
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

void f(){
    int i ;
    cin >> i;
    cout << "i " << i << endl;
}

void hello_line() {
    cout << "Enter Name\n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
}
int main(){
    Entry e;
    cin >> e;
    cout << e;
}