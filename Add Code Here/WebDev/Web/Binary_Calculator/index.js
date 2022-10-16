var val1='',val2='',sign='';
function add10(val){
    if(sign)
    val2+=val;
    else{
        val1+=val;
    }
    ans();
}
  function clearit(){
      val1="";val2="";sign='';
      ans();
  }
  function equal(){
      val1=parseInt(val1,2);
      val2=parseInt(val2,2);
      if(sign=='+'){
         val1+=val2;
         }
      else if(sign=='-'){
         val1-=val2;
      }
      else if(sign=='*'){
         val1*=val2;
      }
      else if(sign=='/'){
          if(val2)
             val1/=val2;
      }
      val1=parseInt(val1).toString(2);
      val2=sign='';
      ans();
  }
  function opera(value){
      sign=value;
      ans();
  }
  function ans(){
      res.innerHTML= val1 +sign +val2;
  }