#include <iostream>
int x=10;

namespace
{
  int x=20;
}

int main(int x, char* y[])
{
  {
    int x=30;
    std::cout<<::x<<std::endl;
  }
  return 0;
}