package stackandqueue;

public class dynamicstackclient {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		dynamicstack st = new dynamicstack(5);
		st.push(5);
		st.push(4);
		st.push(3);
		st.push(2);
		st.push(1);
		st.push(-1);
		st.push(-2);
		st.push(-3);
		st.display();
	}

}
