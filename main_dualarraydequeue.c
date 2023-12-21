#include  <stdio.h>
#include "dualarraydeque.h"


int main() {
    int balance_call_count = 0;
    dualarraydeque_t d;
    size_t elem_size = sizeof(int);

    // Initialize the dualarraydeque
    dualarraydeque_init(&d, elem_size);

    // Add elements to the front and back
    int data1 = 1, data2 = 2, data3 = 3;

    int data4 = 0, data5=8;
    dualarraydeque_add_front(&d, &data1);
    dualarraydeque_add_back(&d, &data2);
    dualarraydeque_add_back(&d, &data3);
    dualarraydeque_add_back(&d, &data4);
    dualarraydeque_add_back(&d, &data5);

    // Print the deque
    for (size_t i = 0; i < d.length; i++) {
        int value;
        dualarraydeque_get(&d, i, &value);
        printf("%d ", value);
    }
    printf("\n");

    // Remove elements from the front and back
    int removed_front, removed_back;
    dualarraydeque_remove_front(&d, &removed_front);
    dualarraydeque_remove_back(&d, &removed_back);

    // Print the deque after removal
    for (size_t i = 0; i < d.length; i++) {
        int value;
        dualarraydeque_get(&d, i, &value);
        printf("%d ", value);
    }
    printf("\n");

    printf("balance called %d\n", balance_call_count);

    // Dispose of the dualarraydeque
    dualarraydeque_dispose(&d);

    return 0;
}
