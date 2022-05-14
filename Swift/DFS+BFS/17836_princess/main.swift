//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/13.
//

import Foundation
// 최단 시간 or 그람 구해서 유클리드 ? 거리 둘 중 작은 값 계산
var l = readLine()!.split(separator: " ").map { Int($0)! }
var n = l[0]
var m = l[1]
var time = l[2]

var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]
var map = Array(repeating: Array(repeating: 0, count: m), count: n)
var visit = Array(repeating: Array(repeating: false, count: m), count: n)
var knife: (Int, Int) = (0, 0)
var distance = 0
var ans = Array(repeating: Array(repeating: 0, count: m), count: n)
//input
for i in 0..<n {
    let line = readLine()!.split(separator: " ").map { Int($0)! }
    for j in 0..<line.count {
        map[i][j] = line[j]
        if map[i][j] == 2 { knife = (i, j) }
    }
}

func BFS() -> Int {
    distance = time
    var queue = [(Int, Int)]()
    queue.append((0, 0))
    visit[0][0] = true
    

    while !queue.isEmpty {
        let nx = queue.first!.0
        let ny = queue.first!.1
        queue.removeFirst()
        if nx == n - 1 && ny == m - 1 {
            return min(distance, ans[nx][ny])
        }
        if map[nx][ny] == 2 {
            distance = (n - 1 - nx) + (m - 1 - ny) + (ans[nx][ny])
        }
        
        for i in 0..<4 {
            let nextX = nx + dx[i]
            let nextY = ny + dy[i]
            
            if(nextX >= n || nextX < 0 || nextY < 0 || nextY >= m) { continue }
            if(visit[nextX][nextY] || map[nextX][nextY] == 1) { continue }
            ans[nextX][nextY] = ans[nx][ny] + 1
            visit[nextX][nextY] = true
            queue.append((nextX, nextY))
                
        }
    }
    if distance != time { return distance }
    return -1
}

var value = BFS()
if value == -1 { // 못감
    print("Fail")
}else {
    if value < time {
        print(value)
    }else {
        print("Fail")
    }
}

