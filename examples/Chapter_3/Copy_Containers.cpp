#include <iostream> 
using namespace std;

class Vector {
    private:
        double* elem;
        int sz;
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {};
        ~Vector() {delete[] elem;}

        Vector(const Vector& a);
        Vector& operator=(const Vector& a);

        double& operator[](int i) {return elem[i];}
        const double& operator[](int i) const;

        int size() const {return sz;}
};

void read(Vector& v){
    cout <<"Read Function" << endl;
    for (int i = 0; i != v.size(); ++i){
        cin >> v[i];
    }
}

Vector::Vector(const Vector& a) 
    :elem{new double[a.sz]},
    sz{a.sz}
{
    for (int i = 0; i != sz; ++i) { 
        elem[i] = a.elem[i];
    }
}    

Vector& Vector::operator=(const Vector& a) { 
    double* p = new double[a.sz];
    for (int i = 0; i != a.sz; ++i) {
        p[i] = a.elem[i];
    }
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;        
    
}



int main() {
    Vector v(3);
    read(v);
    Vector v2(3);
    v2 = v;
    // Vector v2(v); //Same as doing Vector v2 = v;
    v2[1] = 100;
    cout << "v1 values " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << "v2 values " << v2[0] << " " << v2[1] << " " << v2[2] << endl;

}