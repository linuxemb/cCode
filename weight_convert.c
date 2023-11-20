#include <stdio.h>

// from xa convert from a nar y to bniary 
int main() {
    int Number, wei,      rem, sum=0;

   
   
   int a; // num to conver
  int b;     // jinzhi
  int  k=1;   // weight
 int xa =0;  // orignal data
 int xb =0;    //convert data
 int x1= 0 ;
 int x2=0;
  printf("Enter the number--xa and wight a->b : ");
    scanf("%d %d %d", &xa, &a, &b);
    printf(" a = %d", a);
    printf("b= %d \n", b);
    // getchar(); // flush in
    x1 =xa;
     printf("x1= %d \n", x1);
//convert to 10 nary
 while(  x1 !=0) {

      x2+= (x1 %10 ) *k;
      x1 /=10;
      k *=a;  // orignal nary

 }
k=1;
x1=x2;
 printf(" 10nary %d x2=",x2);
// convert to bnary
while(  x1 !=0) {

      xb+= (x1 % b ) *k;
      x1 /=b;
      k *=10;  // orignal nary

 }

 printf("b nary %d x2=",xb);

return 0;
}
// rj$ ./a.out 
// Enter the number--xa and wight a->b : 7513 8 6
//  a = 8b= 6 
// x1= 7513 
//  10nary 3915 x2=b nary 30043 x2=lisa@DESKTOP-TO76GEI:/mnt/c/prj$ 