#include <stdio.h>
#include "IntInf.h"

using namespace ece309;

int main(void){
  IntInf a(5);//num
  printf("creating object a: ");
  a.print();
  IntInf b(0,true);//posInf
  printf("creating object b: ");
  b.print();
  IntInf c(0,false,true);//negInf
  printf("creating object c: ");
  c.print();
  IntInf d(6);
  printf("creating object d: ");
  d.print();
  IntInf e(0,false,false);
  printf("creating object e: ");
  e.print();
  IntInf test;
  printf("a + b = ");
  (a+b).print();
  printf("c + b = ");
  (c+b).print();
  printf("a - b = ");
  (a-b).print();
  printf("a + d = ");
  (a+d).print();
  printf("d - a = ");
  (d-a).print();
  printf("c - b = ");
  (c-b).print();
  printf("a / b = ");
  (a/b).print();
  printf("b / c = ");
  (b/c).print();
  printf("a * b = ");
  (a*b).print();
  printf("a * c = ");
  (a*c).print();
  printf("a * d = ");
  (a*d).print();
  printf("a * e = ");
  (a*e).print();
  printf("d / a = ");
  (d/a).print();
  printf("a > b = %d\n",(a>b));
  printf("a > c = %d\n",(a>c));
  printf("a > d = %d\n",(a>d));
  printf("d > a = %d\n",(d>a));
  printf("a < b = %d\n",(a<b));
  printf("a < c = %d\n",(a<c));
  printf("a < d = %d\n",(a<d));
  printf("d < a = %d\n",(d<a));
  return 0;
}
