#include "ECLongestPrefix.h"
#include <iostream>
#include "ECLongestPrefix.cpp"
using namespace std;

// perform test
static void Test()
{
  // Test case 1
  string arrStr1[3];
  arrStr1[0] = "flower";
  arrStr1[1] = "flow";
  arrStr1[2] = "flight";
  string res1 = ECLongestPrefix(3, arrStr1);
  cout << res1 << endl;;


  // Test case 2 
  string arrStr2[3];
  arrStr2[0] = "dog";
  arrStr2[1] = "racecar";
  arrStr2[2] = "car";
  string res2 = ECLongestPrefix(3, arrStr2);
  cout << res2 << endl;;
}


int main()
{
  Test();
  return 0;
}

