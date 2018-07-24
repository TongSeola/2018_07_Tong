// HW 184, Quick Sort: 
// Name :
// Student ID :

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		QuickSort qs = new QuickSort();	// QuickSort

		while(true) {
			try {
				System.err.print("QuickSort > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals ("i") ) {
					int [] intarr = new int [1024];
					int i = 0;
					int item;
					while(true) {
						item = in.nextInt();
						if(item == -1)
							break;
						intarr[i++] = item;
					}
					qs.Init(intarr, i);
					System.out.println("New Data Set");
					qs.Show(0, i - 1);
				} else if(cmd.equals ("qs") ) {
					System.out.println("quick sort started");
					qs.Sort();
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
	}
}




