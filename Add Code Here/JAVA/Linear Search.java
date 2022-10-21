public class Main {

	public static void main(String[] args) {
		int[]arr= {11,20,25,30,35,45,90};
		int target=25;
		System.out.println(linearSearch(arr,target));
   
	}
	static int linearSearch(int[]arr,int target) {
		if(arr.length==0) {
			return -1;
		}
		for(int index=0;index<arr.length;index++) {
			int element=arr[index];
			if(element==target) {
				return index;
			}
			
		}
		return -1;

	}

}