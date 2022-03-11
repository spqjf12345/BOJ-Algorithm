//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/11.
//

import Foundation
var n = Int(readLine()!)!
var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
var visit = Array(repeating: Array(repeating: false, count: n), count: n)
var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]

func bfs(_ i: Int, _ j: Int){
   visit[i][j] = true
    var qu = [(Int, Int)]()
    qu.append((i, j))
    
    while(!qu.isEmpty){
        let nx = qu.last!.0
        let ny = qu.last!.1
        qu.removeLast()
        for i in 0..<4 {
            let nextX = nx + dx[i]
            let nextY = ny + dy[i]
            if(nextX >= n || nextX < 0 || nextY >= n || nextY < 0) { continue }
            if(visit[nextX][nextY]) { continue }
            //print("\(nextX) \(nextY)")
            visit[nextX][nextY] = true
            qu.append((nextX, nextY))
        }
        
    }
}

func bfsAll() -> Int {
    var cnt = 0;
    for i in 0..<n {
        for j in 0..<n {
            if(!visit[i][j]){
                bfs(i, j)
                cnt += 1
            }
        }
    }
    return cnt
}

var totalArea = 0
var maxNumber = 0
for i in 0..<n {
    let line = readLine()!.split(separator:  " ").map { Int($0)! }
    for j in 0..<line.count {
        arr[i][j] = line[j]
        if(arr[i][j] > maxNumber){
            maxNumber = arr[i][j]
        }
    }
}

for k in 0..<maxNumber {
    for i in 0..<n {
        for j in 0..<n {
            if(arr[i][j] <= k){
                visit[i][j] = true
            }
        }
    }
    totalArea = max(bfsAll(), totalArea)
    visit = Array(repeating: Array(repeating: false, count: n), count: n) // 다시 초기화
}
print(totalArea)






