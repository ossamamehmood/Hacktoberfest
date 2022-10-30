//package com.company;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class MergeSort {
    public static void main(String[] args) throws Exception{
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Reader.nextInt();
        int t = n;
        ArrayList<Long[]> arr = new ArrayList<>();
        while (t--> 0)
        {
            long x = Reader.nextLong();
            long y = Reader.nextLong();
//            System.out.println(x + " " + y);
            arr.add(new Long[]{x, y});
        }
        arr.sort((n1, n2) -> (int) (Objects.equals(n1[0], n2[0]) ? n1[1] - n2[1] : n1[0] - n2[0]));
        double min = Recursion_Fairy(arr,0,n-1);
        System.out.println(min);
//        output.close();
    }
    public static double Recursion_Fairy(ArrayList<Long[]> arr, int left, int right){
        if(right<=left)
        {
            return Double.MAX_VALUE;
        }
        else
        {
            int mid = (left+right)/2;

            long x_mid = arr.get(mid)[0];
            double opt_left = Recursion_Fairy(arr,left,mid);
            double opt_right = Recursion_Fairy(arr,mid+1,right);

//        System.out.println(opt_left+" "+opt_right);


            double curr_min = Math.min(opt_left,opt_right);

            ArrayList<Long[]> possible_pts = new ArrayList<>();
            for(int i = right;i>=left;i--){
                if(Math.abs(arr.get(i)[0]-x_mid)<curr_min/2)
                    possible_pts.add(arr.get(i));
            }
            possible_pts.sort((n1, n2) -> (int) (Objects.equals(n1[1], n2[1]) ? n1[0] - n2[0] : n1[1] - n2[1]));
            int size = possible_pts.size();
            for(int i = 0;i<size;i++){
                int limit = Math.min(size,i+16);
                for(int j = i+1;j<limit;j++){
                    for(int k = j+1;k<limit;k++){
                        double ans = 0;
                        ans += Math.sqrt(Math.pow(Math.abs(arr.get(i)[0]-arr.get(j)[0]),2) + Math.pow(Math.abs(arr.get(i)[1]-arr.get(j)[1]),2));
                        ans += Math.sqrt(Math.pow(Math.abs(arr.get(i)[0]-arr.get(k)[0]),2) + Math.pow(Math.abs(arr.get(i)[1]-arr.get(k)[1]),2));
                        ans += Math.sqrt(Math.pow(Math.abs(arr.get(k)[0]-arr.get(j)[0]),2) + Math.pow(Math.abs(arr.get(k)[1]-arr.get(j)[1]),2));
                        if (curr_min >= ans)
                        {
                            curr_min = ans;
                        }
//                    System.out.println(curr_min);
                    }
                }
            }
            return curr_min;
        }

    }

    public static int findPairs(ArrayList<Integer> array, int checkSum)
    {
        int i = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        int count = 0;
        for (int j=0;j<array.size();j++)
        {
            if (map.containsKey(checkSum-array.get(j)))
            {
                count++;
                map.clear();
            }
            else
            {
                map.put(array.get(j),1);
            }
        }
        return count;
    }
}
class Reader
{
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }
    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
    static long nextLong() throws IOException{
        return Long.parseLong(next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}