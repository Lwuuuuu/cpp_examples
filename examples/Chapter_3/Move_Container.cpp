#include <iostream>
using namespace std;

struct Vector {
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {} //Construct a vector everything after the : will populate the attributes of this class 
        double& operator[](int i) {return elem[i];} //Element access:subscripting operator[] overloads what [] does. it'll make it so that it will index into the elem and not vector itself
        //int i refers to the input, that being if v[i], then it will refer to that i for the func it will execute 

        Vector(const Vector& a); //Copy Constructor
        Vector& operator=(const Vector& a); //Copy Assignment
        
        Vector(Vector && a); //Move constructor 
        Vector& operator=(Vector&& a); //Move assignment

        int size() const {return sz;} //a "const" suffix means "can be applied to const objects"
    private:
        int sz; //number of elements
        double* elem;  //point to elements
};

Vector::Vector(Vector&& a) //&& means rvalue. A move operation is applied whena n rvalue reference is used as an init or as the right-hand side of an assignment
    :elem{a.elem},
    sz{a.sz}
    {
        cout << "Found rvalues" << endl;
        a.elem =  nullptr;
        a.sz = 0;
    }



void read(Vector& v){
    cout <<"Read Function" << endl;
    for (int i = 0; i != v.size(); ++i){
        v[i] = 1;
    }
}

Vector operator+(Vector& a, Vector& b){
    //Bad copy, it makes an entirely new vector when the only thing we want is the addition of 2 vectors 
    // Vector res(a.size());
    Vector res(a.size());
    for (int i =0; i != a.size(); ++i)
        res[i] = a[i] + b[i];
    return res;
}

void f(Vector& x, Vector& y, Vector& z) { 
    Vector r = move(x + y);
    Vector p = move(r + z);
    for (int i =0; i != p.size(); ++i) {
        cout << p[i] << endl;
    }

}
 
int main() {
    Vector v1(3);
    read(v1);
    Vector v2(3);
    read(v2);
    Vector v3(3);
    read(v3);
    f(v1, v2, v3);
}