#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// int splitpos(int *arr, int low, int high) {
//     int pivotpos = low;
//     int pivotele = arr[low];

//     int i = low;
//     int j = high + 1;

//     do {
//         do {
//             i++;
//         } while (arr[i] <= pivotele && i <= high - 1);

//         do {
//             j--;
//         } while (arr[j] >= pivotele && j >= low);

//         if (i < j) {
//             swap(&arr[i], &arr[j]);
//         }
//     } while (i < j);
//     int temp2=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp2;
//     swap(&arr[low], &arr[j]);
//     return j;
// }

// void returnquicksort(int *arr, int low, int high) {
//     if (low < high) {
//         int pivotIndex = splitpos(arr, low, high);

//         returnquicksort(arr, low, pivotIndex - 1);
//         returnquicksort(arr, pivotIndex + 1, high);
//     }
//     else if(low+1 == high){
//         if(arr[low]>arr[high]){
//             swap(&arr[low],&arr[high]);
//         }
//     }
//     else return;
// }
int splitpos(int *arr, int low, int high)
{
    int pivotpos = low;
    int pivotele = arr[low];
    int i = low + 1;
    int j = high;

    // while (i <= j && i <= high && j >= low)
    do{
        // while (arr[i] < pivotele)
        //     i++;
        do
        {
            /* code */
            i++;
        } while (arr[i]<pivotele);
        
        while (arr[j] > pivotele)
            j--;
        // do
        // {
        //     /* code */
        //     j--;
        // } while (arr[j]>pivotele);
        
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }while(i<=j);
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;

    temp = arr[j];
    arr[j] = arr[pivotpos];
    arr[pivotpos] = temp;

    return j;
}

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int s = splitpos(arr, low, high);
        // printf("%d\n", s);
        QuickSort(arr, low, s - 1);
        QuickSort(arr, s + 1, high);
    }
    else
        return;
}

int main() {
    int a[8] = {11, 2, 3, 14, 5, 10, 9, 15};
    // splitpos(a,0,7);
    // returnquicksort(a, 0, 7);

    QuickSort(a,0,7);
    printf("Sorted array: \n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
