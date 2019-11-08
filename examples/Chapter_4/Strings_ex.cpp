#include <string>
#include <iostream>
using namespace std;

//The string type provides a variety of useful string operations, such as concatenation 

string compose(const string& name, const string& domain) {
    return name + '@' + domain;
}

void m2(string& s1, string& s2){
    //Strings are mutable
    s1 += '\n';
    s2 += '\n';
}

void m3(string& name) { 
    string s = name.substr(6,10);  //Returns a string that is a copy of the substring indicated by its argument
    name.replace(0,5, "nicholas");
    name[0] = toupper(name[0]);
}

//Standard strings have a move constructor so returning long strings by value is efficient 

int main() {
    string addr = compose("dmr", "bell-labs.com");
    cout << "addr " << addr << endl;
    string s1 = {"Hello"};
    string s2 = {"World"};
    m2(s1, s2);
    cout << "s1 " << s1;
    cout << "s2 " << s2; 
    string name = "Niels Stroustrup";
    m3(name);
    cout << "Name " << name << endl;

}