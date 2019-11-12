#include <stdio.h>
#define MAX_SIZE 10000

void Quicksort(int array[], int left, int right);
int Partition(int array[], int left, int right);
void Swap(int array[], int value_1, int value_2);
void PrintArray(int array[], int size);

int size;

int main(void) {
    int arr[MAX_SIZE];
    //printf("input element size:\n");
    scanf("%d",&size);
    //printf("input elements:\n");
    int i=0;
    while(i<size){
        scanf("%d",&arr[i]);
        i++;
    }
    
    Quicksort(arr, 0, size-1);
    PrintArray(arr,size);
}
void Quicksort(int array[], int left, int right){
    if(left <= right){
        int pivot=Partition(array, left, right);
        Quicksort(array, left, pivot-1);
        Quicksort(array, pivot+1, right);
        
    }
    
}

int Partition(int array[], int left, int right){
    int pivot=array[right];
    int the_point= left;
    int just_point=left;
    
    while(just_point<right){
        if(array[just_point]<pivot){
            Swap(array,just_point,the_point);
            the_point++;
        }
        just_point++;
    }
    
    Swap(array,the_point, right);
    return the_point;
}

void Swap(int a[], int v1, int v2){
    int temp= a[v1];
    a[v1]=a[v2];
    a[v2]=temp;
}

void PrintArray(int array[], int size){
    for(int i=0; i<size; i++)
        printf("%d\n",array[i]);
}
