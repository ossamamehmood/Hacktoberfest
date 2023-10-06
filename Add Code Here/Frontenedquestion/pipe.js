const val={salary:2000}
const salary=(val)=>val.salary;
const bonus=(salary)=>salary+1000;
const deduct=(net)=>net-(net*0.3);
const pipe=(...fun)=>{
  return (val)=>{ 
    return fun.reduce((current,ass)=>{
        return ass(current)
    },val)
             }
}
const result=pipe(
    salary,
    bonus,
    deduct
)(val);
console.log(result)