#include <iostream>
using namespace std;

int recursive(int n, int sum){
    if (n == 0) {
        return sum;
    }        
    else {
        return recursive(n - 1, sum+n);        
    }       
}


int main()
{
    int n, sum = 0;
    n = 20;
    sum = recursive(n, sum);
    cout << "Sum = " << sum;
    return 0;
}