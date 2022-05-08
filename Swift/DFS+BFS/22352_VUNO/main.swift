//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/08.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]

var originalMap = [[Int]]()
var changedMap = [[Int]]()
var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]

for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map { Int(String($0))! }
    originalMap.append(line)
}

for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map { Int(String($0))! }
    changedMap.append(line)
}
func dfs(originalValue: Int, updateValue: Int, x: Int, y: Int){
    print(originalValue, updateValue, x, y)
    var visit = Array(repeating: Array(repeating: false, count: m), count: n)
    var queue = [(Int, Int)]()
    visit[x][y] = true
    originalMap[x][y] = updateValue
    queue.append((x, y))
    
    while !queue.isEmpty {
        let x = queue.first!.0
        let y = queue.first!.1
        queue.removeFirst()
        for i in 0..<4 {
            var nx = x + dx[i]
            var ny = y + dy[i]
            if(nx >= n || nx < 0 || ny >= m || ny < 0) { continue }
            if(visit[nx][ny] || originalMap[nx][ny] != originalValue) { continue }
            originalMap[nx][ny] = updateValue
            visit[nx][ny] = true
            queue.append((nx, ny))
        }
    }
    
    print(originalMap)
    
}
func compareMap() -> String {
    if originalMap == changedMap {
        print("hree")
        return "YES"
    }
    for i in 0..<n {
        for j in 0..<m {
            if originalMap[i][j] != changedMap[i][j] {
                //dfs
                dfs(originalValue: originalMap[i][j], updateValue: changedMap[i][j], x: i, y: j)
                if originalMap == changedMap { return "YES" }
                else { return "NO" }
            }
        }
    }
    return "YES"
}

print(compareMap())

