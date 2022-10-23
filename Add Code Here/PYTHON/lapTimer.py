import time

start = time.time()
last = start
lap = 1

print("Press ENTER to count laps.\nPress CTRL+C to stop")
  
try:
     while True:
              
          # Input for the ENTER key press
          input()
  
          # The current lap-time
          laptime=round((time.time() - last), 2)
  
          # Total time elapsed 
          # since the timer started
          totaltime=round((time.time() - start), 2)
  
          # Printing the lap number,
          # lap-time and total time
          print("Lap No. "+str(lap)) 
          print("Total Time: "+str(totaltime))
          print("Lap Time: "+str(laptime))
            
          print("*"*20)
  
          # Updating the previous total time
          # and lap number
          lasttime=time.time()
          lap+=1

except KeyboardInterrupt:
    print("Done")
    
