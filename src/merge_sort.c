#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

void merge(int array[], int start, int mid, int end) {
	//int temp[end - start + 1];
	int *temp = malloc(sizeof(int) * (end - start + 1));

	int i = start, j = mid + 1, k = 0;

	while(i <= mid && j <= end) {
		if(array[i] <= array[j]) 
			temp[k++] = array[i++];
		else 
			temp[k++] = array[j++];
	}

	while(i <= mid)
		temp[k++] = array[i++];

	while(j <= end)
		temp[k++] = array[j++];
	
	for(int i = start; i <= end; i++)
		array[i] = temp[i - start];

	free(temp);
}

void merge_sort(int array[], int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;

		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);

		merge(array, start, mid, end);
	}
}

int main(int argc, char *argv[]) 
{
	int size = 0, *array;
	char *filename;
	FILE *fp;

	if(argc == 2) {
		filename = strdup(argv[1]);

		if((fp = fopen(filename, "r")) == NULL) {
			perror("fopen error");
			exit(EXIT_FAILURE);
		}
 	
		size = populate_array(fp, &array);
	} else if (argc == 1) {
		scanf("%d", &size);
		array = malloc(sizeof(int) * (size + 1));

		if(array == NULL) {
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

		for(int i = 0; i < size; i++)
			scanf("%d", &array[i]);
	} else {
		fprintf(stderr, "Usage: %s || <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Array before sorting: \n");
	print_array(array, size);

	merge_sort(array, 0, size - 1);
	printf("Array after sorting: \n");
	print_array(array, size);

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
