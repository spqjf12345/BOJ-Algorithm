//
//  11497_log.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int diff[10000];

int find_min_height(vector<int> vv){
    
    int n = (int)vv.size(); //7
    int result[n];
    
    sort(vv.begin(), vv.end());
    
    //중심에 제일 큰값 넣기
    result[n/2] = vv.back(); // 5
    
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    
    for(int i = n - 2; i >= 0; i--){ // 남아 있는 vv 원소들에 대해
        if(index % 2 == 1){ // 접근 인덱스가 홀수이면
            index1++;
            result[(n/2) + index1] = vv.at(i);
        }else{
            index2++;
            result[(n/2) - index2] = vv.at(i);
        }
        index++;
    }
    
//    cout << "result : ";
//    for(int i = 0; i < n; i++){
//        cout<< result[i] << " ";
//    }
//    cout << endl;
    
    // 값의 차이가 최대인 것 찾기
    int maxDiff = 0;
    for(int i = 1; i < n; i++){
        if(maxDiff < abs(result[i] - result[i-1])){
            maxDiff = abs(result[i] - result[i-1]);
        }
    }
    
    return maxDiff;

}

int main(){
    vector<int> ans;
    int N, M;
    cin >> N;
    vector<int> v;
    for(int i =0; i < N; i++){
        cin >> M;
        v.clear();
        for(int j = 0; j < M; j++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        ans.push_back(find_min_height(v));
    }
    
    for(int i =0; i < (int)ans.size(); i++){
        cout << ans.at(i) << endl;
    }
    
    return 0;
}
