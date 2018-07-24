// Lab 012	: Natural Merge
// Name : Tong Seol a
// Student ID : 20171618

import java.util.*;


class NaturalMerge {
	int noe;  // the number of elements
	private int[] inputArray; // input array 
	int[] outputArray; // output array 


	NaturalMerge() { 
		// Graph constructor. 
		noe = 0;
	}

	public String toString() {
		String str = new String();
		str = "Input : ";
		for(int i = 0; i < noe; i++) {
			str += inputArray[i] + " ";
		}
		str += "\nOutput : ";
		for(int i = 0; i < noe; i++) {
			str += outputArray[i] + " ";
		}
		return str;
	}

	void Init(int [] arr, int n) { 
		noe = n;
		inputArray = new int[noe];
		System.arraycopy(arr, 0, inputArray, 0, n);

		outputArray = new int[noe];
	}

	void Merge() { 
		int n = noe;
		System.out.print("n = "+n);
		int diffIndex = 0;
		int past = -1;
		int now = -1;
		for(int i=0; i<noe; )
		{
			past = inputArray[i];
			++i;
			now = inputArray[i];
			if(past > now)
			{
				diffIndex = i;
				break;
			}
		}
		System.out.println(", m = "+diffIndex);
		int index1 = 0;
		int index2 = diffIndex;
		int outputIndex = 0;
		while(index1 != diffIndex && index2 != noe)
		{
			if(inputArray[index1] < inputArray[index2])
			{
				System.out.print("L ");
				outputArray[outputIndex] = inputArray[index1];
				index1++;
			}
			else if(inputArray[index1] > inputArray[index2])
			{
				System.out.print("R ");
				outputArray[outputIndex] = inputArray[index2];
				index2++;
			}
			else
			{
				System.out.print("L ");
				outputArray[outputIndex] = inputArray[index1];
				index1++;
				//index2++;
			}
			outputIndex++;
		}
		
		while(index1 != diffIndex)
		{
			outputArray[outputIndex] = inputArray[index1];
			index1++;
			outputIndex++;
		}
		while(index2 != noe)
		{
			outputArray[outputIndex] = inputArray[index2];
			index2++;
			outputIndex++;
		}

		System.out.println();
	}
}













