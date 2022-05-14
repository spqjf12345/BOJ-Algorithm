//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/13.
//

import Foundation
var l = readLine()!.split(separator: " ").map { Int($0)! }
var n = l[0]
var m = l[1]

var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]
var destination: (Int, Int) = (0, 0)
var ans = Array(repeating: Array(repeating: 0, count: m), count: n)
var map = Array(repeating: Array(repeating: 0, count: m), count: n)
var visit = Array(repeating: Array(repeating: false, count: n), count: m)

for i in 0..<n {
    let line = readLine()!.split(separator: " ").map { Int($0)! }
    for j in 0..<line.count {
        map[i][j] = line[j]
        if map[i][j] == 2 { destination = (i, j) }
    }
}

func BFS(x: Int, y: Int){
    var queue = [(Int, Int)]()
    queue.append((x, y))
    visit[x][y] = true
    while !queue.isEmpty {
        var nx = queue.first!.0
        var ny = queue.first!.1
        queue.removeFirst()
        
        for i in 0..<4 {
            let nextX = nx + dx[i]
            let nextY = ny + dy[i]
            
            if(nextX >= n || nextX < 0 || nextY < 0 || nextY >= m) { continue }
            if(visit[nextX][nextY]) { continue }
            
            if map[nextX][nextY] == 1 {
                visit[nextX][nextY] = true
                queue.append((nextX, nextY))
                ans[nextX][nextY] = ans[nx][ny] + 1
            }
        }
    }
    ans[destination.0][destination.1] = 0
    
}

BFS(x: destination.0, y: destination.1)
//print(visit)

for i in 0..<n {
    for j in 0..<m {
        if map[i][j] == 1 && visit[i][j] == false {
            ans[i][j] = -1
        }
    }
}

ans[destination.0][destination.1] = 0
for i in 0..<ans.count {
    print(ans[i].map { String($0) }.joined(separator: " "))
}




