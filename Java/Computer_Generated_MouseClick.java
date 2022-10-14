// Neeraj Rathore 
// Computer_Generated Mouse Click using java.awt.robot class

import java.awt.*;
import java.awt.event.InputEvent;

public class Computer_Generated_MouseClick {

    public static void onClick(int x, int y) throws AWTException{
        Robot bot = new Robot();
        bot.mouseMove(x,y);
        bot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
        bot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
    }

    public static void main(String[] args) throws AWTException, InterruptedException{
        while(true){
            onClick(0,1000);          // this sends start button location to onClick method on windows
            Thread.sleep(480000,0);   // automated click frequency is 480 seconds
        }
    }
}