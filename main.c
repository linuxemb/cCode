#include "arrayqueue.h"
#include <stdlib.h>
#include  <stdio.h>

#define N 10
void printq(arrayqueue_t* q) 
{
    int i =0; 
    printf("print \t");
     while(i < q -> length) {
       printf("%d ",  *((int*) (q -> array) + i
       ));
       i++;
     }

     printf("\n");       
}

// void printq_peek(arrayqueue_t* q, int * elemp) 
// {     
//     //  int i =0;
//     //  size_t index = q->pos +1;

//     //  while(i < q -> length) {
//        arrayqueue_peek(q, elemp) ;
//        printf("%d ", * ((int*) elemp));
//     //    i++;
//       // q->array++;
//       //index = (index+1) % q->alloc_length;
//     //  elemp++;
//     //  }
//      printf("\n");       
// }
void printq_peek (arrayqueue_t* q, int * elemp)
{
    iterator_t it;
    size_t start = 0;

    size_t end = q->length - 1;
    // size_t start = q->pos;
    // size_t end = (q->pos + q->length - 1) % q->alloc_length;
    arrayqueue_iterator(q, &it, start, end);
    printf("Peek: ");
    while (it.next(&it)) {
        int* elem = (int*)it.elem(&it);
        printf("%d ", *elem);
    }
    printf("\n");
    it.dispose(&it);
}

int main() {

arrayqueue_t q;
size_t elem_size = sizeof(int);
size_t capacity = 10;
//arrayqueue_init(q , N);

arrayqueue_init(&q, elem_size, capacity);
for (int i =0; i < elem_size; i++) {
    printf("%p \t",(int *)(q.array)) ;
}

int dataarr[11] = {1,2,3,4,5,7,8,9,10,11};
int data1 = 43;
int data2 = 1;
int data3 = 4;
printf("=====elemen_size%d", elem_size);
printf("====capacity %d", capacity);
printf("Before arraydeque_add:\n");
printf("q->length: %d\n", q.length); //------------
printf("q->alloc_length: %d\n", q.alloc_length);

arrayqueue_enqueue (&q, &data1 );
arrayqueue_enqueue (&q, &data2 );
arrayqueue_enqueue (&q, &data3 );
//arrayqueue_add(q, 0, &data);
   

for (int i=0; i<11; i++)
{
    arrayqueue_enqueue(&q, &(dataarr[0]) + i);
}   
printf("===NEW ==elemen_size = %d", q.elem_size);
printf("q->alloc_length: %d\n", q.alloc_length);
printf("%d \n", *(int *)(q.array)) ;
 printq(&q);
// =================why not working only print 1st element spec 
 int *elemp = (int*)malloc(sizeof(int));

printq_peek(&q, elemp);
printf("====capacity %d", capacity);
 // dequeie

arrayqueue_dequeue (&q, elemp);
arrayqueue_dequeue (&q, elemp);
printf("========after dequeue 2 times \n") ;

 printq_peek(&q, elemp);

//============// Create an iterator to iterate through the queue
    iterator_t it;
    size_t start = 0;
printf("!!!!qlen==%d \n", q.length);
    size_t end = q.length - 1;  // Iterate over the entire queue
arrayqueue_iterator(&q, &it, start, end);

// // Use the iterator to print the elements
while (it.next(&it) )
    {
        int* elem = (int*)it.elem(&it);
        printf("%d -->", *elem);
    }
printf("\n");

free(elemp);
it.dispose(&it);

}

// test result
// jen@jen-virtual-machine:~/study/src$ ./main
// 0x55c39ac3a2a0  0x55c39ac3a2a0  0x55c39ac3a2a0  0x55c39ac3a2a0  =====elemen_size4====capacity 10Before arraydeque_add:
// q->length: 0
// q->alloc_length: 10
// ===NEW ==elemen_size = 4q->alloc_length: 20
// 43 
// print   43 1 4 1 2 3 4 5 7 8 9 10 11 0 
// ---qlen==14 
// ---end==13 
// Peek: 43 1 4 1 2 3 4 5 7 8 9 10 11 0 
// ====capacity 10========after dequeue 2 times 
// ---qlen==12 
// ---end==11 
// Peek: 4 1 2 3 4 5 7 8 9 10 11 0 
// !!!!qlen==12 
// ---qlen==12 
// ---end==11 
// 4 -->1 -->2 -->3 -->4 -->5 -->7 -->8 -->9 -->10 -->11 -->0 -->