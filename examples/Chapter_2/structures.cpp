#include <iostream>
using namespace std;
struct Vector {
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {} //Construct a vector everything after the : will populate the attributes of this class 
        double& operator[](int i) { return elem[i];} //Element access:subscripting operator[] overloads what [] does. it'll make it so that it will index into the elem and not vector itself
        //int i refers to the input, that being if v[i], then it will refer to that i for the func it will execute 
        int size() const {return sz;} //a "const" suffix means "can be applied to const objects"
    private:
        int sz; //number of elements
        double* elem;  //point to elements
};

// void vector_init(Vector& v, int s){ //Use & to pass the vector v by non-const reference, so that we can modify the vector passed in 
//     v.elem = new double[s]; //Allocate an array of s doubles. the new operator allocates memory from an area called the free store (Heap)
//     v.elem[5] = 10;
//     v.sz = s;
// }

// void f(Vector v, Vector& rv, Vector* pv){
//     cout << "Acessing through name " << v.sz << "\n";
//     cout << "Accessing through reference " << rv.sz << "\n";
//     rv.sz = 20;
//     cout << "Accessing through pointer " << pv->sz << "\n";
//     pv->sz = 30;
// }

double read_and_sum(int s) {
    Vector v(s);
    for (int i = 0; i != v.size(); ++i) {
        cin >> v[i];
    }
    double sum = 0;
    for (int i = 0; i != v.size(); ++i){
        sum += v[i];
    }
    return sum;
    
}

int main(){
    double sum = read_and_sum(10);
    cout << sum << "\n";
    // vector_init(v, 10);
    // cout << (&v)->elem[5] << "\n"; //when using -> the thing before the arrow must be a pointer demostrated by added the &.
    // f(v, v, &v);
    return 0;
}