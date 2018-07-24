import java.util.*;
import java.lang.reflect.*;

/**
 * Generic version of the MinHeap class.
 * @param <T> the type of the value being added
 */

class MinHeap <T extends Comparable> {
	private T[] heapArray;
	private int heapSize;	// number of heap elements

	/**
	 * Create an empty MinHeap of size capacity
	 */
	MinHeap(Class<T> elemType, int capacity) {
		heapArray = (T []) Array.newInstance(elemType, capacity);
		heapSize = 0;
	}


	/**
	 * Insert item into the MinHeap
	 */
	void Insert (T item) { 
		// T타입은 부등호로 크기를 알 수 없으므로 compareTo() > < == 0를 사용해야 한다
		heapArray[++heapSize] = item;
		int comp = heapSize;
		double h = Math.log(heapSize) / Math.log(2);
		while(comp/2 >0) {
			if(heapArray[comp].compareTo(heapArray[comp/2]) < 0) {
				T rootData = heapArray[comp/2];
				heapArray[comp/2] = heapArray[comp];
				heapArray[comp] = rootData;
				
				comp = comp/2;
				
			}
			else {break;}
		}
	}

	void PostOrder (final int idx) { 
		// left - right - me 즉 2i - 2i+1 - i
		if (idx > heapSize) { return;}
		else {
			PostOrder(2*idx);
			PostOrder(2*idx+1);
			System.out.print(heapArray[idx]+ " ");
		}
	}


	public String toString() {
		String a = new String();
        a = "Min Heap : - ";
        for(int i = 1; i <= heapSize; i++) {
            a += heapArray[i] + "  ";
        }
        return a;
    }
}; 




