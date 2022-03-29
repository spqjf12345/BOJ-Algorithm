//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int($0)! }
var n = line[0]
var m = line[1]

var arr = readLine()!.split(separator: " ").map { Int($0)! }

var startIndex = 0
var endIndex = 0
var sum = arr[startIndex]
var length = 1000000

func findMinLength() -> Int {
    if(arr.reduce(0, +) < m){
        return 0;
    }
    while endIndex < n {
        if(sum >= m){
            var tempIndex = startIndex
            while(tempIndex <= endIndex) {
                if(sum - arr[tempIndex] >= m){
                    sum -= arr[tempIndex]
                    tempIndex += 1
                }else {
                    break;
                }
            }
            //print("startIndex \(tempIndex) endIndex \(endIndex)")
            length = min(length, endIndex - tempIndex + 1)
            startIndex = tempIndex
        }
        if(endIndex + 1 < n){
            sum += arr[endIndex+1]
        }
        endIndex += 1

        //print("sum \(sum)")
    }
    return length
}

print(findMinLength())

