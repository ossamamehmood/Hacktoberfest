package factoryMPattern;

public class ObstacleClass implements IObstacleObject{

    private String name;
    private float size;
    private float x;
    private float y;

    public ObstacleClass(String name, float size, float x, float y) {
        this.name=name;
        this.size=size;
        this.x=x;
        this.y=y;
    }
    @Override
    public void initObject() {
        System.out.println("The name of the object is " + name+", size is " + size + 
        ", x is " + x + ", y is " + y);
    }
    
}
