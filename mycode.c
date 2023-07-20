#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Holds user data
typedef struct TransactionType{     //when you use typedef, you wont need to include struc in the future when defining these again
    char transactionID[11];         //if you dont used typedef, u must include struc when defining new ones later
    char customerID[9];
    float amount;
} TransactionItem;

//Implements the linked list data structure (from Prof's code example)
typedef struct LinkedListNodeType{
    TransactionItem* transactionItem;
    struct LinkedListNodeType* next;
} ListNode;


ListNode* createNode(TransactionItem* item) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->transactionItem = item;
    newNode->next = NULL;
    return newNode;
}

void insertNode(ListNode** head, ListNode* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


int main() {
    char str[] = "|T000000001,C0000001,0000001.11|T000000002,C0000002,0000200.22|T000000003,C0000002,0003333.33";
    char *str_bk = strdup(str);

    const char s1[2] = "|";
    const char s2[2] = ",";

    char *token1;
    char *token2;
    
    // Create an array to store the transactions
    char *arr[3];
    char* arr2[15];

    int i = 0;

    // Get the first transaction
    token1 = strtok(str_bk, s1);

    while (token1 != NULL) {
        printf("======Field token1 : %s\n", token1);

        // Allocate memory for the current transaction and copy it
        arr[i] = (char *)malloc(strlen(token1) + 1); // +1 for the null terminator
        strcpy(arr[i], token1);

        i++; // Move to the next array element

        token1 = strtok(NULL, s1);
    }

    // Print the array elements (just for verification)
    for (int j = 0; j < i; j++) {
        printf("arr[%d]: %s\n", j, arr[j]);
    }

// arr[0]: T000000001,C0000001,0000010.99
// arr[1]: T000000002,C0000002,0000100.99
// arr[2]: T000000003,C0000002,0009999.99
 
// 创建链表头节点
ListNode* head = NULL;

 // move ot filed transxtion
  for  (int i = 0; i<3;i++)  {
     token2 = strtok(arr[i], s2);

    TransactionItem* item = (TransactionItem*)malloc(sizeof(TransactionItem));
 // 解析事务数据
    strcpy(item->transactionID, token2);
    token2 = strtok(NULL, s2);
    strcpy(item->customerID, token2);
    token2 = strtok(NULL, s2);
    item->amount = atof(token2);

// 创建新节点并插入链表
    ListNode* newNode = createNode(item);
    insertNode(&head, newNode);
  }   

// 遍历链表并打印事务数据
ListNode* current = head;
while (current != NULL) {
    TransactionItem* item = current->transactionItem;
    printf("Transaction ID: %s\n", item->transactionID);
    printf("Customer ID: %s\n", item->customerID);
    printf("Amount: %.2f\n", item->amount);
    printf("\n");
    current = current->next;
}


// 释放链表节点内存

current = head;
while (current != NULL) {
    ListNode* temp = current;
    current = current->next;
    free(temp->transactionItem);
    free(temp);

}
    // while (token2 != NULL) {
    // printf("======Field token2 : %s\n", token2);

    //   // Allocate memory for the current transaction and copy it
    //     arr2[i] = (char *)malloc(strlen(token2) + 1); // +1 for the null terminator
    //     strcpy(arr2[i], token2);
    //     token2 = strtok(NULL, s2);
       
    //    }       
    // }



    //   // Print the array elements (just for verification)
    // for (int j = 0; j < 9; j++) {
    //     printf("arr2[%d]: %s\n", j, arr2[j]);
    // }


    // // Free the dynamically allocated memory for each transaction
    // for (int j = 0; j < i; j++) {
    //     free(arr[j]);
    //     free(arr2[j]);
    // }

    // free(str_bk); // Free the strdup memory

  

  return 0;

}