#include <stdio.h>
// Binary search "----O(log(n))"

// Iterneative way  --1
 int a[8] = {1,2,4,6,78,9,5,34};
int binSearch(int arr[], int l, int  h, int target) 
{
    while (l <= h)
    {   
       int  mid = (l+h)/2;
        if (arr[mid] == target)
        {
            printf("found---%d at array[ %d]=\n", target, mid );
        return mid;  // found pos of target
        }
        if (target < arr[mid] )
        { 
            h = mid -1;
        }
        else {
            l = mid + 1;
        }

    }
printf("not found %d", target);
return -1;}
//============= REcursive approach --2
int binSearchR(int arr[], int l, int  h, int target) {
    int mid =0;
    if ( l  <= h) {
         mid = (l+h)/2;
        if (mid >=0 && mid <= 8) {
                    if (arr[mid] == target) return arr[mid];
                  else   if (arr[mid] < target)
                            return      binSearchR(arr, mid+1, h, target );
   
                          else 
                          return   binSearchR(arr, l, mid-1, target);
                         }
         else 
        return -1;
       return -1;

    }                 
}


// delet elemnet form array
void fun()
{
    static int x;
    printf("%d", x);
    x = x+1;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b =tmp;

}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j=0; j<n-1-i ; j++) {
            if (arr[j]  > arr[j+1]) {
                swap( &arr[j], &arr[j+1]) ;
            }
        }
    } 
}
void print(int arr[], int size) {
    for (int i=0;i<size; i++){
        printf("\t %d ", arr[i]);
    }
    printf("/n");
}

int insertElement(int arr[], int elem, int key, int size);
void deleteElement (int arr[], int target);
int main()
{
   
   int loc =0;
    int a[8] = {1,2,4,6,78,9,5,34};
    printf("size = %d\n", sizeof(a)/sizeof(a[0]));
    
    bubbleSort(a, 8);
    print(a, 8);
    
    int target = 78;

    // printf("===bin search %d in array", target);

    // loc= binSearch(a, 0, 8, target);
    // if (loc >= 0)
    // printf("loc= %d \t, for targetf %d\n", loc, target);
    // else
    // printf("loc= %d \t,  Not found for targetf %d\n", loc, target);
 
 // -----------------test recursive     binSearchR 
   // int target = 5;
    printf("===bin search %d in array", target);
    loc= binSearch(a, 0, 8, target);
  //  loc= binSearchR(a, 0, 8, target); // ha sissue with last elemt loc = 78 buggey 
    if (loc >= 0)
    printf("loc= %d \t, for targetf %d\n", loc, target);
   else
    printf("loc= %d \t,  Not found for targetf %d\n", loc, target);
    
    
    // delete element
    deletElement(a, 8, target);
    // int len = sizeof(a) /sizeof(a[0]) - 1;
    // int arr_new [len];

    //  for (int i=0; i<= len ;i++)  
    //    {
    //        if (i != loc)
    //         arr_new[i]  = a[i];
    //    }    
        printf("after del target ====\n");
        print(a,  7);
   
   int e =  insertElement(a, 7, target, 8);
    printf("n After Insertion: "); 
    for ( int i = 0; i < e; i++) 
        printf("%d  ",a[i]); 
        return 0; 
   // if(printf("jjj%%90")){} // print without  ;

}
// insert to an unsorted arr , just add at last element
int insertElement(int arr[], int elem, int key, int size) {
   // find the location of elemnet to insert
   
   // Check if the capacity of the array is already full 
   if (elem >= size) 
    return elem;  // last elem pos toinset
 // if not ele is insertee at last index and the new arrar size returned 
    arr[elem] = key;
    return (elem +1);

}

int deletElement(int arr[], int size, int target ) {
    int len = sizeof(arr) /sizeof(arr[0]) - 1;
  //  int arr_new [len];  // no need 
    int loc = binSearch(arr, 0, len, target) ;
    //  for (int i=0; i<= len ;i++)  
    //    {
    //        if (i != loc)
    //         arr_new[i]  = a[i];
    //    }    
     // === move the rest of elem by one pos
     for (int i= loc; i<= len  ;i++)  
       {
           if (i != loc)
            arr [i]  = a[i + 1];
       }    
       return size-1;

}   