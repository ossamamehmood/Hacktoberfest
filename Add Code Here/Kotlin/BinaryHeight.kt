package br.com.alura.devhub

import jdk.nashorn.internal.ir.BinaryNode
import java.lang.Integer.max

class BinaryHeight {

    fun height(node: BinaryNode<T>? = this): Int {
        return node?.let { 1 + max(height(node.leftChild),
                height(node.rightChild)) } ?: -1
    }
}