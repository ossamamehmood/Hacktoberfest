package hashMapAndHeap;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class CountdistinctCharatersInEveryWindowSizek {

	public static ArrayList<Integer>list(String str,int k){
		ArrayList<Integer>al=new ArrayList<>();
		char[]arr=str.toCharArray();
		HashMap<Character,Integer>hm=new HashMap<>();
		for(int i=0;i<k-1;i++) {
			hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
		}
		int j=-1;
		for(int i=k-1;i<arr.length;i++) {
			hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
			al.add(hm.size());
			j++;
			int freq=hm.get(arr[j]);
			if(freq==1) {
				hm.remove(arr[j]);
			}
			else {
				hm.put(arr[j],freq-1);
			}
		}
		return al;
	
		}


			public static void main(String[] args) {
				Scanner scn = new Scanner(System.in);
				 String str=scn.nextLine();
				int k = scn.nextInt();
				ArrayList<Integer> ans =list(str,k);
				for(int a : ans){
					System.out.print(a + " ");
				}

			}

		}
