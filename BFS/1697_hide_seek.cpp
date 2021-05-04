//
//  1697_hide_seek.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/21.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>


using namespace std;
#define MAX 100000
int visit[MAX + 1];
int n, k;
int moving[3] = { - 1, 1, 2}; //walk, jump

void hide_and_seek_bfs(int num){
    queue<int> q;
    q.push(num);
    visit[num] = 0;
    
    if(num == k){
        cout << 0 << '\n';
    }
    
    while(!q.empty()){
        int temp = q.front();
        int next;
        q.pop();
        
        for(int i = 0; i < 3; i++){
            if(i == 2) next = moving[i] * temp;
            else next = moving[i] + temp;
            
            //예외 처리
            if(next < 0 || next > 100000) continue;
            if(visit[next] != -1) continue;
            
            q.push(next);
            visit[next] = visit[temp] + 1;
            
            if(next == k){
                cout << visit[next] << '\n';
                break;
            }
            
            
        }
    }
}



int main(){
    memset(visit, -1, sizeof(visit));
    cin >> n >> k;
    hide_and_seek_bfs(n);
    return 0;
}
