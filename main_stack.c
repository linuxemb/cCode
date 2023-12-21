#include "arraystack.h"
#include <iterator.h>
#include <stdlib.h>
#include  <stdio.h>
//https://github.com/tekinozbek/ods/blob/master/c/include/arraystack.h
// FILO

int main() {
arraystack_t s;
int i;
//  initialize the struct with the size of the elements you want to store
//  inside. this will allocate memory for the backing array. 
 arraystack_init(&s, sizeof(int));

for (i = 0; i < 10; i++)
        arraystack_push(&s, &i);

// using itertor 
iterator_t it;
/* make an iterator for stack[1,4] */
arraystack_iterator(&s, &it, 1 , 4);

while (it.next(&it))
    printf("%d\n", *(int*) it.elem(&it));
    /* iterators allocate memory for state, which must be released. */
it.dispose(&it);


printf("Revers\n");
arraystack_reverse(&s, 0,2);
int data;
arraystack_get(&s, 9, &data);
printf("get---%d \n", data) ;   
iterator_t it2;
/* make an iterator for stack[1,4] */
arraystack_iterator(&s, &it2, 0 , 9);

while (it2.next(&it2))
    printf("%d\n", *(int*) it2.elem(&it2));


while (s.length > 0) {

        arraystack_pop(&s, &i);
        printf("popped: %d\n", i);
    }
  arraystack_dispose(&s);
    return 0;
}


// 1
// 2
// 3
// 4
// Revers
// 1
// 0
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// popped: 9
// popped: 8
// popped: 7
// popped: 6
// popped: 5
// popped: 4
// popped: 3
// popped: 2
// popped: 0
// popped: 1