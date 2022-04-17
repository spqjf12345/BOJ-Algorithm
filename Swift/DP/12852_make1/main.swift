//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/17.
//

import Foundation

var d = Array(repeating: 0, count: 1000001) // n을 1로 만드는 최단 경우의 수
var n = Int(readLine()!)!
//var trackd = [Int]()
// top down 방식
//d[2] = 1
//d[3] = 1
//func dp(_ n: Int) -> Int {
//    var max = 1000001
//    if n == 1 { return d[n] }
//    if n == 0 { return 0 }
//    if d[n] > 0 { return d[n] }
//
//    if n % 3 == 0 { max = min(dp(n / 3) + 1, max) }
//
//    if n % 2 == 0 { max = min(dp(n / 2) + 1, max) }
//
//    max = min(dp(n-1) + 1, max)
//    d[n] = max
//
//    return d[n]
//}
//
//func tracking(_ n: Int) {
//    if n == 0 { return }
//    trackd.append(n)
//    if n % 3 == 0 && (d[n] == d[n/3] + 1) {
//        tracking(n/3)
//    }else if n % 2 == 0 && (d[n] == d[n/2] + 1) {
//        tracking(n/2)
//    }else if n - 1 >= 0 && (d[n] == d[n-1] + 1) {
//        tracking(n-1)
//    }
//}
//
//print(dp(n))
//tracking(n)
//for i in trackd {
//    print(i, terminator: " ")
//}

var traced: [Int] = Array(repeating: 0, count: 1000001)
func dp(_ n: Int) -> Int {
    traced[2] = 1
    traced[3] = 1
    d[2] = 1
    d[3] = 1
    if n <= 3 { return d[n] }
    for i in 4...n {
        var max = 1000001
        var from = -1
        max = min(d[i-1] + 1, max)
        if i % 2 == 0 {
            max = min(d[i / 2] + 1, max)
            if max == d[i / 2] + 1 { from = 2 }
        }
        if i % 3 == 0 {
            max = min(d[i / 3] + 1, max)
            if max == d[i / 3] + 1 { from = 3 }
        }

        if from == -1 {
            traced[i] = i - 1
        }else {
            traced[i] = i / from
        }
        d[i] = max
    
    }
    return d[n]
}
print(dp(n))
print(n, terminator: " ")
var i = n
while i > 0 {
    if i == 1 { break }
    print(traced[i], terminator: " ")
    i = traced[i] // index
}
