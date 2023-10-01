package com.mycompany.dsa;

class deleteHeadNode {
    static class Node {
        int data;
        Node next;
    }

    static void deleteList(Node head) {
        if(head == null) return;
        deleteList(head.next);
        System.gc();
    }

    static void push(Node head_ref, int new_data) {
        Node new_node = new Node();
        new_node.data = new_data;
        new_node.next = head_ref;
        head_ref = new_node;
    }

    public static void main(String[] args) {
        Node head = new Node();
        push(head, 1);
        push(head, 4);
        push(head, 1);
        push(head, 12);
        push(head, 1);
        System.out.println("\nDeleting linked list");
        deleteList(head);
        System.out.println("\nLinked list deleted");
    }
}
