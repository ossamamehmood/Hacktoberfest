package factoryMPattern;
import java.util.*;

public interface IObstacleFactory {

    public IObstacleObject getObstacle(String name, float size, float x, float y);
}