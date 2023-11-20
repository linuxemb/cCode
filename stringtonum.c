#include <stdio.h>

// turne string to digits atoi(char *p)


int atoi(char *p)
{ 
    int k,  num =0;  // k is digits, num is result 
    // not ending and *p is digits do convvert 
   while ( *p != '\0'  && ( *p >= '0')  && (*p <='9'))
   {
       k = *p -48; 
       num = 10 *num +k;
       p++;
     
   }
  return num;

}

int main ()
{
 char s[10];
 int num;
 printf("\n\n uboyt a digtial string") ;
 gets(s);

 num = atoi(s);
 printf("%d", num);
 return 0;
}




