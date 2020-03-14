#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0;i<N;i++){
        printf("%d ", arr[i]);
    }
} 

int main(){
    int arr[] = {99,88,12,11,11,11,10,18,-45,-45,-5};
    bubble_sort(arr,11);
    return 0;
}