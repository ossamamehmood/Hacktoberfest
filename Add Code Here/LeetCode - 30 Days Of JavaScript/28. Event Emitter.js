class EventEmitter {
   constructor(){
       this.dict = {}
   }   
 
subscribe(eventName, callback) {
    this.dict[eventName] ||= [];
    this.dict[eventName].push(callback);  	
	return {
		unsubscribe: () => {
			this.dict[eventName] = this.dict[eventName].filter(c => c !== callback);
			}
		};
	}
    
	emit(eventName, args = []) {
		return (this.dict[eventName] ?? []).map(callback => callback(...args));
	}
}



/** Follow on Github : @utsxvrai  **/