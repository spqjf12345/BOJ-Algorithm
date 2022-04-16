//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/17.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]
var tree: [[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)

for _ in 0..<m {
    let l = readLine()!.split(separator: " ").map { Int(String($0))! }
    tree[l[0]][l[1]] = 1
    tree[l[1]][l[0]] = 1
}


func bfs_level(start: Int, cnt: Int) -> Int {
    var visit: [Bool] = Array(repeating: false, count: n+1)
    var queue = [(Int, Int)]()
    var answer = 0
    visit[start] = true
    queue.append((start, cnt))
    
    while !queue.isEmpty {
        let now = queue.first!.0
        let cnt = queue.first!.1
        queue.removeFirst()
        
        for i in 1..<n+1 {
            if !visit[i] && tree[now][i] == 1 {
//                print("start => \(now)  i \(i) cnt \(cnt)")
                answer += cnt
                queue.append((i, cnt + 1))
                visit[i] = true
            }
        }

    }
    
    return answer
}

var answer = 0
var min = 10000
for i in 1..<n {
    let temp = bfs_level(start: i, cnt: 1)
    if(temp < min) {
        min = temp
        answer = i
    }
}
print(answer)
