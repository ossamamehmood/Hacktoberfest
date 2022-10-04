package coba;

import java.util.ArrayList;

public class Suhu {

    public static void main(String[] args) {

        // nomor1
        double senin = 29.3;
        double selasa = 30.1;
        double rabu = 32;
        double kamis = 35.9;
        double jumat = 36.7;
        double sabtu = 33;
        double minggu = 29;
        double terkecil = 0;

        // nomor2
        ArrayList hari = new ArrayList();

        hari.add("senin");
        hari.add("selasa");
        hari.add("rabu");
        hari.add("kamis");
        hari.add("jumat");
        hari.add("sabtu");
        hari.add("minggu");

        double suhu[] = { 29.3, 30.1, 32, 35.9, 36.7, 33, 29 };
        double suhumax = suhu[0];
        double suhumin = suhu[0];
        for (int i = 0; i < suhu.length; i++) {
            if (suhu[i] > suhumax) {
                suhumax = suhu[i];
            }
            for (int j = 0; j < suhu.length; j++) {
                if (suhu[j] < suhumin) {
                    suhumin = suhu[j];
                }
            }
        }

        System.out.println(hari.get(0));
        System.out.println(hari.get(1));
        System.out.println(hari.get(2));
        System.out.println(hari.get(3));
        System.out.println(hari.get(4));
        System.out.println(hari.get(5));
        System.out.println(hari.get(6));

        System.out.println("");

        System.out.println("suhu tertinggi " + hari.get(4) + " " + suhumax);
        System.out.println("suhu terendah " + hari.get(6) + " " + suhumin);

    }

}
