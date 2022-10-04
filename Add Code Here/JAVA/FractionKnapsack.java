import java.util.Arrays;
import java.util.Comparator;

public class FractionalKnapSack {
    public double getMaxValue(int[]w,int[]v,int capacity){
        Item[] item = new Item[w.length];
        for(int i=0;i<w.length;i++){
            item[i] = new Item(w[i],v[i],i);
        }
        Arrays.sort(item, new Comparator<Item>() {
            @Override
            public int compare(Item o1, Item o2) {
                return o2.cost.compareTo(o1.cost);
            }
        });
        double total = 0d;

        for(Item i : item){
            int curWT = (int) i.wt;
            int curVal = (int) i.val;

            if(capacity-curWT>0){
                capacity-=curWT;
                total = total+curVal;
            }else{
                double frac = (double) capacity/curWT;
                total = total+curVal*frac;
                capacity = (int) (capacity-curWT*frac);
                break;
            }
        }
        return total;
    }
}
class Item{
    Double cost;
    double wt,val,idx;

    public Item(double wt, double val, double idx) {
        this.wt = wt;
        this.val = val;
        this.idx = idx;
        cost = val/wt;
    }

    public static void main(String[] args) {
        int[] wt = { 10, 40, 20, 30 };
        int[] val = { 80, 20, 120, 60 };
        int capacity = 50;
        KnapSack k = new KnapSack();
        double maxValue = k.getMaxValue(wt, val, capacity);
        System.out.println(maxValue);
    }
}
