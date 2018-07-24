// Lab 010	: Graph Floyd Algorithm 
// Name : Dong-Seol -a
// Student ID : 20171618

import java.util.*;


class Graph {
	int numofnodes;  // the number of nodes in the graph
	private int[][] CostAdj; // Adjacency matrix
	private int[][] c; // c array
	private int[][] kay; // kay array

	final int LargeCost = 999999999;

	Graph() { 
		// Graph constructor. 
		numofnodes = 0;
	}


	void Init(int n) { 
		numofnodes = n;
		// now create 2 dimensional array of numofnodes * numofnodes
		CostAdj = new int[numofnodes][numofnodes]; // edge length
		c = new int[numofnodes][numofnodes]; // shortest length
		kay = new int[numofnodes][numofnodes]; // max Node

		for(int i = 0; i < numofnodes; i++) {
			for(int j = 0; j < numofnodes; j++)
				CostAdj[i][j] = 0;//LargeCost;  // initialize the adjacency matrix
			//CostAdj[i][i] = 0;
		}

	}

	// return the path length between i and j
	int GetPathLength(int i, int j) { 
		return c[i][j]; 
	};



	void Edge(int v1, int v2, int cost) { 
	//	NEED TO IMPLEMENT 
		CostAdj[v1][v2] = cost;
		//디버깅
//		System.out.println("input : "+ CostAdj[v1][v2]);
	}

	void Floyd() { 
		// initialize the matrix
		for(int i = 0; i < numofnodes; i++) {
			// initialize all entries to 0
			for(int j = 0; j < numofnodes; j++) {
				c[i][j] = CostAdj[i][j]; // initial distances
				kay[i][j] = -1;	// not intermediate nodes
			}
		}
		//	NEED TO IMPLEMENT
		
		int length[] = new int[numofnodes];
		int sublength[] = new int[numofnodes];
		int maxNode[] = new int[numofnodes];
		
		for(int pathIndex = 0; pathIndex < numofnodes; pathIndex++)
		{ // 0부터 끝까지 만들어야 하므로
			for(int p=0; p<numofnodes; p++)
			{ // 할당
				length[p] = CostAdj[pathIndex][p];
				sublength[p] = CostAdj[pathIndex][p];
				maxNode[p] = -1;
			}
			for(int j=0; j< numofnodes; j++)
			{	
				for(int i = 0; i < numofnodes; i++) 
				{	// new
					if(sublength[i] !=0)
					{  
						for(int t=0; t < numofnodes ; t++)
						{
							if(CostAdj[i][t] !=0)
							{
								int put = CostAdj[i][t] + sublength[i];
								if( t != pathIndex && (sublength[t] == 0 || put <= sublength[t]))
								{
									length[t] = put;
									maxNode[t] = i;
								}}}}
					// 기존
					for(int k=0; k<numofnodes; k++)
					{
						sublength[k] = length[k];
					}
				}
				
			}
			for(int p=0; p<numofnodes; p++)
			{
				c[pathIndex][p] = length[p];
				kay[pathIndex][p] = maxNode[p];
			}
		}

	}
		// end of the algorithm

	String outputPath(int i, int j) { 
		//	NEED TO IMPLEMENT 
		String str = new String();
		String rstr = new String();
		str = String.valueOf(j);
		int index1 = i;
		int index2 = j;
		while(kay[index1][index2] != -1)
		{
			str = str + "-" + String.valueOf(kay[index1][index2]);
			index2 = kay[index1][index2];
		}
		str = str + "-";
		for(int index=str.length()-1; index >=0; index--)
		{
			rstr = rstr + str.charAt(index);
		}

		return rstr;
	}
}

