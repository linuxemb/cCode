#include <stdio.h>

// find all students 's grad which fails

#define N 3  // course
#define M 2  // peopel
#define ROWS 3
#define COLS 4

#define N 3
#define LEN 10


// sort stings 

void sort( char ** p) {
     int i, j;
     char *ptr;  // string
     for (i =0; i<N-1; i++)
     {
        for (j=1; j<N; j++)  {
             if(strcmp(*(p +i), *(p +j))  > 0) {
            // swap
              ptr = *(p +i);
            *(p+i) = *(p+j);
             *(p+j) = ptr;
             }
        }

    }
}


int main ()

{ // input strings
int i;
char * pstr[N], s[N][LEN];  // pstr is array of start address of eachstring 


for (i = 0; i < N;i++) {
    pstr[i] = s[i];  // pass ith strings start address to pointer array  // mem allocat static
    printf("input string%d num of strng \n", N) ;
    {
        gets(pstr[i]);
    }
}
    sort (pstr);
   printf ("the sorted strings are ") ;

   for (i=0; i< N ; i++) {
       puts(pstr[i]);
   }

     return 0;
}






