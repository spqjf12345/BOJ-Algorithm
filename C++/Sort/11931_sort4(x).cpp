//
//  11931_sort4.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/10.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int N;
int arr[1000001];

void Swap(int arr[], int a, int b) // a,b 스왑 함수
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void quickSort(int arr[], int left, int right){
    int pivot, i, j;
    
    if(left < right){
        i = left + 1;
        j = right;
        pivot = left;

        while(i <= j){
            while(arr[i] >= arr[pivot] && i <= right){
                i++;
            }
            while(arr[j] <= arr[pivot]  && j > left){
                j--;
            }
            
            if(i >= j){
                break;
            }
            Swap(arr, i, j);
        }
        Swap(arr, pivot , j);
        
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}


int main(){
    cin >> N;
    for(int i =0; i < N; i++){
        cin >> arr[i];
    }
    
    quickSort(arr, 0, N-1);
    
    for(int i =0; i < N; i++){
        cout << arr[i] << '\n';
    }
    
    return 0;
}
