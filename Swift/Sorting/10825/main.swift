//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/15.
//

import Foundation
var n = Int(readLine()!)!
var arr = [[String]]()
for _ in 0..<n {
    var line = readLine()!.split(separator: " ").map { String($0) }
    arr.append(line)
}
func compare(s1: [String], s2: [String]) -> Bool {
    if Int(s1[1])! > Int(s2[1])! { // 국어 감소 순
        return Int(s1[1])! > Int(s2[1])!
    } else if Int(s1[1])! == Int(s2[1])! {
        if Int(s1[2])! < Int(s2[2])! { // 영어 증가 순
            return Int(s1[2])! < Int(s2[2])!
        }else if Int(s1[2])! == Int(s2[2])! {
            if Int(s1[3])! > Int(s2[3])! { // 수학 감소하는 순
                return Int(s1[3])! > Int(s2[3])!
            }else if Int(s1[3])! == Int(s2[3])! { //사전으로 증가하는 순
                return s1[0] < s2[0]
            }
        }
    }
    return false
}

arr.sort(by: compare(s1:s2:))
for i in arr.map { $0[0]} {
    print(i)
}
