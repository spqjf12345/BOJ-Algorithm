//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/15.
//

import Foundation
var n = Int(readLine()!)!
var maxDay: Int = 0
var arr: [[Int]] = Array(repeating: [], count: n+1) // 1 ~ n+1
for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    let day = line[0], value = line[1]
    if(day > maxDay){
        maxDay = day
    }
    arr[day].append(value)
}

//for i in 0..<maxDay {
//    arr[i].sort(by: >)
//}

var sum = 0

for i in stride(from: maxDay, to: 0, by: -1) {
    var maxValue = 0
    var maxValueIndex = (0, 0)
    
    for j in i..<maxDay+1 {
        if arr[j].count != 0 {
            for k in 0..<arr[j].count {
                if(arr[j][k] > maxValue){
                    maxValue = arr[j][k]
                    maxValueIndex = (j, k)
                }
            }
        }
    }
    if maxValue != 0 {
        sum += maxValue
        arr[maxValueIndex.0][maxValueIndex.1] = 0
    }
    
}

print(sum)
