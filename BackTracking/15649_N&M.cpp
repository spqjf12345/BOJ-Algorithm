//
//  15649_N&M.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;
int visit[9] = { false, };
vector<int>::iterator it;

void make_dfs(){
    if(v.size() == M){
        for(int i = 0; i < M; i++){
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }else {
        for(int j = 1; j <= N; j++){
            if(visit[j] == false){
                if(find(v.begin(), v.end(), j) != v.end()) { continue; }
                visit[j] = true;
                v.push_back(j);
                make_dfs();
                v.pop_back();
                visit[j] = false;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    make_dfs();
    return 0;
}
