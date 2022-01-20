//
//  numberGame.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1001][1001];
int N;
vector<int> idx;
bool visit[5] = { false, };
int result[1001] = { 0, };
int cnt = 1;
void combi(){
    
    if(idx.size() == 3){
        int maxCheck[1001] = { 0, };
        for(int i = 1; i <= N; i++){ // person
            for(int j = 0; j < 3; j++){ // card
                int n = idx.at(j);
                maxCheck[i] += arr[i][n];
            }
            
            result[i] = max(maxCheck[i] % 10, result[i]);

        }
    }else {
        for(int i = 1; i <= 5; i++){
            if(visit[i] == false){
                if(find(idx.begin(), idx.end(), i) != idx.end()) { continue; }
                idx.push_back(i);
                //visit[i] = true;
                combi();
                idx.pop_back();
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 5; j++){
            cin >> arr[i][j];
        }
    }
    
    combi();
    
    int winnerIndex = 0;
    int winnerMax = 0;
    
    for(int i = 1; i <= N; i++){
        if(winnerMax <= result[i]){
            winnerMax = result[i];
            winnerIndex = i;
        }
    }
    
    cout << winnerIndex << '\n';
    
    return 0;
}
