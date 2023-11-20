#include <stdio.h>

// find all prime
#define M 200   // find all prime in range of 200
#define N (M+1)/2  // num of odd 100

int main() {
   
// step 1 diven by 2 ok, remove all even nums

int i, j, a[N];
 a[0] = 2; // find evne num loc and set to 0
for (i=0;  i<N; i++)
    a[i] = 2* i+1;

// step 2 loop var and self inccreas and remove fois
for ( i=1; i<N-1;i++) {
   if (a[i]!=0)
    {
        for (j = i+1; j<N; j++) {
            if (a [j] % a[i] ==0)
            a[j] =0;
        }

    }
}
printf("the prime number are [2-%d]:\n" ,M);

for (i=0; i<N; i++)
{
    if (a[i] !=0)
    {
        printf("%5d", a[i]);
            if((++j) %10 ==0)
        printf("\n");

    }
   
}
return 0;
}




// $ ./a.out 
// the prime number are [2-200]:
//     1    3    5    7   11   13   17   19   23   29
//    31   37   41   43   47   53   59   61   67   71
//    73   79   83   89   97  101  103  107  109  113
//   127  131  137  139  149  151  157  163  167  173
//   179  181  191  193  197 

