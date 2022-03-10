//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/10.
//

import Foundation
var line1 = readLine()!.split(separator: " ").map { Int($0)! }
var itemArr = readLine()!.split(separator: " ").map { Int($0)! }
var n = line1[0]
var m = line1[1]
var dist = line1[2]

var node:[[(Int, Int)]] = Array(repeating: [(0, 0)], count: n+1)
var d = Array(repeating: 1000000000, count: n+1) // 최단 거리 테이블



for _ in 0..<dist {
    let costLine = readLine()!.split(separator: " ").map { Int($0)! }
    node[costLine[0]].append((costLine[1], costLine[2])) // 정점, 거리
    node[costLine[1]].append((costLine[0], costLine[2]))
}


func dijkstra(start: Int){
    var visit: [Bool] = Array(repeating: false, count: n+1)
    var qu = [(Int, Int)]()
    for i in 0..<n+1 {
        d[i] = 1000000000
    }
    d[start] = 0
    qu.append((0, start)) // 거리, 시작점
    
    while(!qu.isEmpty){
        let dist = qu.last!.0
        let next = qu.last!.1
        qu.removeLast()
        
        if(!visit[next]){
            visit[next] = true
            for i in 1..<node[next].count {
                //print("\(next) \(node[next])")
                let cost = dist + node[next][i].1
                //거쳐 가는 거리 더 작다면
                if(cost < d[node[next][i].0]){
                    d[node[next][i].0] = cost
                    qu.append((cost, node[next][i].0))
                    //print("\(cost) \(node[next][i].0)")
                }
            }
        }
        
    }
    
    
}

var answer = 0
for i in 1..<n+1 { // 1 ~ n+1번 노드에 대해서 다익스트라 수행
    dijkstra(start: i)
    var total = 0
    for j in 1..<n+1 {
        if(d[j] <= m) { total += itemArr[j-1] }
        answer = max(answer, total)
    }
}
print(answer)





