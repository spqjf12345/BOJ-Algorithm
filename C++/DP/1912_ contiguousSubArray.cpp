//
//  1912_ contiguousSubArray.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/25.
//

#include <iostream>
#include <algorithm>

using namespace std;
int result = -100000;
int N, sum;
int arr[100001];

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        if(sum < 0){
            sum = 0;
        }
        sum += arr[i];
        result = max(result, sum);
    }
    
    cout << result << '\n';
    return 0;
}
