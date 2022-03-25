//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/25.
//

import Foundation
func bs(arr: [Int], m : Int) -> Int{
    var left = arr.max()! // 원소 중 가장 큰 값
    var right = arr.reduce(0, +) // 모든 원소의 합
    var mid = 0
    while(left <= right){
        mid = (left + right) / 2
        //print("\(left) \(right) \(mid) \(length(arr: arr, mid: mid))")
        if(length(arr: arr, mid: mid) <= m) {
            right = mid - 1
        }else {
            left = mid + 1
        }
        
    }
    return left
}

func length(arr: [Int], mid: Int) -> Int {
    var sum = 0
    var cnt = 1
    for i in 0..<arr.count {
        if(sum + arr[i] > mid){
            sum = 0
            cnt += 1
        }
        sum += arr[i]
    }
    return cnt
}

var line = readLine()!.split(separator: " ").map { Int($0)! }
var n = line[0]
var m = line[1]

var arr = readLine()!.split(separator: " ").map { Int($0)! }

print(bs(arr: arr, m: m))



