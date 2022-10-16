//
//  Stack.swift
//  Stack
//
//  Created by Stevhen on 12/10/22.
//

import Foundation

public class Book {
    var stackId: String
    var bookName: String
    
    init(stackId: String, bookName: String) {
        self.stackId = stackId
        self.bookName = bookName
    }
}

//To create Node property
public class Node<T> {
    var value: T
    
    init(value: T){
        self.value = value
    }
    
    var next: Node<T>?
    weak var prev: Node<T>?
}

//Data Structure logics
public class DoubleLinkedList<T> {
    fileprivate var head: Node<T>?
    private var tail: Node<T>?
    
    public var isEmpty: Bool {
        return head == nil
    }
    
    public var first: Node<T>? {
        return head;
    }
    
    public var last: Node<T>? {
        return tail
    }
    
    public func push(value: T) {
        
        let curr = Node(value: value)
        
        if let headNode = head {
            headNode.prev = curr
            curr.next = headNode
        }
        
        head = curr
    }
    
    public func getNode(index: Int) -> Node<T>? {
        
        if index >= 0 {
            var curr = head
            var i = index
            
            while curr != nil {
                if i == 0 { return curr }
                i -= 1
                curr = curr!.next
            }
        }
        
        return nil
    }
    
    public func getSize() -> Int{
        var curr = head
        var  i: Int = 0
        
        while curr != nil {
            i += 1
            curr = curr!.next
        }
        
        return i
    }
    
    public func pop(curr: Node<T>) -> T {
        let prev = curr.prev
        let next = curr.next
        
        if let prev = prev {
            prev.next = next
        } else {
            head = next
        }
        
        next?.prev = prev
        
        if next == nil {
            tail = prev
        }
        
        curr.prev = nil
        curr.next = nil
        
        return curr.value
    }
    
    public func popAll() {
        head = nil
        tail = nil
    }
}


public struct Stack<T> {
    
    fileprivate var list = DoubleLinkedList<T>()
    
    public var isEmpty: Bool {
        return list.isEmpty
    }
    
    public mutating func push(_ element: T){
        list.push(value: element)
    }
    
    public mutating func pop() -> T? {
        guard !list.isEmpty, let element = list.first else { return nil }
        
        let removedElement = list.pop(curr: element)
        
        return removedElement
    }
    
    public func peek() -> T? {
        return list.first?.value
    }
    
    public func getSize() -> Int {
        return list.getSize()
    }
    
    public func peekAt(index: Int) -> Node<T>? {
        return list.getNode(index: index)
    }
    
    public func popAll(){
        list.popAll()
    }

}

//Main Program
public func pushBook(){
    print("Enter book id: ", terminator: "")
    let stackId: String? = readLine()
    print("Enter book name: ", terminator: "")
    let bookName: String? = readLine()

    stack.push(Book(stackId: stackId!, bookName: bookName!))
    
    print("Book with \(stackId!) added to stack")
}

public func clrScr(){
    for _ in 1...25 {
        print("")
    }
}

public func separatorBar(length : Int){
    for _ in 1...length {
        print("=", terminator: "")
    }
    print("")
}

public func showStack(){

    if stack.isEmpty {
        print("No data yet")
    }
    else{
        let header: String = String(format: "| %-4s | %-12s | %-15s |", ("No" as NSString).utf8String!,("ID" as NSString).utf8String!, ("Book Name" as NSString).utf8String!)
        
        separatorBar(length: header.count)
        print(header)
        separatorBar(length: header.count)
        for i in 0 ..< stack.getSize()  {
            let curr = stack.peekAt(index: i)
            print(String(format: "| %-4d | %-12s | %-15s |", i+1, (curr!.value.stackId as NSString).utf8String!, (curr!.value.bookName as NSString).utf8String!))
        }
        separatorBar(length: header.count)
    }

}

public func popBook(){
    if stack.isEmpty {
       print("No data yet")
   }
   else{
        if let buyer = stack.pop() {
            print("Book with ID: \(buyer.stackId) taken from stack")
        }
    }
}

public func popAllBook(){
    stack.popAll()
    
    print("All Book taken from stack")
}

var stack = Stack<Book>()

//Dummy data
stack.push(Book(stackId: "S15", bookName: "Algorithms II"))
stack.push(Book(stackId: "S17", bookName: "Mathematics I"))
stack.push(Book(stackId: "S19", bookName: "Accounting I"))

while true {

    clrScr()
    var choose: Int! = 0;

    print("Pile of Book Program")
    print("=====================")
    if let nextBook = stack.peek() {
        print("Next Book ID to take: \(nextBook.stackId)")
        print("=====================")
    }
    print("Menu")
    print("1. Stack Book")
    print("2. Show")
    print("3. Take Book")
    print("4. Take All Book")
    print("5. Exit")

    repeat {
        print("Input: ", terminator: "")
        if let str = readLine(){
         choose = Int(str)
        }
    } while choose < 1 || choose > 5;

    switch choose {
        case 1:
            pushBook()
        case 2:
            showStack()
        case 3:
            popBook()
        case 4:
            popAllBook()
        case 5:
            print("Thank you for using this program :)")
        default:
            print("")
    }

    _ = readLine()

    if choose == 5 {
        break
    }
}
