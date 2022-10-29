  function nextHole(array,until) {
      this.array=array;
      this.lastIndex=0;
      this.lastItem=0;
      this.until=until;
      this.loopFinished=false;
      this.done=false;
      this.reset = function(){
          this.lastIndex=0;
          this.lastItem=0;
          this.done=false;
          this.loopFinished=false;
      }

      this.getNext = function(){

        if (this.done){
            return null;
        }

        if (!this.loopFinished){                
            for(loop=this.lastIndex;loop<this.array.length ;loop++){
                if (this.array[loop]!=this.lastItem+1){

                    this.lastItem++;
                    this.lastIndex=loop;
                    if (this.lastItem>until)
                        break;


                    return this.lastItem;
                }else{
                    this.lastItem=this.array[loop];
                }

            }

        }
        this.loopFinished=true;
        if (this.lastItem < this.until){
            return (++this.lastItem);
        }
        this.done=true;
        return null;
      }

    }


    var h = new nextHole([1,2,5,6,7,15],10);
    while(true){
        var n = h.getNext();
        if (n == null){
            break;
        }else{
            console.log(" yield: "+n);
        }
    }


    h.reset();
    while(true){
        var n = h.getNext();
        if (n == null){
            break;
        }else{
            console.log(" yield: "+n);
        }
    }
