#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Modulo_print {
    ostream& os;
    int m;

    public:
        Modulo_print(ostream& s, int mm) :os(s), m(mm) {}
        void operator()(int x) const 
            { if (x % m == 0) os << x << "\n";}
};

void print_modulo(const vector<int>& v, ostream& os, int m) { 
    for_each(begin(v), end(v), Modulo_print{os, m});
}

int main() { 
    vector<int> x = {1,2,3};
    print_modulo(x, cout, 1);
}