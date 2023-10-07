package factoryMPattern;

public class FactoryClass implements IObstacleFactory{

    @Override
    public IObstacleObject getObstacle(String name, float size, float x, float y) {
        IObstacleObject obst = new ObstacleClass(name, size, x, y);
        System.out.println("Created new object!\n");
        return obst;
    }
    
}
