#include <iostream>
using namespace std;
struct Vector {
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {} //Construct a vector everything after the : will populate the attributes of this class 
        double& operator[](int i) {
            if (i < 0 || size() <= i) throw out_of_range{"Vector::operator[]"}; //Throw transfers control to a handler for exceptions of type out_of_range
            return elem[i];
        } //Element access:subscripting operator[] overloads what [] does. it'll make it so that it will index into the elem and not vector itself
        //int i refers to the input, that being if v[i], then it will refer to that i for the func it will execute 
        int size() const {return sz;} //a "const" suffix means "can be applied to const objects"
    private:
        int sz; //number of elements
        double* elem;  //point to elements
};

void f(Vector& v) { 
    try {
        v[v.size()] = 7;
    }
    catch (out_of_range){
        cout << "Out of Range Error";
    }
}

int main() {
    Vector v(3);
    f(v);
}