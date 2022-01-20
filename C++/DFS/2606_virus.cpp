//
//  2606_virus.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/07/16.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n; // computer n
int connectN; // connected computer n
vector<int> computer[101];
stack<int> s;
bool visit[101];
int cnt = 0; // default for computer 1

int finc_infection_computer_dfs(){
    
    while(!s.empty()){
        int next = s.top();
        s.pop();
        for(int i = 0; i < computer[next].size(); i++){
            if(visit[computer[next][i]] == false){
                visit[computer[next][i]] = true;
                 cnt++;
                s.push(computer[next][i]);
            }
        }
    }
    
    return cnt;
    }


int main(){
    cin >> n;
    cin >> connectN;
    visit[1] = true;
    for(int i = 0; i < connectN; i++){
        int j, k;
        cin >> j >> k;
        if(j == 1){
            s.push(k);
            visit[k] = true;
            cnt++;
        }
        else if(k == 1){
            s.push(j);
            visit[j] = true;
            cnt++;
        }
        computer[j].push_back(k);
        computer[k].push_back(j);
    }
    
    cout << finc_infection_computer_dfs() << '\n';
    return 0;
}
