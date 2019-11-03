#include <iostream>
#include <list> 
#include <initializer_list>
using namespace std;
//Whenever you have ::std likely means you have to include the library into the source file 
class Container {
    public: 
    //Pure interface to specific containers defined later 
    //Virtual means "may be redefined later" in a class derived from this one
    //A class derived from Container provides an implementation for the Container interface
    // The "=0" syntax says the function is pure virtual; that is, some class derived from Container must define the function 
    //Container can only be used as an interface if the operator and size functions are implemented 
    //Class with a pure virtual function is called an abstract class
        virtual double& operator[](int) = 0; //Pure Virtual Function
        virtual int size() const = 0; //Const member function 
        virtual ~Container() {} //Destructor, is virtual.  
};

//Container can be used like this:
//use uses the Container interface in complete ignorance of implementation details. Uses size() and [] without any idea of exactly which type provided their implementation 
//A class that provides the interface to a variety of other classes is often called a polymorphic type
//Flip side of this functionality is that objects must be manipulated through pointers or reference 
void use(Container& c){ //use has no idea if the argument passed in is a vector_container or list_container
    const int sz = c.size();
    for (int i =0; i != sz; ++i) {
        cout << c[i] << '\n';
    }
}

struct Vector {
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {} //Construct a vector everything after the : will populate the attributes of this class 
        double& operator[](int i) {return elem[i];} //Element access:subscripting operator[] overloads what [] does. it'll make it so that it will index into the elem and not vector itself
        //int i refers to the input, that being if v[i], then it will refer to that i for the func it will execute 
        int size() const {return sz;} //a "const" suffix means "can be applied to const objects"
        ~Vector() {delete[] elem;}

    private:
        int sz; //number of elements
        double* elem;  //point to elements
};

//A container that implements the functions required by the interface defined by the abstract class Container could use the concrete class Vector 
class Vector_container : public Container { //Vector_container implements Container. : public can be read "is dervied from" or "is a subtype of."
    Vector v;
    public:
        Vector_container(int s) : v(s) {}
        ~Vector_container() {}
        double& operator[](int i){return v[i];} //Overides the corresponding members in the base class 
        int size() const {return v.size();}
};

class List_container : public Container {
    list<double> ld;
    public:
        List_container() {}
        List_container(initializer_list<double> il) : ld{il} {}
        ~List_container() {}
        double& operator[](int i);
        int size() const {return ld.size(); }
};

double& List_container::operator[](int i) { 
    for (auto&x : ld) {
        if (i == 0) return x;
        --i; //Gets the i'th element of the list 
    }
    throw out_of_range("List Container");
}

void read(Container& c) {
    cout << "In read func" << endl;
    for (int i = 0; i != c.size(); ++i) {
        cin >> c[i];
    }
}

void h() { 
    List_container lc = {1,2,3,4,5};
    read(lc);
    use(lc);

}

int main() {
    Vector_container v(3);
    read(v);
    use(v);
    //h();
    return 0;
}