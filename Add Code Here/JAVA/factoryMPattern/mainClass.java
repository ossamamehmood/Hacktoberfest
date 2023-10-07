package factoryMPattern;
import java.util.*;
import java.util.concurrent.TimeUnit;  

class mainClass {
    public static void main(String[] args) {
        mainClass clazz = new mainClass();
        clazz.mainWork();
        
    }
    
    private void mainWork() {
        FactoryClass factory=new FactoryClass();
        ObstacleClass object;
        ObstacleClass object2;
        object =(ObstacleClass) factory.getObstacle("Stone", 20, 5, 5);
        object.initObject();
        object2 =(ObstacleClass) factory.getObstacle("Coin", 10, 12, 12);
        object2.initObject();
    }
    
    
    }