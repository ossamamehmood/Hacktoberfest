
let timeObj = new Date();


let hrs;
let min;
let session ;
let seeionName;







document.querySelector('.clickTimer').addEventListener('click', function () {


        click = true
        //getting live time
    if(click == true){
        setInterval(() => {
            var sessoin = "AM";
            let time = new Date();
    
            
        
            let hrs = time.getHours();

            let min = time.getMinutes();
            let sec = time.getSeconds();
            let date = time.toLocaleDateString();
        
            if (hrs >= 12) {
                hrs = hrs - 12;
                sessoin = "PM";
            }
        
            hrs = (hrs < 10) ? "0" + hrs : hrs;
            hrs = (hrs == 0) ? hrs = 12: hrs;
            min = (min < 10) ? "0" + min : min;
            sec = (sec < 10) ? "0" + sec : sec;
    
            time = `${hrs} : ${min} : ${sec} ${sessoin}`;
        
        
  

            console.log("ButtonClicked");
            document.querySelector('.timer').innerHTML = time;

        }, 1000);
    }
})
