class MyQueue {
    pushStack : number[]
    popStack : number[]
    length: number
    constructor() {
        this.pushStack = []
        this.popStack= []
        this.length = 0
    }

    push(x: number): void {
        this.pushStack.push(x)
        this.length++
    }

    pop(): number {
        this.reverseShift();
        this.length--
        return this.popStack.pop()
    }

    peek(): number {
        this.reverseShift();
        return this.popStack[this.popStack.length - 1]
    }

    empty(): boolean {
        if(this.length == 0){
            return true
        }
        return false
    }
    reverseShift(){
        if(this.popStack.length === 0){
            for(let i = this.pushStack.length - 1 ; i >= 0; i--){
                this.popStack.push(this.pushStack[i])
            }
            this.pushStack =[]
        }
    }
}
