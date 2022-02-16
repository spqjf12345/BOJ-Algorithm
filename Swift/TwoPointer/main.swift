//
//  2003_sum2.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/16.
//

import Foundation

let line1 = readLine()!.split(separator: " ")
let M = Int(line1[0])!
let N = Int(line1[1])!
var arr: [Int] = []

func input(){
    arr = readLine()!.split(separator: " ").map { Int($0)! }
}

func pointer() -> Int {
    input()

    var start = 0
    var end = 0
    var cnt = 0
    var sum = 0

    while(true){
        if(sum >= N){
            sum = sum - arr[start]
            start += 1
        }else if(end >= M) {
            break
        }else {
            sum = sum + arr[end]
            end += 1
        }

        if(sum == N){
            cnt += 1
        }
    }

    return cnt;

}

print(pointer())
