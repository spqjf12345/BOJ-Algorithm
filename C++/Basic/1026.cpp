//
//  1026.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/21.
//

#include <iostream>
#include <algorithm>

using namespace std;
int N;
int A[10001];
int B[10001];
int sum = 0;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    reverse(A,A+N);
    
    for(int i = 0; i < N; i++){
        sum += A[i] * B[i];
    }
    cout << sum << '\n';
    
    return 0;
}
