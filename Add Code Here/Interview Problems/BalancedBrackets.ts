// Problem: Balanced Brackets

// Given a string containing just the characters '(', ')', '{', '}', '[', and ']', determine if the input string is valid. An input string is valid if:

// Open brackets are closed by the same type of brackets.
// Open brackets are closed in the correct order.
// A string is considered balanced if it satisfies the above conditions. Your goal is to determine whether a given string is balanced or not.

const peek = (stack: string[]) => {
    return stack[stack.length -1];
}
const isBalanced = (str: string) => {
    let stack: string[] = [];
    let opening: string = "({[";
    let closing: string = ")}]";
    // iterate through every letter of the string
    for(let i: number = 0; i < str.length; i++){
        let letter: string = str.charAt(i);
        if(opening.includes(letter)){
            // if the first opening characters of the different types of characters have letter
            stack.push(letter);
            // we push it into the stack so that it can find its match
        } else if(closing.includes(letter)){
            // each closing character must have a matching opening character
            if(stack.length === 0){
                return false;
            }
            else {
                let top = peek(stack);
                // top = the top of the stack
                // read what is at the top of the stack
                if(top === "(" && letter === ")" || 
                   top === "{" && letter === "}" || 
                   top === "[" && letter === "]"){
                    // if the top of the stack matches its closing letter
                    stack.pop();
                    // pop it off the stack since we have now found its match
                } else {
                    // if it does not have a match then clearly it isn't balanced
                    return false;
                }
            }
        }
    }

    return stack.length === 0;
    // this confirms whether or not the stack is empty.
    // if the stack is empty, it is balanced.
}

