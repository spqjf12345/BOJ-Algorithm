//
//  11279_maxHeap.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/02.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef struct maxHeap {
    int heap[MAX];
    int count;
}heap;

int N;

void push(heap * hp, int n){
    if(hp->count >= MAX) return;
    hp->heap[hp->count] = n; // 마지막 원소에 데이터 삽입
    int nowIndex = hp->count; // 현재 인덱스
    int parentIndex = (hp->count -1)/2;
    while(nowIndex > 0 && hp->heap[nowIndex] > hp->heap[parentIndex]){
        swap(hp->heap[nowIndex], hp->heap[parentIndex]);
        nowIndex = parentIndex;
        parentIndex = (parentIndex - 1)/2;
        
    }
    hp->count++;
}

int pop(heap * hp){
    if(hp->count <= 0){ // 원소가 비어있으면
        return 0;
    }
    int root = hp->heap[0];
    hp->count--;
    hp->heap[0] = hp->heap[hp->count]; // 마지막 원소 대입
    
    int nowIndex = 0;
    int leftChild = 1; int rightChild = 2;
    int target = nowIndex;
    
    while(leftChild < hp->count){
        if(hp->heap[target] < hp-> heap[leftChild]) target = leftChild;
        if(hp->heap[target] < hp->heap[rightChild] && rightChild < hp->count) target = rightChild;
        if(target == nowIndex) break;
        else{
            swap(hp->heap[nowIndex], hp->heap[target]);
            nowIndex = target;
            leftChild = nowIndex * 2 + 1;
            rightChild = nowIndex * 2 + 2;
           }
       }
    return root;

}
    

int main(){
    heap hp;
    hp.count = 0;

    cin >> N;
    for(int i =0; i< N; i++){
        int n;
        cin >> n;
        if(n == 0){
            // 가장 큰 값 출력
            // 원소 제거
            int result = pop(&hp);
            cout << result << '\n';
        }else{
            //n push
            push(&hp, n);
            
        }
    }
    return 0;
}
