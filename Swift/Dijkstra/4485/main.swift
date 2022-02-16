//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

import Foundation
var dx: [Int] = [-1, 1, 0, 0]
var dy: [Int] = [0, 0, 1, -1]
var index = 1
var n = 0
var d = [[Int]]()


func find_jelda(map: [[Int]]) {
    var idx = 0
    var qu = [(Int, (Int, Int))]()
    d[0][0] = map[0][0]
    qu.append((-map[0][0],(0, 0))) // cost, x, y
    
    while (idx < qu.count) {
        let top = qu[idx]
        let x = top.1.0
        let y = top.1.1
        let dist = -top.0
        
        qu.removeLast()

        for i in 0 ..< 4 {
            let nx = dx[i] + x
            let ny = dy[i] + y
            let cost = dist + map[nx][ny]
            
            if (nx >= n || ny >= n || nx < 0 || ny < 0) { continue }
            if(d[nx][ny] == -1 || cost < d[nx][ny]) {
                d[nx][ny] = cost
                qu.append((-cost, (nx, ny)))
            }
        }
        idx += 1
    }
    
    print("Problem \(index): \(d[n-1][n-1])")
    index += 1
    
    
    
}

func solution(){
    repeat {
        var map = [[Int]]()
        n = Int(readLine()!.split(separator: " ")[0])!
        d = [[Int]](repeating: [Int](repeating: -1, count: n), count: n)
        if(n == 0){
            break
        }
        
        for _ in stride(from: 0, to: n, by: 1) {
            map.append(readLine()!.split(separator: " ").map { Int(String($0))! })
        }
        find_jelda(map: map)

    }while(n != 0)
}

solution()
