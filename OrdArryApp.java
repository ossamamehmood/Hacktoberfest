public class OrdArryApp {

    /
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        OrdArray x = new OrdArray(7);
        x.insert(7);
        x.insert(8);
        x.insert(10);
        x.insert(3);
        x.insert(15);
        x.display();
        x.delete(8);
        x.display();
        x.insert(7);
        x.insert(5);
        x.insert(3);
        x.insert(2);
        x.display();
        x.find(10);
        x.display();

    }
}

class OrdArray {

    private long[] a; // ref to array a
    private int nElements; //number of data items

    public OrdArray(int max) {
        this.a = new long[max];
        this.nElements = 0;
    }

    public int size() { // return max size of the array
        return this.a.length;
    }

    public int find(long searchKey) {
        for (int i = 0; i < this.nElements; i++) {
            if (a[i] == searchKey) {
                return i;
            }
        }
        return -1; //not available
    }

    public void insert(long value) { // put element into arrray
        if (this.nElements == size()) {
            System.out.println("array is full. insertion terminated");
            return;

        }
        for (int i = 0; i < this.nElements; i++) {
            if (this.a[i] > value) {
                for (int j = this.nElements - 1; j >= i; j--) {
                    this.a[j + 1] = this.a[j];
                }
                this.a[i] = value;
                this.nElements++;
                return;
            }
        }

        a[this.nElements] = value;
        this.nElements++;

    }

    public boolean delete(long value) {
        int index = find(value);
        if (index == -1) {
            System.out.println("value not found. deletion terminated");
            return false;
        } else {
            for (int i = index; i < this.nElements - 1; i++) {
                this.a[i] = this.a[i + 1];
            }
            this.nElements--;
            return true;
        }
    }

    void display() { // display array contents
        System.out.println("---value of the array---");
        for (int i = 0; i < this.nElements; i++) {
            System.out.print(this.a[i] + " ");
        }
    }
}
