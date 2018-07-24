import java.util.*;

/**
 * Lab 002 
 * @version 1.0
 * @author Sanghwan Lee
 * @id 20181234
 */

class LabTest{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//System.out.println("Enter n m : ");
		int n = input.nextInt();
		int m = input.nextInt();
		
		while (n != 0 ) 
		{
			int output = Combi(n,m);
			System.out.println("Combination("+n+", "+m+") : "+output);
			//System.out.println("Enter n m : ");
			n = input.nextInt();
			m = input.nextInt();
			
			
		} 
//		else System.out.println("enter positive number");
	}
	static int Combi(int n, int m) {
		if (n == m) return 1;
		if (m == 0) return 1;
		else return Combi(n-1, m)+Combi(n-1, m-1);
	}
}
