//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/19.
//

import Foundation
var n = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map { Int(String($0))! }
var d = Array(repeating: 0, count: n + 1)
arr.insert(0, at: 0)
d[1] = arr[1]

for i in 2..<n+1 {
    var maxValue = 0
    for j in 1..<i {
        maxValue = max(maxValue, d[j] + arr[i-j])
    }
    d[i] = max(arr[i], maxValue)
}

print(d[n])


//func solution(_ a:String, _ b:String) -> String{
//    var answer:String = ""
//    var len = a.count > b.count ? a.count : b.count
//    var short = a.count < b.count ? a.count : b.count
//    var strArr: [Int] = Array(repeating: 0, count: len)
//    var aArr = Array(a.reversed())
//    var bArr = Array(b.reversed())
//
//    for i in stride(from: 0, to: short, by: 1) {
//        strArr[i] = Int((aArr[i].asciiValue! - 48) + (bArr[i].asciiValue! - 48))
//    }
//    if a.count > short {
//        while short < a.count {
//            strArr[short] = Int(aArr[short].asciiValue! - 48)
//            short += 1
//        }
//    }
//
//    if b.count > short { // 자릿수가 더 많다면
//        while short < b.count {
//            strArr[short] = Int(bArr[short].asciiValue! - 48)
//            short += 1
//        }
//    }
//    for i in 0..<strArr.count {
//        if strArr[i] / 10 >= 1 { // 10의 자리 이상
//            if i == strArr.count - 1 { strArr.append(0) } // 자릿수 늘리기
//            strArr[i+1] += strArr[i] / 10
//            strArr[i] %= 10
//        }
//    }
//    for i in strArr.reversed() {
//        answer += "\(i)"
//    }
//
//    return answer
//}
//print(solution("1111", "8889"))
