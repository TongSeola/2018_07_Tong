#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr << "Input file opening failed." << endl;
		exit(1);
	}

	inStream >> numTestCases;

	while(numTestCases--)
	{
		unsigned int multiple = 1;
		unsigned int new_number;
		int count_of_divide10 = 0;
		int count_of_divide2 = 0;
		int count_of_divide5 = 0;
		int count_of_new_number;

		inStream >> count_of_new_number;

		for(int i=0;i<count_of_new_number;i++)
		{
			inStream >> new_number;

			while((new_number % 2 == 0)||(new_number % 5 == 0))
			{
				if(new_number % 2 == 0)
				{
					count_of_divide2++;
					new_number /= 2;
				}
				if(new_number % 5 == 0)
				{
					count_of_divide5++;
					new_number /= 5;
				}
			}
			new_number %= 10;
			multiple *= new_number;
			multiple %= 10;
		}

		while(count_of_divide2 > 0 && count_of_divide5 > 0)
		{
			count_of_divide10++;
			count_of_divide2--;
			count_of_divide5--;
		}
		for(int i=0;i<count_of_divide2;i++)
		{
			multiple *= 2;
			multiple %= 10;
		}
		for(int i=0;i<count_of_divide5;i++)
		{
			multiple *= 5;
			multiple %= 10;
		}

		cout << multiple << " " << count_of_divide10 << endl;
	}

	inStream.close();

    return 0;
}