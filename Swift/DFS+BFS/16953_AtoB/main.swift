//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/05.
//


//var way:[Int] = [2, 1]
//var visit = Array(repeating: 0, count: 1000000)
//func AtoB() -> Int {
//    var queue = [Int]()
//    queue.append(n)
//    visit[n] = 0
//    if(n > m){ return -1 }
//
//    while(!queue.isEmpty){
//        let now = queue.popLast()!
//        var next = 0
//        for i in 0..<way.count {
//            if i == 0 {
//                next = n * n
//            }else {
//                next = Int("\(now)1")!
//            }
//            print(next)
//            if(n > m){ continue }
//            if(next > 1000000) { continue }
//            if(visit[next] != 0) { continue }
//            queue.append(next)
//            visit[next] = visit[now] + 1
//
//            if(next == m){
//                return visit[next];
//            }
//        }
//
//    }
//    return -1
//}

import Foundation

var line = readLine()!.split(separator: " ").map { Int($0)! }
var n = line[0]
var m = line[1]
var answer = 1000000
//var d: [Int] = Array(repeating: 0, count: 10000000)
//d[n] = 1 // root

func AtoB(_ n: Int, depth: Int) {
    if(n > m) { return }
    if(n == m){ answer = min(answer, depth) }
    AtoB(n*2, depth: depth + 1)
    AtoB(n*10 + 1, depth: depth + 1)
}

AtoB(n, depth: 1)
if(answer == 1000000){
    print(-1)
}else {
    print(answer)
}
