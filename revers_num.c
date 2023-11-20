//How To Reverse Number In C?#include <stdio.h>
#include <stdio.h>
/* The Function we defined to reverse the given number*/
int ReverseTheNumber(int Number)
  {
   int rev = 0 ;
   while (Number  > 0)   // / 10 =
    {
     int dig = Number %10;   
     rev = rev *10 + dig;
     Number = Number /10;
    } 
    return rev;
  }




int main() {
    int Number, rem, sum=0;

    printf("Enter the number to be reversed: ");
    scanf("%d", &Number);
    getchar(); // flush input buffer
  //  int res=  ReverseTheNumber(Number);
    // printf("Reverse of no. is %d", ReverseTheNumber(Number)); /* Using the Function */
   // printf("%d\n", res);
    
    // Amstornstring 1*1*1+5*5*5+3*3*3=1+125+27=153

    int org = Number;
    while( org !=0) {
        rem = org % 10;
        sum = sum + rem * rem* rem;
        org = org /10;
    }
    if (sum == Number)
    printf("ARmstrong");    
    else 
    printf("Non Armstorn");
    return 0;

}