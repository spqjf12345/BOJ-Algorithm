//
//  Stack.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/20.
//

import Foundation

//O(n)
public struct Stack<T> {
    fileprivate var array = [T]()
    
    public var isEmpty: Bool {
        return array.isEmpty
    }
    
    public mutating func push(_ element: T){
        array.append(element)
    }
    
    public mutating func pop() -> T? {
        return array.popLast()
    }
    
    public var top: T? {
        return array.last
    }
}
