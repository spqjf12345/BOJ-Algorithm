#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, target, ans = 0;
int v[20];


void part_per_sum_dfs(int i, int sum) {

    if(i == n)
        return;
    sum += v[i];
    
    if(sum == target)
        ans++;

    
    //해당 숫자 더했을 경우
    part_per_sum_dfs(i+1, sum);
    
    //해당 숫자 더하지 않았을 경우
    part_per_sum_dfs(i+1, sum - v[i]);



}
int main(void) {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        
    }
    //cout << v[5] << " ";
    part_per_sum_dfs(0, 0);
    cout << ans;
    return 0;
}





