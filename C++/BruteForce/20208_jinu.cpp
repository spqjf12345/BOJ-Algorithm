//
//  20208_jinu.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, M, H, ans;
int arr[101][101];
pair<int, int> house;

struct Mint {
    int x; int y; bool eat;
};
vector<Mint> mint;

void backTracking(int x, int y, int nowM, int cnt){
    if(cnt > ans) { // 집으로 돌아오는길
        if(abs(x - house.first) + abs(y - house.second) <= nowM) {
            ans = cnt;
        }
    }
    if(nowM <= 0) { return; }
    
    for(int i = 0; i< mint.size(); i++){
        int dist = abs(x - mint[i].x) + abs(y - mint[i].y);
        if(dist <= nowM && mint[i].eat == false){
            mint[i].eat = true;
            backTracking(mint[i].x, mint[i].y, nowM - dist + H, cnt + 1);
            mint[i].eat = false;
        }
    }
}

int main(){
    cin >> N >> M >> H;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                house.first = i; house.second = j;
            }else if(arr[i][j] == 2){
                mint.push_back({i, j, false});
            }
        }
    }
    
    backTracking(house.first, house.second, M,  0);
    cout << ans << '\n';
    
    return 0;
}


