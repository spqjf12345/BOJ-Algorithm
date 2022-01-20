//
//  14888_put_operator.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/05.
//

#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;
int N;
vector<int> v;
int op[4];
int mymin = 1000000001;
int mymax = -1000000001;
int chk[11];

//void permutation(int result, int idx){
//    if(idx == N){
//        if(result > mymax) {
//            mymax = result;
//        }
//        if(result < mymin) {
//            mymin = result;
//        }
//        return;
//    }
//
//    for(int i =0; i < 4; i++){ /// +  -  *  %
//        if(op[i] > 0){
//            op[i]--;
//            if(i == 0){
//                permutation(result + v[idx], idx+1);
//            }
//            else if(i == 1){
//               permutation(result - v[idx], idx+1);
//            }
//            else if(i == 2){
//               permutation(result * v[idx], idx+1);
//            }
//            else {
//               permutation(result / v[idx], idx+1);
//            }
//            op[i]++; //다른 연산자 사용
//        }
//    }
//    return;
//}
//
//int main(){
//    cin >> N;
//    for(int i =0; i < N; i++){
//        int temp;
//        cin >> temp;
//        v.push_back(temp);
//    }
//
//    for(int i =0; i < 4; i++){ //4 operator
//        int temp;
//        cin >> temp;
//        op[i] = temp;
//    }
//    permutation(v[0], 1);
//
//    cout << mymax << '\n';
//    cout << mymin << '\n';
//
//    return 0;
//}
void calcul(){
    int temp = v[0];
    for(int i = 1; i < N; i++){ /// +  -  *  %
        switch (chk[i]) {
            case 0: temp += v[i]; break;
            case 1: temp -= v[i]; break;
            case 2: temp *= v[i]; break;
            case 3: temp /= v[i]; break;
        }
    }
    if(temp > mymax) { mymax = temp; }
    if(temp < mymin) { mymin = temp; }
}

void dfs(int node){
    if(node == N) {
        calcul();
        return;
    }else {
        for(int i = 0; i < 4; i++){
            if(op[i] == 0) continue;
            chk[node] = i; // 수행할 연산자
            op[i]--;
            dfs(node+1);
            op[i]++;
            chk[node] = 0;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i =0; i < 4; i++){ //4 operator
        int temp;
        cin >> temp;
        op[i] = temp;
    }
    
    dfs(1); // depth

    cout << mymax << '\n';
    cout << mymin << '\n';

    return 0;
}
