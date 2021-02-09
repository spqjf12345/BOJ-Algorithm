//
//  2110_router.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/09.


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int find_min_distance(int home, int router, int *arr){
    int max_distance = 0;
    int start = 1; int end = arr[home - 1] - arr[0]; // 간격 최소, 최대 거리
    
    while(start <= end){
        int mid = (start + end) / 2;
        int set_router = arr[0]; //처음 세운 라우터
        int count = 1; // 처음 집 count
        
        for(int i = 1; i < home; i++){//첫집을 제외한 집을 돌면서 i 로 공유기 세움
            int compare = arr[i] - set_router;
            //가장 가까운 집 간격이 최소한 mid가 되도록 설정하기 위해서
            if(compare >= mid){ // 간격이 mid 보다 크다면 초기엔 end 쪽에 가까운 값으로 셋팅
                set_router = arr[i]; //초기 8로 셋팅
                count++;
//                cout << "set_router " << i << " " << set_router << endl;
//                cout << "count " << count << endl;
            }
        }
        
        if(count >= router) {
            max_distance = mid;
            start = mid + 1;
        }else{
            //설치할게 남았으므로 설치 수 증가
            end = mid - 1; // 간격을 하나 감소 == 설치 수 증가
        }
    }
    return max_distance;
    
            //int value_min = min(arr[i] - arr[start], arr[end] - arr[i]);
//            if(value_min > max_distance){
//                max_distance = value_min; //3
//                index = i; //2
//            }
        
        
//        if(max_distance < mid){
//            start = index + 1;
//        }else if( max_distance >= mid){
//            end = index - 1;
//        }

}


int main(){
    int home, router, distance;
    cin >> home >> router;
    int *arr = new int[home];
    for(int i = 0; i < home; i++){
        cin >> arr[i];
    }
    sort(arr, arr + home);
    distance = find_min_distance(home, router, arr);
    cout << distance << endl;
    return 0;
}
