const PwEl = document.getElementById("pw");
const copyEl = document.getElementById("copy");
const lenEl = document.getElementById("len");
const upperEl = document.getElementById("upper");
const lowerEl = document.getElementById("lower");
const symbolEl = document.getElementById("symbol");
const generateEl = document.getElementById("generate");
const numberEl = document.getElementById("number");
const upperLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const lowerLetters = "abcdefghijklmnopqrstuvwxyz";
const numbers = "0123456789";
const symbol = "~!@#$^&*()_+=";
function getLowercase(){
    return lowerLetters[Math.floor(Math.random() * lowerLetters.length)];
}
function getUppercase(){
    return upperLetters[Math.floor(Math.random() * upperLetters.length)];
}
function getSymbol(){
    return symbol[Math.floor(Math.random() * symbol.length)];
}
function generatePassowrd(){
    const len = lenEl.value;
    let password = "";
    for(let i = 0; i < len; i++){
        const x = generateX();
        password += x;
    }
    PwEl.innerText = password;
    function generateX(){
        const xs = [];
        if(upperEl.checked){
            xs.push(getUppercase());
        }
        if(upperEl.checked){
            xs.push(getLowercase());
        }
        if(upperEl.checked){
            xs.push(getNumber());
        }
        if(upperEl.checked){
            xs.push(getSymbol());
        }
        if (xs.length === 0) return "";
        return xs[Math.floor(Math.random() * xs.length)];
}
        generateEl.addEventListener("click", generatePassowrd);
        copyEl.addEventListener("click",() => {
            const textarea = document.createElement("textarea");
            const password = PwEl.innerText;
            if(!password){
                return;
            }
            textarea.value = password;
            document.body.appendChild(textarea);
            textarea.select();
            document.execCommand("copy");
            textarea.remove();
            alert("password copied to clipboard");
        });
}
console.log("hello");

