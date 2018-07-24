import java.util.*;
import java.lang.*;

class SparseMatrix {
	MatrixTerm[] smArray;
	int rows, cols;
	int capacity;   // size of smArray
	int terms;  // number of nonzero terms

	class MatrixTerm {
		int row;
		int col;
		int value;
	};

	// constructor
	SparseMatrix(int r, int c, int t) {
		capacity = 128;
		smArray = new MatrixTerm[capacity];
		terms = t;
		rows = r;
		cols = c;
	}

	/**
	*  Add a new term to the end of smArray
	*/
	void NewTerm(int row, int col, int value) {   
		if(terms == capacity)
		{// double capacity of smArray
			try {
				ChangeSize1D (capacity * 2);
			} catch (Exception e) {
				System.out.println("not enough capacity");
			}
		}
		smArray[terms] = new MatrixTerm();
		smArray[terms].row = row;
		smArray[terms].col = col;
		smArray[terms++].value = value;
	}

	int Compare(MatrixTerm a, MatrixTerm b) {
		// if a is smaller than b in row major order, return negative value
		// if a is the same as b in row major order, return 0
		// if b is smaller than a in row major order, return positive value
		if(a.row == b.row)
			return a.col - b.col;
		else
			return a.row - b.row;
	}



	int StoreSum (int sum, int r, int c) {
		//If sum!= 0, then it along with its row and column 
		 //position are stored as the last term in *this
		if (sum != 0) { 
			if (terms == capacity) {
				try {
					ChangeSize1D (capacity * 2);
				} catch (Exception e) {
					System.out.println("not enough capacity");
				}
			}
			smArray[terms] = new MatrixTerm();
			smArray[terms].row = r;
			smArray[terms].col = c;
			smArray[terms++].value = sum;
			return 0;
		}
		return 0;
	}


	void ChangeSize1D (final int newSize) throws Exception 
	{//Change the size of smArray to newSize
		if(newSize < terms) 
			throw new Exception("New size must be >= number of terms");

		capacity = newSize;
		MatrixTerm[] temp = new MatrixTerm[capacity]; // new array
		System.arraycopy(smArray, 0, temp, 0, terms);
		smArray = temp;
	}

	// init the polynomial
	public String toString() {
		String a = new String();
		int number = 0;
		// show the content of smArray
		a = "Content of smArray :\n";
		for(int i = 0; i < terms;i++) {
			if (smArray[i].value ==0) {
				continue;
			}
			else {
			a += "[" + number + "] " + smArray[i].row + " " + smArray[i].col + " "  
				+ smArray[i].value + "\n";
			number++;
			}
		}
		a += "=========" + "\n";

		return a;
	}


	SparseMatrix Add(SparseMatrix b) {
		// Return the sum of the Sparse Matrices *this and b

		SparseMatrix c = new SparseMatrix(rows, cols, 0);

		if((rows != b.rows) || (cols != b.cols)) {
			System.err.println("The dimension mismatch");
			return c;
		}

		int aPos = 0, bPos = 0;

		while ((aPos < this.terms) && (bPos < b.terms)) {
			int diff;
			diff = Compare(this.smArray[aPos], b.smArray[bPos]);
			if (diff > 0) {
				c.NewTerm(b.smArray[bPos].row, b.smArray[bPos].col, b.smArray[bPos].value );
				bPos++;
			}
			else if(diff < 0) {
				c.NewTerm(this.smArray[aPos].row, this.smArray[aPos].col, this.smArray[aPos].value );
				aPos++;
			}
			else {
				int apb = b.smArray[bPos].value + this.smArray[aPos].value;
				c.NewTerm(b.smArray[bPos].row, b.smArray[bPos].col, apb);
				
				aPos++;
				bPos++;
			}
		}

		if (aPos < this.terms) {
			c.NewTerm(this.smArray[aPos].row, this.smArray[aPos].col, this.smArray[aPos].value );
			aPos++;
		}
		if (bPos < b.terms ) {
			c.NewTerm(b.smArray[bPos].row, b.smArray[bPos].col, b.smArray[bPos].value );
			bPos++;
		}


	// NEED TO IMPLEMENT



		// return the sum, c
		return c;
	}		
}


