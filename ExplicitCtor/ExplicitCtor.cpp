// ExplicitCtor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

class Class1 {
  public:
    explicit Class1(int param=4) {std::cout<<param<<" ";}
};

int main()
{
  int ii=5;
  Class1 aa[2];
  Class1 bb[]={Class1(1),Class1(2),Class1(3)};
  Class1 cc[5]={Class1(1),Class1(2),Class1(3)};
  Class1 dd[5]={Class1(ii),aa[0],bb[0],cc[0],dd[0]};

  return 0;
}
