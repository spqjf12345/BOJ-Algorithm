//
//  11582_chicken_merge.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/10.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int arr[1548577];
int re_arr[1548577];
int N = 0;
int cnt_n = 0;

void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    
    if(end - start > N / cnt_n) {
        return;
    }
    
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            re_arr[k++] = arr[i++];
        }else {
            re_arr[k++] = arr[j++];
        }
    }
    
    while (i <= mid){
        re_arr[k++] = arr[i++];
    }
          
    while (j <= end){
        re_arr[k++] = arr[j++];
    }
           
    for (int i = start; i <= end; i++) {
       arr[i] = re_arr[i-start];
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, end);
    }
}


int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cin >> cnt_n;
    merge_sort(0, N-1);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}
