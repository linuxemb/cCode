#include <stdio.h>
// f1=1,
//f2=1;
// f3=f1+f2;
// f4=f3+f2;

// max gcd

int gcd (int, int);


int main()
{
  int x;
  int a=1;
  int b=1;
  // pirnt fab 
  for(int x = 0; x<=20; x++)
   {
    printf("%16ld %16ld", a, b);
   // printf("x=%d ", x);
    if (x %2) printf ("\n");
     a = b+a;
     b= a+b;
   }


   // find GCD of 9 and 3;
   int mygcd = gcd (26,100);
  printf ("gcd %d \n", mygcd ) ;
}


  int gcd (int a, int b) {
   int t, c ;
   if(a<b) 
   {
    t =a;
    a=b;
    b=t;  // swap
   }
   c = a % b; 
   while (c!=0) 
   {
     a = b;
     b = c;
     c = a % b;

   }
    return b;
}
 


