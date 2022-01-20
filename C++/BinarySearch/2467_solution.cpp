#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <string>

using namespace std;

unordered_map<string, int> solution(int arr[],int n){
    int acidArr[n];
    int alkaliArr[n];
    fill_n(acidArr, n, -1);
    fill_n(alkaliArr, n, -1);
    
    int acidCount = 0;
    int alkaliCount = 0;
    
    unordered_map<string, int> mapping;
    mapping["acid"] = 0;
    mapping["alkali"] = 0;
    
    for(int i =0; i<n; i++){
        if(arr[i] < 0){ //put in acidArr
            acidArr[acidCount] = arr[i];
            acidCount++;
        }else if (arr[i] > 0){
            alkaliArr[alkaliCount] = arr[i];
            alkaliCount++;
        }
    }

    int initDiff = 0xffff;
    for(int acidJ = 0; acidArr[acidJ] != -1; acidJ++){
        for(int alkaliJ = 0; alkaliArr[alkaliJ] != -1; alkaliJ++){
            int diff = (acidArr[acidJ] + alkaliArr[alkaliJ]) - 0;
            if(abs(diff) < abs(initDiff)){
                initDiff = diff;
                mapping["acid"] = acidArr[acidJ];
                mapping["alkali"] = alkaliArr[alkaliJ];
            }
        }
    }
    
    return mapping;
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
    
    unordered_map<string, int> mapping = solution(arr,n);
    int acid = mapping["acid"];
    int alkali = mapping["alkali"];
    cout << acid << " " << alkali << " " << endl;
    
    return 0;
}

