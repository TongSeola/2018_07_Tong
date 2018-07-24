import java.util.*;

// Name :
// Student ID :


class Chain <T> {
	
	class ChainNode <U> 
	{
		private U data;	// storage for data 데이터 저장소
		private ChainNode<U> link;	// link to the next node 다음노드로 연결

		// constructors come here
		ChainNode() 
		{
			this.link = null;
			// the link field is null 
		}
		ChainNode(U data) 
		{
			// set the data field only 
			this.data = data;
		}
		ChainNode(U data, ChainNode<U> link) 
		{
			// set the data field and link field
			this.data = data;
			this.link = link;
		}
	};

	private ChainNode<T> first; // reference to the first node 첫 번째 노드에 대한 참조

	Chain() 
	{ 
		// 즉 첫번째 노드는 null값으로 받아 온다
		first = null;
	}

	boolean IsEmpty() {return first == null;}
	// 만약 비어 었다면 null을 return

	/**
	 * Show all the elements in the Chain in sequence
	 */
	public String toString() 
	// 오브젝트를 프린트 했을 경우 나오는 것들
	{ 
		ChainNode<T> p = first;

		String str = new String();
		str = String.format("List (%d) : ", Size());

		// show all the nodes
		while (p != null) {
			str += p.data + " ";
			p = p.link; // 다음으로 넘기기
		}
		return str;
	}

	/**
	 * insert theElement in theIndex
	 */

	boolean Insert(int theIndex, T theElement) 
	// theIndex자리에 theElement값을 추가한다
	// 현재 있는 리스트의 자리수보다 큰 값이 들어온 경우 불가 판정
	{
		if (theIndex < 0)
		{
			System.out.println("Bad insert index");
			return false;
		}
		if (theIndex == 0)
		{
			first = new ChainNode<T> (theElement, first);
			return true;
		}
		else
		{
			ChainNode<T> p =first;
			for (int i=0; i < theIndex-1; i++)
			{
				if (p == null)
				{
					System.out.print("Bad");
					return false;
				}
				p = p.link;
			}
			if (p == null)
			{
				System.out.println("s");
				return false;
			}
			p.link = new ChainNode<T> (theElement, p.link);
		}
		return true;
	}

	/**
	 * delete an element from the first 
	 */
	T DeleteFront() 
	// 리스트 맨 앞의 노드 삭제 
	// 제거된 값을 return 
	// 리스트가 빈경우 null을 return
	{   
		T one = null;
		
		if (first == null)
		{
			System.out.println("Cannot delete from empty chain");
			return null;
		}
		else
		{
			one = first.data;
			first = first.link;
		}
		return one;
	}

	/**
	 * return the number of elements in Chain
	 */
	final int  Size()
	// 현재 리스트에 있는 원소의 수를 알려준
	{
		ChainNode<T> p = first;
		int cnt = 0;
		
		while (p!= null)
		{
			p = p.link; //p.link를 하면 다음것으로 넘어간다 
			cnt ++;
		}
		
		return cnt;
	}

}



