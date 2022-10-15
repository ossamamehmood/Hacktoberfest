fun palindrome(n:Int):Int{

    if(n==0)
    return 0
    if(n==1||n==2)
    return 1
    else
    return palindrome(n-1)+palindrome(n-2)
}

fun main(){
    val range=10
    repeat(range){
        index->println(palindrome(index))
    }
}