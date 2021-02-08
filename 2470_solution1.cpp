#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return abs(a) < abs(b);
}

void solution1(int arr[], int n){
    sort(arr, arr + n, compare);
    
    int initDiff = 2147483647;
    int acid = 0, alkali = 0;
    
    for(int i = 0; i< n - 1; i++){
        int diff = (arr[i] + arr[i+1]) - 0;
        if(abs(diff) < initDiff){
            initDiff = abs(diff);
            acid = arr[i];
            alkali = arr[i+1];
        }
        
    }
    
    if (acid > alkali){
        swap(acid, alkali);
    }
        
    cout << acid << " " << alkali << endl;
}

int main() {
    int n;
    int i=0;
    
    cin >> n;
    int arr[n];
    
    while(i<n){
        cin >> arr[i];
        i++;
    }
    solution1(arr,n);
    return 0;
}

