import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		MinHeap<Integer> heap = new MinHeap<Integer>(Integer.class, 128);	
		while(true) {
			System.err.println("MeanHeap > ");
			String command;
			command = in.next();
			if(command.equals("quit"))
				break;	// stop the program
			if(command.equals("ins")) {	// insert command
				int item = in.nextInt();
				System.out.println("CMD : ins " + item);
	
				heap.Insert(item);
			} else if(command.equals("post")) {
				int idx = in.nextInt();
				System.out.print("CMD : post " + idx + " : ");
				heap.PostOrder(idx);
				System.out.println();
			}

			// show the current heap
			System.out.println(heap);
			System.out.println();
		}
	}
}

