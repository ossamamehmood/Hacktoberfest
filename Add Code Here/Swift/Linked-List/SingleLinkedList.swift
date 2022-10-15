//
//  SingleLinkedList.swift
//  SingleLinkedList
//
//  Created by Stevhen on 12/10/22.
//

import Foundation

public class Book {
    var id: String
    var title: String
    var author: String
    
    init(id: String, title: String, author: String){
        self.id = id
        self.title = title
        self.author = author
    }
}

//To create Node property
public class Node<T> {
    var value: T
    
    init(value: T){
        self.value = value
    }
    
    var next: Node<T>?
}

//Data Structure logics
public class SingleLinkedList<T> {
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
        
        if let tailNode = tail {
            tailNode.next = curr
        } else {
            head = curr
        }
        
        tail = curr
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
        var i: Int = 0
        
        while curr != nil {
            i += 1
            curr = curr!.next
        }
        
        return i
    }
    
    public func pop(curr: Node<T>) -> T {
        
        var newCurr = head
        
        if(head === tail) {
            popAll()
        }
        else if first === curr {
            head = head?.next
            curr.next = nil
        }
        else if(last === curr) {
            while newCurr?.next !== tail {
                newCurr = newCurr?.next
            }
            
            newCurr?.next = nil
            tail = newCurr
        }
        else{
            while newCurr?.next !== curr {
                newCurr = newCurr?.next
            }
            
            newCurr?.next = newCurr?.next?.next
            curr.next = nil
        }
        
        return curr.value
    }
    
    public func popAll() {
        head = nil
        tail = nil
    }
}

//Main Program
public func addBook(){
    print("Enter Book id: ", terminator: "")
    let id: String? = readLine()
    print("Enter Book title: ", terminator: "")
    let title: String? = readLine()
    print("Enter Book author: ", terminator: "")
    let author: String? = readLine()
    
    list.push(value: Book(id: id!, title: title!, author: author!))
}

public func clrScr(){
    for _ in 1...25 {
        print("")
    }
}

public func separatorBar(){
    for _ in 1...53 {
        print("=", terminator: "")
    }
    print("")
}

public func showBook(){
    
    if list.getSize() <= 0 {
        print("No data yet")
    }
    else{
        separatorBar()
        print(String(format: "| %-4s | %-12s | %-12s | %-12s |", ("No" as NSString).utf8String!,("ID" as NSString).utf8String!, ("Title" as NSString).utf8String!, ("Author" as NSString).utf8String!))
        separatorBar()
        for i in 0..<list.getSize() {
            let curr = list.getNode(index: i)
            print(String(format: "| %-4d | %-12s | %-12s | %-12s |", i+1, (curr!.value.id as NSString).utf8String!, (curr!.value.title as NSString).utf8String!, (curr!.value.author as NSString).utf8String!))
        }
        separatorBar()
    }
    
}

public func removeBook(){
    if list.isEmpty {
       print("No data yet")
   }
   else{
        var pos: Int! = -1

        print("Remove Book")
        showBook()

        print("")
        print("Enter number to remove: ", terminator: "")
        repeat {
            if let str = readLine(){
                pos = Int(str)!
            }
        } while pos < 1 || pos > list.getSize();
        pos -= 1

        let book = list.pop(curr: list.getNode(index: pos)!)

        print("Book with ID: \(book.id) removed")
    }
}

public func removeAllBook(){
    list.popAll()
    print("All Book removed")
}

let list = SingleLinkedList<Book>()

//Dummy data
list.push(value: Book(id: "PS4212", title: "Psychology I", author: "Patrick B."))
list.push(value: Book(id: "AC5233", title: "Accounting I", author: "Benjamin C."))
list.push(value: Book(id: "CS1242", title: "Algorithm II", author: "Colitta K."))

while true {
    
    clrScr()
    var choose: Int! = 0;
    
    print("Books List Program")
    print("=====================")
    print("Menu")
    print("1. Add")
    print("2. Show")
    print("3. Remove")
    print("4. Remove All")
    print("5. Exit")
    
    repeat {
        print("Input: ", terminator: "")
        if let str = readLine(){
         choose = Int(str)
        }
    } while choose < 1 || choose > 5;
    
    switch choose {
        case 1:
            addBook()
        case 2:
            showBook()
        case 3:
            removeBook()
        case 4:
            removeAllBook()
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
