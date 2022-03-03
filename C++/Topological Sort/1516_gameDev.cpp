//
//  1516_gameDev.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/03.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<int> v[501];
int indegree[501];
int buildTime[501];
int sum[501];
queue<int> q;

int main(){
    
    for(int i = 1; i <= N; i++){
        indegree[i] = 0; // 초기화
        sum[i] = 0;
    }
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> buildTime[i];
        int b;
        while(1){
            cin >> b;
            if(b == -1) break;
            v[b].push_back(i);
            indegree[i]++; // 위상 증가
        }
        
    }
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
            sum[i] = buildTime[i];
        }
    }
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        //cout << "top " << top << "\n";
        for(int i = 0; i < v[top].size(); i++){
            int next = v[top][i];
            if(--indegree[next] == 0) { q.push(next); }
            sum[next] = max(sum[next], buildTime[next] + sum[top]);
            //cout << "top " << next << " value " << sum[next] <<'\n';
        }
        
    }
    
    for(int i = 1; i <= N; i++){
        cout << sum[i] << '\n';
    }
    
    
    
    
    return 0;
}
