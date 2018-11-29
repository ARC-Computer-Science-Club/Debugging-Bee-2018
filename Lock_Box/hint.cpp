#include <iostream>

using namespace std;

void count(unsigned i)
{

  // basecase
  if (i != 0)
    {
      count(i - 1);
    }

  cout << i << endl;
}


int main()
{
  count(3);
  /* prints:
     0
     1
     2
     3
  */
}
