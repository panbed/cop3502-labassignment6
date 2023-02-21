#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	if (numbers == NULL)
		return -1;
	
	//printf("DEBUG: We are looking for %d...\n", value);
	int mid = ((high - low) / 2) + low;
	//printf("DEBUG: mid is (%d - %d) / 2 = %d with a value of %d\n", high, low, mid, numbers[mid]);
	//printf("DEBUG: looking at numbers[%d]\n", mid);

	if (low == high)
		return -1;
	
	if (numbers[mid] == value) {
		//printf("DEBUG: We found %d at numbers[%d]!\n", value, mid);
		return mid;
	}
	
	if (numbers[mid] > value) {
		//printf("DEBUG: numbers[%d] (%d) is greater than %d... calling search\n", mid, numbers[mid], value);
		return search(numbers, low, mid - 1, value);
	}
	
	if (numbers[mid] < value) {
		//printf("DEBUG: numbers[%d] (%d) is less than %d... calling search\n", mid, numbers[mid], value);
		return search(numbers, mid + 1, high, value);
	}

	//printf("DEBUG: returning -1...\n");
	return -1;
	

}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}