//C++ suports a simple form of user-defiend type for which we can enumerate the values
#include <iostream>
using namespace std;
enum class Color {red, blue, green};
enum Traffic_light {green, yellow, red};
Traffic_light& operator++(Traffic_light &t) {
    switch(t){
        case Traffic_light::green: 
            return t=Traffic_light::yellow;
        case Traffic_light::yellow: 
            return t=Traffic_light::red;
        case Traffic_light::red: 
            cout << "Light will turn green.";
            return t=Traffic_light::green;
        default: 
            cout << "Somethig went wrong";
            return t;
    }
}
// Enumerators are in the scope of their own class so the red in Color is different from the red in traffic light 
// Class after the enum specifies that an enumeration is strongly typed and that its enumerators are scoped.
// If you do not want to explicitly qualify enumerator names and want enumator values to be ints, can remove the class from enum class 
int main() {

    Traffic_light light = Traffic_light::red;
    Traffic_light next = ++light;
}
