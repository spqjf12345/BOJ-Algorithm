//
//  2003_sum2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/26.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

int two_pointer(int N, int arr[], int M){
    int cnt = 0;
    int start = 0, end = 0;
    int sum = 0;
    
    while(true){
        
        if(sum >= M){
            sum = sum - arr[start++]; // 값을 빼주고 start 인덱스 뒤로 감
        }else if(end == N){ // end 가 인덱스 범위 벗어났을 경우
            break;
        }else{ // end 현재 위치값 저장 후 end 뒤로 이동
            sum = sum + arr[end++];
        }
        
        if(sum == M){
            cnt++;
        }
    }
    
    return cnt;
}
int main(){
    int N, M;
    cin >> N >> M;
    int arr[N];
    for(int i =0; i < N; i++){
        cin >> arr[i];
    }
  
    int cnt = two_pointer(N, arr, M);
    cout << cnt << endl;
    return 0;
}
