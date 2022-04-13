////
////  main.swift
////  SOMA👩🏻‍💻
////
////  Created by JoSoJeong on 2022/04/13.
////
//
//import Foundation
//
//func checkReverse(_ p1: Int, _ p2: Int) -> Int {
//    var result = 0
//    if p1 > p2 {
//        result += (9 - p1) + (p2 - 0)
//    }else {
//       result += (9 - p2) + (p1 - 0)
//    }
//    return result
//}
//
//func check(_ p1: Int, _ p2: Int) -> Int {
//    return p2 - p1 > 0 ? p2 - p1 : p1 - p2
//}
//
//func solution(_ p:String, _ s:String) -> Int
//{
//    var ans = 0
//    for (idx, i) in p.enumerated() {
//
//        var me = i.asciiValue! - 48
//        var target = s[s.index(s.startIndex, offsetBy: idx)].asciiValue! - 48
//        ans += min(checkReverse(Int(me), Int(target)), check(Int(me), Int(target)))
//    }
//
//    return ans
//}

//import Foundation
//
//func solution(_ bread_schedule:[String], _ current_time:String, _ K:Int) -> Int {
//    var bread = dateToSecond(bread_schedule)
//    let curSecond = dateFormatter(current_time)
//    bread = bread.filter { $0.0 >= curSecond}
//
//    var result = 0
//    var goalBread = 0
//    //initial
//   for i in bread {
//       if goalBread < K {
//           goalBread += i.1 // 빵 더함
//           result += i.0 - curSecond
//       }else if goalBread >= K {
//           return result / 60 // 분으로 변환
//       }
//   }
//    return -1
//}
//
//func dateToSecond(_ arr: [String]) -> [(Int, Int)] {
//    var result = [(Int, Int)]()
//    for i in arr {
//        var line = i.split(separator: " ").map { String($0) }
//        result.append((dateFormatter(line[0]), Int(line[1])!))
//    }
//    return result
//}
//
//func dateFormatter(_ str: String) -> Int {
//    let dateFormatter = DateFormatter()
//    dateFormatter.dateFormat = "HH:mm"
//    let date = dateFormatter.date(from: str)
//    return Int(date!.timeIntervalSince1970)
//}

//var N = Int(String(readLine()!))!
//if N == 1 {
//    print("")
//}
//for i in stride(from: 2, through: N, by: 1) {
//    while N % i == 0 {
//        print("\(i)")
//        N = N / i
//    }
//}

