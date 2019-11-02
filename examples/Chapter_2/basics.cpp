#include <iostream>
using namespace std;

bool accept() {
    cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    cin >> answer; 
    switch(answer) { 
        case 'y':
            return true;    
        case 'n':
            return false;
        default:
            cout << "I'll take that for a no.\n";
            return false;
    }
}

void pointers() {
    double v[2];
    v[0] = 10;
    v[1] = 20;
    double* p = &v[1]; //The type of the pointer must be the same as the variable type it is point at 
    cout << "Array v " << v << "\n";
    cout << "Pointer P " << *p << "\n";
}

void simple_loop() { 
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto& x : v) //If we do not want to copy the values from v into x, but use x to reference an element use the following
    //& reference to. Similar to pointer, but you do not need the prefix * to access the value referred to by the reference 
        x *= 10; //A change in the reference will change the value it is referencing {0, 10, 20, ...}
        //cout << x; //This will throw an error because a reference cannot be made to refer to a different object after its initalization 
        //using (const auto& x: v) will not work because when casting as a const you are only able to read, not write, so forgo the const 
    for (auto x : v)  //for each x in v 
        cout << x << ' '; //Change observed
}        
int count_x(int *p, int x){
    //count the number of occurences of x in p[]
    //p is assumed to point to a zero-terminated array of char 
    if (p == nullptr) return 0;      
    int count = 0;
    for (; *p!=0; ++p) { // If you want to execute more than 1 execution you need to add curly brackets, without it wil only execute 1 statement  
    //If no Curly brackets then this will only execut the cout and not the if statement and it will return 0 
        cout << "Parsing through p " << *p << ' ' <<  x << "\n";
        if (*p == x) {
            cout << "These values are the same " << *p << " " << x << "\n"; 
            ++count; 
        }
    }
    return count;            
}   




int main(){
    int p[] = {1,1,2,2,3,3,0};
    int x = 2;
    int count = count_x(p, x);
    cout << "Answer is " << count;
}