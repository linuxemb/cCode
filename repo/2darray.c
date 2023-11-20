#include <stdio.h>

// find all students 's grad which fails

#define N 3  // course
#define M 2  // peopel
#define ROWS 3
#define COLS 4

//void search ( int rows, int cols, int p [rows][cols])  // ver1
void search ( int rows, int cols, int (*p) [cols])   // ver 2
{
    int flag=0; int i, j;
    for (i =0; i < M; i++) {

        for (j= 0 ; j< N; j ++) 
        {
            if (p[i][j] <60)
            {
                flag = 1;
            }
            if (flag ==1) {
                // printf("flunked scroes are num %d", i+1 );
                for (j=0; j<N; j++)
                   printf("%d /t ",  p[i][j]);
                flag =0;
                // printf(("%5.1d", * ( *(p+i) + j)));
            }
        }

    }



}
int main ()

{
    int score[M] [N] = { {59, 66, 77},
                          {88, 88, 99}};        
    //   int matrix[ROWS][COLS] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

//  char score[M][N];
//   // get all grades for all students
//  int p, class =0;
//  for (int i =0; i< M; i++) {
//      printf("\n\n uInput the courses and for this person ith %d", i) ;
//     for (int j =0; j < N; j++) {
//         scanf("%d", &score[i][j]);
//     }



  
//print all grades for all stu

//  for (int i =0; i< M; i++) {
//       for (int j =0; j < N; j++) {
//        printf("%d", score[i][j]);
//     }

//  }
    search( M, N,score);

//   for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//           //  printf("%d\t", matrix[i][j]);
//           //  printf("%d\t", *(*(matrix +i)+j));   // way 2
//             printf("%d\t", *(matrix[i] +j));    // way 3 

//         }
//         printf("\n");
//     }
 return 0;
}




