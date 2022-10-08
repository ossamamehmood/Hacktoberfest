//John is at a toy store help him pick maximum number of toys. 
//He can only select in a continuous manner and he can select only two types of toys.

import java.util.*;

public class PickToys {

	public static void main(String []args) {
		Scanner sc=new Scanner(System.in);
		 String str=sc.nextLine();
		 int val=findMax(str);
		 System.out.println(val);
	}

	private static int findMax(String str) {
	    HashMap<Character,Integer>hm=new HashMap<>();
	    int i=-1,j=-1,max=0;
	    
	    while(true) {
	    	boolean f1=false;
	    	boolean f2=false;
	    	
	    	while(i<str.length()-1) {
	    		f1=true;
	    		i++;
	    		char ch=str.charAt(i);
	    		hm.put(ch,hm.getOrDefault(ch,0)+1);
	    		if(hm.size()>2) {
	    			break;
	    		}
	    		else if(hm.size()<=2){
	    			int len=i-j;
	    			if(len > max) {
	    				max=len;
	    			}
	    		}
	    	}
	    	
	    	while(j<i) {
	    		f2=true;
	    		j++;
	    		char ch=str.charAt(j);
	    		int freq=hm.get(ch);
	    		if(freq==1) {
	    			hm.remove(ch);
	    		}
	    		else {
	    			hm.put(ch,freq-1);
	    		}
	    		if(hm.size()==2) {
	    			int len=i-j;
	    			if(len > max) {
	    				max=len;
	    			}
	    			break;
	    		}
	    		
	    	}
	    	if(f1==false && f2==false) {
	    		break;
	    	}
	    }
		return max;
	}
}
