//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/18.
//

import Foundation

var dx = [-1, 0, 1, 0]
var dy = [0, 1, 0, -1]

var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]

var line2 = readLine()!.split(separator: " ").map { Int(String($0))! }
var r = line2[0]
var c = line2[1]
var dir = line2[2]

var cnt = 1 // 현재까지 cnt
var arr: [[Int]] = Array(repeating: [], count: n)
var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: m), count: n)

for i in 0..<n {
    let l = readLine()!.split(separator: " ").map { Int(String($0))! }
    arr[i] = l
}
//현재 위치 방문
visit[r][c] = true


func leftTurn(_ now: Int, _ i: Int) -> Int {
   return (now + 3 - i) % 4 // 북 - 0, 동 - 1, 남 - 2, 서 - 3
}

func dfs_clean(_ cnt: Int, _ now: Int, _ x: Int, _ y: Int) {
    for i in 0..<4{
        let nextD = leftTurn(now, i)
        let nextX = dx[nextD] + x
        let nextY = dy[nextD] + y
        if (nextX >= n || nextX < 0 || nextY >= m || nextY < 0) { continue }
        if (visit[nextX][nextY] == true || arr[nextX][nextY] == 1) { continue }
        visit[nextX][nextY] = true
        dfs_clean(cnt + 1, nextD, nextX, nextY)
    }
    
    //4번 연속 실행을 끝내고
    //바로 뒤가 벽이면 멈춤
    // 아니면 후진
    
    let backIdx = now > 1 ? now - 2: now + 2
    let backX = dx[backIdx] + x
    let backY = dy[backIdx] + y

    if backX < n || backX > 0 || backY < m || backY > 0  {
        if arr[backX][backY] == 1 {
            print(cnt)
            exit(0)
        }else {
            dfs_clean(cnt, now, backX, backY) //후진 시 방향은 바뀌지 x
        }
    }
    
}

dfs_clean(cnt, dir, r, c)
