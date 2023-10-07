const str="ultimate javascript frontend guide";
const words=["front","end","script"];
const highlight=(str,words)=>{
 const newWord=new Set(words);
const newstr=str.split(" ");

const result=newstr.map((word)=>{
  let output=""
  if(newWord.has(word)){
    console.log(newWord.has(word))
    output=`<strong>${word}</strong>`
  }else{
    for(let i=0;i<word.length;i++){
      let prefex=word.slice(0,i+1);
      let suffix=word.slice(i+1);
      if(newWord.has(prefex) && newWord.has(suffix)){
        
        output=`<strong>${prefex +suffix}</strong>`
      }
      else{if(!newWord.has(prefex) && newWord.has(suffix)){
      output=`${prefex}<strong>${suffix}</strong>`
        }
        else{
          if(newWord.has(prefex) && !newWord.has(suffix)){
            output=`${suffix}<strong>${prefex}</strong>`
          }
        }
      }
    }
  }
  console.log(output!==""?output:word)
  return output!==""?output:word
})

return result.join("")
}
console.log(highlight(str,words))