//
//  2252_line.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define INTMAX 32001

using namespace std;

void line(){
    int N, n;
    //input
    cin >> N >> n;
    queue<int> q;
    vector<int> arr[INTMAX];
    int indegree[N+1]; // 각 number indegree 증가

    for(int i = 0; i < N+1; i++){ // indegree 초기화
        indegree[i] = 0;
    }

    int s1, s2;
    for(int i = 0; i< n; i++){
        cin >> s1 >> s2; // 키 비교한 두 학생
        //indegree[s1]++;
        indegree[s2]++; // 들어온 것만 기록하면 되므로 하나만 저장
        arr[s1].push_back(s2);
        //arr[s2].push_back(s1);
    }

    for(int i = 1; i < N+1; i++){//초기 indegree 0 인것 == 검사 대상 push 1,2
        if(indegree[i] == 0){
            q.push(i); // indegree 0 되면은 q에 push
        }
    }

    while(!q.empty()){
        int temp = q.front(); //1
        q.pop();
        cout << temp << " ";
        for(int i = 0; i < (int)arr[temp].size(); i++){
//            cout << "arr[temp][i] : " << arr[temp][i] << endl;
//            cout << "indegree[arr[temp][i]] : " << indegree[arr[temp][i]] << endl;
            indegree[arr[temp][i]]--;
            if(indegree[arr[temp][i]] == 0) q.push(arr[temp][i]);
        }

    }
    cout << endl;

}


int main(){
    line();
    return 0;
}

