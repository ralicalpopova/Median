// Median.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sample
{
	vector<int> currentSample;
	
	void addSample(vector<int> sample)
	{
		currentSample = sample;
	}

	double extractMedian()
	{
		if (!currentSample.empty())
		{
			int size = currentSample.size();
			sort(currentSample.begin(), currentSample.end());
			if (size % 2 != 0)
			{
				return currentSample[size / 2];
			}
			else
			{
				return (double)(currentSample[(size - 1) / 2] + currentSample[size / 2]) / 2.0;
			}
		}
	}

	void addNumber(int number)
	{
		currentSample.push_back(number);
	}

	void printSample()
	{
		int size = currentSample.size();
		printf("The sample is: ");
		for (int i = 0; i < size; i++)
		{
			printf(" %d ", currentSample[i]);
		}
		printf("\n");
	}
};

void test()
{
	vector<int> someVector;
	for (int i = 0; i < 50; i++)
	{
		int a = rand() % 100;
		someVector.push_back(a);
	}
	Sample obj;
	
	obj.addSample(someVector);
	obj.printSample();
	printf("\The meadian is %f\n", obj.extractMedian());
	obj.addNumber(15);
	obj.printSample();
	printf("The meadian is %f\n", obj.extractMedian());
	obj.addNumber(15);
	obj.addNumber(30);
	obj.addNumber(20);
	obj.printSample();
	printf("The meadian is %f\n", obj.extractMedian());

}

int main()
{
	test();
    return 0;
}

