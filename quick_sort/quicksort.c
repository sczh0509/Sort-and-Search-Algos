#include <stdio.h>

// function to swap elements
void	ft_swap(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

// function to find partition position
int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	// select rightmost element as pivot
	pivot = array[high];
	// index for greater element
	i = low - 1;

	// traverse each element of the array
	// compare with pivot
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
	}
	// after reaching second last element
	// swap the pivot element with the latest greater element
	ft_swap(&array[i + 1], &array[high]);
	// return partition position
	return (i + 1);
}

void	quickSort(int array[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

// display elements
void	printArray(int array[], int size)
{
	int	i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

// driver code
int	main(void)
{
	int	data[] = {8, 9, 2, 6, 1, 0, 9, 9};

	int size = sizeof(data) / sizeof(data[0]);
	printArray(data, size);

	quickSort(data, 0, size - 1);

	printf("sorted array in ascending order: \n");
	printArray(data, size);
}
