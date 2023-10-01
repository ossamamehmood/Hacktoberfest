package com.mycompany.dsa;

public class reverseDoublyLinkedList {
    static class Node{
        int data;
        Node next, prev;
    }

    static Node getNode(int data) {
        Node new_node = new Node();
        new_node.data = data;
        new_node.next = new_node.prev = null;
        return new_node;
    }

    static Node push(Node head_ref, Node new_node) {
        new_node.prev = null;

        new_node.next = (head_ref);

        if((head_ref) != null)
            (head_ref).prev = new_node;

        (head_ref) = new_node;
        return head_ref;
    }

    static Node Reverse(Node node) {
        if(node == null)
            return null;

        Node temp = node.next;
        node.next = node.prev;
        node.prev = temp;

        if(node.prev == null)
            return node;

        return Reverse(node.prev);
    }

    static void printList(Node head) {
        while(head != null) {
            System.out.println(head.data + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {
        Node head = null;

        head = push(head, getNode(2));
        head = push(head, getNode(4));
        head = push(head, getNode(8));
        head = push(head, getNode(10));
        System.out.println("Original list: ");
        printList(head);

        head = Reverse(head);
        System.out.println("\nReversed list: ");
        printList(head);

    }
}
