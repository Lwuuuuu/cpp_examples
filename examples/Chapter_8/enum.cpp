#include <iostream>
using namespace std;

enum class Printer_flag {
    none = 0,
    acknowledge = 1,
    paper_empty = 2,
    busy = 4,
    out_of_black = 8,
    out_of_color = 16
};

enum class Flag : char { x = 1, y = 2, z = 4, e = 8};


int main() {
    //cout << static_cast<int>(Printer_flag::out_of_black);
    int i = static_cast<int>(Flag::y);
    int c = static_cast<char>(Flag::e);
    char d = static_cast<int>('8');
    cout << "i " << i << " " << "c " << c << endl;
    cout << d << endl;
}