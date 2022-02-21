//
//  3020_ firefly.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/21.
//

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N, H, h;
long long mite[5000001]; //석순
long long tite[5000001]; //종유석
long long sum[5000001];

int main(){
    cin >> N >> H;
    memset(mite, 0, sizeof(mite));
    memset(tite, 0, sizeof(tite));
    memset(sum, 0, sizeof(sum));
    
    for(int i = 1; i <= N; i++){
        cin >> h;
        if(i % 2 == 1){ // 석순
            mite[h]++; //h 높이인 개수
        }else{
            tite[h]++;
        }
    }
    
    for(int i = H - 2; i >= 1; i--){ // 누적합
        mite[i] += mite[i+1];
        tite[i] += tite[i+1];
    }
    
    for(int i = 1; i <= H; i++){
        sum[i] = mite[i] + tite[H + 1 - i]; // i 높이 석순 + H - i 높이 종유삭
    }
    
    sort(sum+1, sum+H+1); // 1 ~ H
    
    int cnt = 0;
    int target = sum[1];
    for(int i = 1; i <= H; i++){
        if(sum[i] == target){
            cnt++;
        }
    }

    
    cout << target << " " << cnt <<'\n';
    
    return 0;
}
