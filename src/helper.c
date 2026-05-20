#include<stdio.h>
#include<stdlib.h>
#include<helper.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);

	puts("");
}

int populate_array(FILE *fp, int **array)
{
	int len = 0;

	fscanf(fp, "%d", &len);
	fprintf(stderr, "Size: %d\n", len);
	int *arr = (int *) malloc((sizeof(int) * len) + 1);

	if(arr == NULL) {
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < len; i++) {
		fscanf(fp, "%d", &arr[i]);
	}

	*array = arr;

	return len;
}

int populate_array_double(FILE *fp, double **array)
{
	int len = 0;

	fscanf(fp, "%d", &len);
	fprintf(stderr, "Size: %d\n", len);
	*array = (double *) malloc((sizeof(double) * len) + 1);

	if(array == NULL) {
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < len; i++) {
		fscanf(fp, "%lf", &(*array)[i]);
	}

	return len;
}
