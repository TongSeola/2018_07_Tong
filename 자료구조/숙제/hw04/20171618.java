// HW 184, QuickSort
// Name : 동설아	
// Student ID : 20171618

import java.util.*;


class QuickSort {
    int[] arr; // array
	int arrSize;  // number of elements in arr

	QuickSort() { 
		arr = new int[1024];  
		arrSize = 0;
	}


	void Show(int s, int e) { 
		// Show all the element in the arr
		if(s > e)
			return ;
		String str = new String();
		str = "arr : ";

		// print all the nodes in the arr
		for(int i = 0; i < arrSize; i++) {
			if(i == s)
				str += "[";
			else
				str += " ";
			str += arr[i];
			if(i == e)
				str += "]";
			else
				str += " ";
		}
		System.out.println( str);
	}

	void  Init(int[] es, int n) {	
		// fill the arr array by the input
		arrSize = n;
		for(int i = 0; i < n; i++)
			arr[i] = es[i];
	}


	void  Sort() {
		// sort arr[0:arrSize-1] into nonincreasing order
		// This is an invoking method to the Partition() and QSort() 
		QSort(0, arrSize - 1);	// quick sort from 0 to n-1
	}



	void  QSort(int s, int e) {	
		// sort arr[s:e] into nonincreasing order
		System.out.println("Sort in [" + s + "," + e + "]");
		Show(s, e);
		
		if(s >= e)
			return;
		
		if(s < e)
		{
			//System.out.println("Sort in [" + s + "," + e + "]");
			//Show(s, e);
			int i = s;
			int j = e+1;
			int middle = (s+e)/2;
			int pivot = s;
			
			if(arr[s] < arr[e] && arr[e] < arr[middle] || 
			   arr[middle] < arr[e] && arr[e] < arr[s]) 
			{
//				pivot = e;
				int firstData = arr[s];
				arr[s] = arr[e]; 
				arr[e] = firstData;
			}
			else if(arr[e] <= arr[s] && arr[s] <= arr[middle] ||
					 arr[middle] <= arr[s] && arr[s] <= arr[e])
			{
//				pivot = s;
			}
			else if(arr[s] < arr[middle] && arr[middle] <= arr[e] ||
					 arr[e] <= arr[middle] && arr[middle] < arr[s]) 
			{
//				pivot = middle;
				int firstData = arr[s];
				arr[s] = arr[middle];
				arr[middle] = firstData;
			}

			do {

				do i++; while(arr[i] > arr[pivot]);
				do j--; while(arr[j] < arr[pivot]);
				if(i < j) 
				{
					int swapeI = arr[i];
					int swapeJ = arr[j];
					
					arr[i] = swapeJ;
					arr[j] = swapeI;

				}
			}while(i < j);
			
			int swapeP = arr[pivot];
			int swapeS = arr[j];

			arr[pivot] = swapeS;
			arr[j] = swapeP;
			
			QSort(s, j-1);
			QSort(j+1, e);
		}
		
	} 

}



