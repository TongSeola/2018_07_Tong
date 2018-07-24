import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		DblList<Integer> dbll = new DblList<Integer>();	
		while(true) {
			System.err.println("Dbl > ");
			String command;
			command = in.next();
			if(command.equals("quit"))
				break;	// stop the program
			if(command.equals("ins")) {	// insert command
				int item = in.nextInt();
				System.out.println("CMD : ins " + item);
	
				dbll.InsertFront(item);
			} else if(command.equals("del")) {
				int item = in.nextInt();
				System.out.println("CMD : del " + item);
				if(dbll.Delete(item) == false)
					System.out.println("Cannot delete item " + item);
			}


			// show the current list
			System.out.println(dbll);

			// show the number of elements in the list
			System.out.println("List has " + dbll.Size() + " elements\n");
		}
	}
}

