//
//  3048_ant.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int A, B;
int t;

void after_t_time(char arr[]){
    //무작정 swap 할 것이 아니라 방향 구분이 필요
//    int left = A - 1;
//    int right = A;
    while(t--){
        for(int i = 1; i < A + B; i++){
            if(arr[i-1] >= 'a' && arr[i-1] <= 'z' && arr[i] >= 'A' && arr[i] <= 'Z'){
                swap(arr[i], arr[i-1]);
                i++;
            }
        }
//        if(left < 0 || right > A+B){
//            break;
//        }
//
//        for(int i = left; i < right; i = i + 2){
//            swap(arr[i], arr[i+1]);
//        }
//
//        left--;
//        right++;
    }
}

int main(){
    cin >> A >> B;
    char arr[A+B+1];
    
    for(int i = A-1; i >= 0; i--){
        cin >> arr[i];
        arr[i] = arr[i] - 'A' + 'a'; // 소문자로 받기
    }
    
    for(int j = A; j < A+B; j++){
        cin >> arr[j];
    }
    
    
    cin >> t;
    
    after_t_time(arr);
    
    for(int i =0; i < A+B; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            cout << char(arr[i] + 'A' - 'a');
        }else {
            cout << arr[i];
        }
    }
    return 0;
}
