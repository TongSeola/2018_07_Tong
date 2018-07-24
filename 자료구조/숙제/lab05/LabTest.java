import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		Chain<Integer> chain = new Chain<Integer>();

		while(true) {
			try {
				System.err.println("Chain > ");
	
				String cmd = in.next();
				if(cmd.equals("ins")) {
					int idx = in.nextInt();
					int item = in.nextInt();
					if(chain.Insert(idx, item) == false) {
						System.out.println("Cannot Insert into position " + idx);
					}
				} else if(cmd.equals("delf")) {
					Integer item = chain.DeleteFront();
					if(item != null) {
						System.out.println("	Output : " + item);
					} else {
						System.out.println("Chain is Empty!");
					}
				} else if(cmd.equals("quit"))
					break;
			} catch (Exception e) {
				System.out.println(e);
			}
			System.out.println(chain);
			System.out.println();
		}
	}
}



