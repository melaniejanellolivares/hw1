#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("foo");
  dat.push_back("bar");
  dat.push_back("baz");
  dat.pop_front();
  
  
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

  cout << dat.get(0) << dat.get(1)<< endl;
  return 0;
}
