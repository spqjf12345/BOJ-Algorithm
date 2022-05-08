//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/08.
//

import Foundation
var Tcase = Int(readLine()!)!
var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]
var arr = [[Int]]()
var visit = [[Bool]]()

func dfs_All(_ n: Int, _ m: Int){
    var cnt = 0
    visit = Array(repeating: Array(repeating: false, count: m), count: n)
    for i in 0..<n {
        for j in 0..<m {
            if arr[i][j] == 1 && !visit[i][j] {
                dfs(n, m, i, j)
                cnt += 1
            }
        }
    }
    print(cnt)
}

func dfs(_ n:Int, _ m: Int,_ x: Int, _ y: Int){
    visit[x][y] = true
    
    for i in 0..<4 {
        var nx = x + dx[i]
        var ny = y + dy[i]
        if nx >= n || nx < 0 || ny < 0 || ny >= m { continue }
        if !visit[nx][ny] && arr[nx][ny] == 1 {
            visit[nx][ny] = true
            dfs(n, m, nx, ny)
        }
        
    }
    
}

for i in 0..<Tcase {
    var line = readLine()!.split(separator: " ").map { Int(String($0))! }
    var n = line[0]
    var m = line[1]
    var cnt = line[2]
    arr = Array(repeating: Array(repeating: 0, count: m), count: n)
    for i in 0..<cnt {
        var cabbage = readLine()!.split(separator: " ").map { Int(String($0))! }
        arr[cabbage[0]][cabbage[1]] = 1
    }

    dfs_All(n, m)
}
