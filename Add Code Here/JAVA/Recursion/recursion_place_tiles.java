public class recursion_place_tiles {
    public static int countNoOfWaysToPlaceTiles(int fx,int fy,int tx,int ty){
        if(fx==fy){
            return 2;
        }
        else if(fx<ty){
            return 1;
        }
        //horizontal
        int horizontal_count = countNoOfWaysToPlaceTiles(fx-1, fy,tx ,ty);

        //vertical
        int vertical_count = countNoOfWaysToPlaceTiles(fx-ty, fy , tx,ty);

        return  horizontal_count + vertical_count;
    }
    public static void main(String[] args) {
        int fx=4;
        int fy=2;
        int tx = 2;
        int ty = 2;
        int total_ways = countNoOfWaysToPlaceTiles(fx ,fy, tx, ty);
        System.out.println("the total no.ways are "+total_ways);
    }
}
