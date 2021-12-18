//
//  1005_acmCraft.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/18.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int Tcase;
int value, node;
int v[1001];
vector<int> n[100001];
int lastNode;
int indegree[100001];
int result[100001];

queue<int> q;
int checkValue(){
    
    for(int i = 1; i <= value; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0; i < (int)n[temp].size(); i++){
            int idx = n[temp][i];
            result[idx] = max(result[idx], result[temp] + v[idx]);
            //cout << "idx " << result[idx] << '\n';
            indegree[idx]--;
            if(indegree[idx] == 0) {
                q.push(idx);
            }
        }

    }
    
    return result[lastNode];
}

void initial(){
    for(int i = 1; i <= value; i++){
        v[i] = 0;
    }
    
    for(int i = 1; i <= node; i++){
        indegree[i] = 0;
        n[i].clear();
    }
}

int main(){
    cin >> Tcase;
    while(Tcase--){
        cin >> value >> node;
        for(int i =1; i <= value; i++){
            cin >> v[i];
            result[i] = v[i];
        }
        for(int i = 1; i <= node; i++){
            int start, end;
            cin >> start >> end;
            indegree[end]++;
            n[start].push_back(end);
        }
        cin >> lastNode;
        cout << checkValue() << '\n';
        
        initial();
    }
    return 0;
    
}
