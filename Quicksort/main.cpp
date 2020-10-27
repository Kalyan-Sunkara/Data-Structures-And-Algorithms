#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}


int Partition_midPoint(int numbers[], int lowIndex, int highIndex) {
   // Pick middle element as pivot
   int temp = 0;
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[midpoint];
   
   bool done = false;
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1;
      }
      
      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1;
      }
      
      // If zero or one elements remain, then all numbers are 
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;
         
         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }
   
   return highIndex;
}

int Partition_median(int numbers[], int lowIndex, int mid, int highIndex) {
   // Pick middle element as pivot
   int temp = 0;
   int midpoint = numbers[mid];
   if((numbers[lowIndex] > numbers[mid] && numbers[lowIndex] < numbers[highIndex]) || 
		(numbers[lowIndex] > numbers[highIndex] && numbers[lowIndex] < numbers[mid]))
   {
//	   midpoint = lowIndex;
	   if(numbers[lowIndex] < numbers[mid]) //condition: high < low < mid
	   {
//		   int temp1 = numbers[mid];
		   numbers[mid] = numbers[lowIndex];
		   numbers[lowIndex] = numbers[highIndex];
		   numbers[highIndex] = midpoint;
	   }
	   else // condition: mid < low < high
	   {
		   numbers[mid] = numbers[lowIndex];
		   numbers[lowIndex] = midpoint;
	   }
   }
   else if((numbers[mid] > numbers[lowIndex] && numbers[mid] < numbers[highIndex]) || 
		(numbers[mid] > numbers[highIndex] && numbers[mid] < numbers[lowIndex]))
		{
//			midpoint = mid;
			if(numbers[mid] < numbers[lowIndex])
			{
				int temp1 = numbers[lowIndex];
				numbers[lowIndex] = numbers[highIndex]; 
				numbers[highIndex] = temp1;
			}
		}
	else
		{
//			midpoint = highIndex;
			if(numbers[highIndex] > numbers[mid])
			{
				numbers[mid] = numbers[highIndex];
				numbers[highIndex] = numbers[lowIndex];
				numbers[lowIndex] = midpoint;
			}
			else
			{
				numbers[mid] = numbers[highIndex];
				numbers[highIndex] = midpoint;
			}
		}
//   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[mid];
   
   bool done = false;
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1;
      }
      
      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1;
      }
      
      // If zero or one elements remain, then all numbers are 
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;
         
         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }
   
   return highIndex;
}
void Quicksort_midpoint(int numbers[], int lowIndex, int highIndex) {
   // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (lowIndex >= highIndex) {
      return;
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   int lowEndIndex = Partition_midPoint(numbers, lowIndex, highIndex);
   
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   Quicksort_midpoint(numbers, lowIndex, lowEndIndex);
   Quicksort_midpoint(numbers, lowEndIndex + 1, highIndex);
}

void Quicksort_medianOfThree(int numbers[], int lowIndex, int highIndex)
{
   // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (lowIndex >= highIndex) {
      return;
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   int lowEndIndex = Partition_median(numbers, lowIndex, (lowIndex + (highIndex)) / 2, highIndex);
   
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   Quicksort_medianOfThree(numbers, lowIndex, lowEndIndex);
   Quicksort_medianOfThree(numbers, lowEndIndex + 1, highIndex);
}

void InsertionSort(int numbers[], int numbersSize)
{
	int j = 0;
	int temp = 0;
	for(int i = 0; i < numbersSize; i++)
	{
		j = i;
		while(j > 0 && numbers[j] < numbers[j-1])
		{
			temp = numbers[j];
			numbers[j] = numbers[j-1];
			numbers[j-1] = temp;
			--j;
		}
	}
}

int main()
{
	int arr1[NUMBERS_SIZE];
	int arr2[NUMBERS_SIZE];
	int arr3[NUMBERS_SIZE];
	fillArrays(arr1, arr2, arr3);
//	int arr4[NUMBERS_SIZE];
//	for(int i = 0; i < NUMBERS_SIZE; i++)
//	{
//		arr4[i] = rand();
//	}
	clock_t Start = clock();
	//call sort function here
	for(int i = 0; i < NUMBERS_SIZE; i++)
	{
		cout << arr3[i] << " " << endl;
	}
	cout << endl;
//	InsertionSort(arr1, NUMBERS_SIZE);
//arr4[0] = 1;
//arr4[1] = 2;
//arr4[2] = 3;
//arr4[3] = 4;
//arr4[4] = 5;
//arr4[5] = 7;
//arr4[6] = 6;
//	for(int i = 0; i < 7; i++)
//	{
//		cout << arr4[i] << " " << endl;
//	}
//	cout << endl;
//	Quicksort_midpoint(arr2, 0, NUMBERS_SIZE-1);
//	
	Quicksort_medianOfThree(arr3, 0 , NUMBERS_SIZE-1);
	for(int i = 0; i < NUMBERS_SIZE; i++)
	{
		cout << arr3[i] << " " << endl;
	}
//	Quicksort_medianOfThree(arr4, 0 , 6);
//	for(int i = 0; i < 7; i++)
//	{
//		cout << arr4[i] << " " << endl;
//	}
	clock_t End = clock();
	int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << elapsedTime << endl;
	return 0;
}
