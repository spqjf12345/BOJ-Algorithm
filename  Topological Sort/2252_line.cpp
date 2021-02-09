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

using namespace std;

void line(){
    int N, n;
    //int maxValue = 0x7FFFFFF;
    
    cin >> N >> n;
    queue<int> q;
    vector<int> arr[32001];
    int indegree[N+1]; // 각 number indegree 증가

    for(int i = 0; i < N+1; i++){
        indegree[i] = 0;
    }

    int s1, s2;
    for(int i = 0; i< n; i++){
        cin >> s1 >> s2; // 키 비교한 두 학생
        //indegree[s1]++;
        indegree[s2]++; // 들어온 것만 기록하면 되므로
        arr[s1].push_back(s2); // 서로가 서로에 대해 인접 노드 저장
        //arr[s2].push_back(s1);
    }

    for(int i = 1; i < N+1; i++){//초기 indegree 0 인것 push 1,2
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


//#include <iostream>
//#include <stack>
//#include <vector>
//#define SIZE 32000
//
//using namespace std;
//int n, m;
//int visit[SIZE + 1];
//int arr[SIZE + 1];
//vector< vector<int> > student;
//
//void DFS(int node, stack<int> &s)
//{
//    visit[node] = true;
//    for (int x : student[node])
//    {
//        if (!visit[x])
//            DFS(x, s);
//    }
//    // 더 이상 선행 정점이 없는 경우 push
//    s.push(node);
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> n >> m;
//
//    student.resize(n + 1);
//    for (int i = 0; i < m; ++i)
//    {
//        int front, back;
//        cin >> front >> back;
//
//        student[front].push_back(back);
//    }
//    stack<int> s;
//    for (int i = 1; i <= n; ++i)
//    {
//        if (!visit[i])
//        {
//            DFS(i, s);
//        }
//    }
//
//
//        // 걸어둔 블로그 링크의 코드 스타일을 따라함
//
//
//    while (s.size())
//    {
//        cout << s.top() << " ";
//        s.pop();
//    }
//
//    return 0;
//}
