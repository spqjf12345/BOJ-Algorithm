//
//  2003_sum2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M, N;
int cnt = 0;
vector<int> v;

void pointer(){
    int start = 0, end = 0;
    int sum = 0;
    
    while(true){
        if(sum >= N) {
            sum = sum - v[start++];
        }else if(end >= M) {
            break;
        }else {
            sum = sum + v[end++];
        }
        
        if(sum == N){
            cnt++;
        }
    }
}

int main(){
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    pointer();
    cout << cnt << '\n';
    return 0;
}
