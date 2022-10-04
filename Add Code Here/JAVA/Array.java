public class Arrays
{
    protected int size;
    protected int max;
    protected int min;
    protected int[] array;
    
    public Arrays(int size, int max, int min)
    {
        this.size = size;
        this.max = max;
        this.min = min;
        array = new int[size];
        generateArray();
    }
    protected void generateArray()
    {
        for(int i = 0; i < size; i++)
        {
            array[i] = getRandom();
        }
    }
    //Returns a random number between max and min inclusive
    protected int getRandom()
    {
        return (int)((Math.random() * (max-min+1))+min);
    }
    protected void printArray()
    {
        for(int num : array)
        {
            System.out.println(num);
        }
    }
    public int[] getArray()
    {
        return array;
    }
    public int getSize()
    {
        return size;
    }
}
