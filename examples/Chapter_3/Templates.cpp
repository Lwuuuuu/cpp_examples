#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;

template<typename T> //prefix makes T a parameter of the declaration it prefixes. C++ version of "for all T or "for all types T"
class Vector { 
    private:
        T* elem; //elem points to an array of sz elements of type T
        int sz;
    public:
        Vector(int s);
        ~Vector() {delete[] elem; }

        T& operator[](int i) {return elem[i];}
        const T&operator[](int i) const;
        int size() const {return sz;}
};


template<typename T>
T* begin(Vector<T>& x) {
    return x.size() ? &x[0] : nullptr;
}
template<typename T>
T* end(Vector<T>& x) {
    return begin(x) + x.size();
}

template<typename Container, typename Value>
Value sum(Container& c, Value v){ 
    for (auto x : c) {
        v += x;
    }
    return v;
}

template<typename T>
Vector<T>::Vector(int s) { 
    if (s < 0) throw invalid_argument("Recieved Negative Value");
    elem = new T[s];
    sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const 
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

void write(const Vector<string>& vs) {
    for(int i = 0; i != vs.size(); ++i) { 
        cout << vs[i] << endl;
    }
}

void f2(Vector <string>& vs) {
    for (auto& s : vs)
        cout << s << endl;
}
int main() { 
    //Vector<char> vc(200); //Vector of 200 characters
    Vector<int> vs(17); //Vector of 17 Strings
    // vs[0] = '5';
    //Vector<list<int>> vli(45); //Vector of 45 lists of integers
    //f2(vs);
    double total = sum(vs, -2e+009);
    cout << total << endl;
}