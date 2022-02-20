//
//  15652_N&M(4).cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/20.
//

#include <iostream>

using namespace std;
int N, M;
int arr[8];

//중복 허용 + 증가하는 순
void backTracking(int cnt, int num){
    if(cnt == M){
        //출력
        for(int i =0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = num; i <= N; i++){
        arr[cnt] = i;
        backTracking(cnt + 1, i); // num, i 차이
    }

}

int main(){
    cin >> N >> M;
    backTracking(0, 1);
    return 0;
}
