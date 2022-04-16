//
//  BinarySearch.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/16.
//

import Foundation

public class BinarySearchTree<T: Comparable> {
      private(set) public var value: T
      private(set) public var parent: BinarySearchTree?
      private(set) public var left: BinarySearchTree?
      private(set) public var right: BinarySearchTree?

      public init(value: T) {
        self.value = value
      }
    
    public convenience init(array: [T]) {
      precondition(array.count > 0)
      self.init(value: array.first!)
      for v in array.dropFirst() {
        insert(value: v)
      }
    }

      public var isRoot: Bool {
        return parent == nil
      }

      public var isLeaf: Bool {
        return left == nil && right == nil
      }

      public var isLeftChild: Bool {
        return parent?.left === self
      }

      public var isRightChild: Bool {
        return parent?.right === self
      }

      public var hasLeftChild: Bool {
        return left != nil
      }

      public var hasRightChild: Bool {
        return right != nil
      }

      public var hasAnyChild: Bool {
        return hasLeftChild || hasRightChild
      }

      public var hasBothChildren: Bool {
        return hasLeftChild && hasRightChild
      }

      public var count: Int {
        return (left?.count ?? 0) + 1 + (right?.count ?? 0)
      }
    
    //insert
    public func insert(value: T) {
       if value < self.value {
         if let left = left {
           left.insert(value: value)
         } else {
           left = BinarySearchTree(value: value) // 왼쪽 노드가 없다면
           left?.parent = self
         }
       } else {
         if let right = right {
           right.insert(value: value)
         } else {
           right = BinarySearchTree(value: value) // 오른쪽 노드가 없다면
           right?.parent = self
         }
       }
     }
    
    //travel
    public func search(_ value: T) -> BinarySearchTree? {
        if value < self.value {
          return left?.search(value)
        } else if value > self.value {
          return right?.search(value)
        } else {
          return self  // found it!
        }
      }
    
    public func traverseInOrder(process: (T) -> Void) {
      left?.traverseInOrder(process: process)
      process(value)
      right?.traverseInOrder(process: process)
    }

    public func traversePreOrder(process: (T) -> Void) {
      process(value)
      left?.traversePreOrder(process: process)
      right?.traversePreOrder(process: process)
    }

    public func traversePostOrder(process: (T) -> Void) {
      left?.traversePostOrder(process: process)
      right?.traversePostOrder(process: process)
      process(value)
    }
}

extension BinarySearchTree: CustomStringConvertible {
  public var description: String {
    var s = ""
    if let left = left {
      s += "(\(left.description)) <- "
    }
    s += "\(value)"
    if let right = right {
      s += " -> (\(right.description))"
    }
    return s
  }
    
    private func reconnectParentTo(node: BinarySearchTree?) {
        if let parent = parent {
          if isLeftChild {
            parent.left = node
          } else {
            parent.right = node
          }
        }
        node?.parent = parent
      }
    
    public func minimum() -> BinarySearchTree {
       var node = self
       while let next = node.left {
         node = next
       }
       return node
     }

     public func maximum() -> BinarySearchTree {
       var node = self
       while let next = node.right {
         node = next
       }
       return node
     }
    
    ///@discardableResult - return 되지 않아도 에러를 띄워주지 말기
    @discardableResult public func remove() -> BinarySearchTree? {
       let replacement: BinarySearchTree?

       // Replacement for current node can be either biggest one on the left or
       // smallest one on the right, whichever is not nil
       if let right = right {
         replacement = right.minimum()
       } else if let left = left {
         replacement = left.maximum()
       } else {
         replacement = nil
       }

       replacement?.remove()

       // Place the replacement on current node's position
       replacement?.right = right
       replacement?.left = left
       right?.parent = replacement
       left?.parent = replacement
       reconnectParentTo(node:replacement)

       // The current node is no longer part of the tree, so clean it up.
       parent = nil
       left = nil
       right = nil

       return replacement
     }
    
    public func height() -> Int {
        if isLeaf {
          return 0
        } else {
          return 1 + max(left?.height() ?? 0, right?.height() ?? 0)
        }
      }
    
    ///returns the node whose value precedes the current value in sorted order
    /// O(h)
    public func predecessor() -> BinarySearchTree<T>? {
      if let left = left {
        return left.maximum()
      } else {
        var node = self
        while let parent = node.parent {
          if parent.value < value { return parent }
          node = parent
        }
        return nil
      }
    }
    
    /// O(h)
    public func successor() -> BinarySearchTree<T>? {
        if let right = right {
          return right.minimum()
        } else {
          var node = self
          while let parent = node.parent {
            if parent.value > value { return parent }
            node = parent
          }
          return nil
        }
      }
}

public enum BinarySearchTreeEnum<T: Comparable> {
  case Empty
  case Leaf(T)
  indirect case Node(BinarySearchTreeEnum, T, BinarySearchTreeEnum)
    
    public var count: Int {
       switch self {
       case .Empty: return 0
       case .Leaf: return 1
       case let .Node(left, _, right): return left.count + 1 + right.count
       }
     }

     public var height: Int {
       switch self {
       case .Empty: return -1
       case .Leaf: return 0
       case let .Node(left, _, right): return 1 + max(left.height, right.height)
       }
     }
    
    //insert
    public func insert(_ newValue: T) -> BinarySearchTreeEnum {
      switch self {
      case .Empty:
        return .Leaf(newValue)

      case .Leaf(let value):
        if newValue < value {
          return .Node(.Leaf(newValue), value, .Empty)
        } else {
          return .Node(.Empty, value, .Leaf(newValue))
        }

      case .Node(let left, let value, let right):
        if newValue < value {
          return .Node(left.insert(newValue), value, right)
        } else {
          return .Node(left, value, right.insert(newValue))
        }
      }
    }
    
    public func search(_ x: T) -> BinarySearchTreeEnum? {
      switch self {
      case .Empty:
        return nil
      case .Leaf(let y):
        return (x == y) ? self : nil
      case let .Node(left, y, right):
        if x < y {
          return left.search(x)
        } else if y < x {
          return right.search(x)
        } else {
          return self
        }
      }
    }
}

extension BinarySearchTreeEnum: CustomDebugStringConvertible {
  public var debugDescription: String {
    switch self {
    case .Empty: return "."
    case .Leaf(let value): return "\(value)"
    case .Node(let left, let value, let right):
      return "(\(left.debugDescription) <- \(value) -> \(right.debugDescription))"
    }
  }
}




let tree = BinarySearchTree<Int>(value: 7)
//tree.insert(2)
//tree.insert(5)
//tree.insert(10)
//tree.insert(9)
//tree.insert(1)

let tree2 = BinarySearchTree<Int>(array: [7, 2, 5, 10, 9, 1])
//tree.search(5)
//tree.traverseInOrder { value in print(value) }


//enum use like this
var tree3 = BinarySearchTreeEnum.Leaf(7)
//tree = tree.insert(2)
//tree = tree.insert(5)
//tree = tree.insert(10)
//tree = tree.insert(9)
//tree = tree.insert(1)

//tree.search(10)
//tree.search(1)
//tree.search(11)

//왼쪽 노드와 오른쪽 노드의 불균형으로 O(n)에 가까워질때
//양쪽 노드를 보간하는 작업이 필요
//AVL tree or red-black tree 통해 수행
