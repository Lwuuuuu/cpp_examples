#include <iostream>
#include <vector>
#include <string>
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

template<typename T>
class Vec : public vector<T>{
    public:
        using vector<T>::vector; //use the constructor from vector under the name Vec

        T& operator[](int i) //Range checking 
            {return vector <T>::at(i);} // at() operation is a vector subscript operation that throws an exception of type out_of_range if its argument is out of range
        const T& operator[](int i) const   //Range Checkign for const objects
            { return vector<T>::at(i);}
};

int main() {
    Vec<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}
    };
    cout << phone_book[5];

}