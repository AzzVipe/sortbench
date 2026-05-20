#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>

#define BUBBLE    "Bubble Sort"
#define SELECTION "Selection Sort"
#define INSERTION "Insertion Sort"
#define MERGE     "Merge Sort"
#define QUICK     "Quick Sort"
#define COUNTING  "Counting Sort"
#define BUCKET    "Bucket Sort"
#define HEAP      "Heap Sort"

#define BUBBLE_PATH    "./bin/bubble_sort"
#define SELECTION_PATH "./bin/selection_sort"
#define INSERTION_PATH "./bin/insertion_sort"
#define MERGE_PATH     "./bin/merge_sort"
#define QUICK_PATH     "./bin/quick_sort"
#define COUNTING_PATH  "./bin/counting_sort"
#define BUCKET_PATH    "./bin/bucket_sort"
#define HEAP_PATH      "./bin/heap_sort"

#define INPUT_INTEGER  "input/input.txt"
#define INPUT_DECIMAL  "input/input_decimal.txt"

struct data {
	char *algo_name;
	char *alias;
	char *path;
	char *input;
};

struct data algos[] = {
	{ BUBBLE,    "bubble",    BUBBLE_PATH,    INPUT_INTEGER },
	{ SELECTION, "selection", SELECTION_PATH, INPUT_INTEGER },
	{ INSERTION, "insertion", INSERTION_PATH, INPUT_INTEGER },
	{ MERGE,     "merge",     MERGE_PATH,     INPUT_INTEGER },
	{ QUICK,     "quick",     QUICK_PATH,     INPUT_INTEGER },
	{ COUNTING,  "counting",  COUNTING_PATH,  INPUT_INTEGER },
	{ BUCKET,    "bucket",    BUCKET_PATH,    INPUT_DECIMAL },
	{ HEAP,      "heap",      HEAP_PATH,      INPUT_DECIMAL },
	{ NULL,      NULL,        NULL,           NULL }
};

void tv_sub(struct timeval *end, struct timeval *start, struct timeval *diff)
{
	diff->tv_usec = end->tv_usec - start->tv_usec;
	diff->tv_sec  = end->tv_sec - start->tv_sec;

	if (diff->tv_usec < 0) {
		diff->tv_sec = end->tv_sec - 1;
		diff->tv_usec = diff->tv_usec + 1000000;
	}
}

void run_program(int index)
{
	struct data temp = algos[index];
	
	char buf[1024];

	sprintf(buf, "%s < %s > /dev/null", temp.path, temp.input);
	printf("\n%s\n", temp.algo_name);
	system(buf);
}

int find_index(char *algo_alias)
{
	for(int i = 0; algos[i].alias; i++) {
		if(strcmp(algo_alias, algos[i].alias) == 0)
			return i;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	int index = 0;
	struct timeval start, stop, diff;
	if(argc	== 1) {
		for(int i = 0; algos[i].alias; i++)
			run_program(i);	
	} else {
		for(int i = 1; argv[i]; i++) {
			if((index = find_index(argv[i])) == -1) 
				continue;
			else {
				gettimeofday(&start, NULL);
				run_program(index);
				gettimeofday(&stop, NULL);
				tv_sub(&stop, &start, &diff);
				printf("Execution Time: %02lds : %02ldms\n", diff.tv_sec, diff.tv_usec);
			}
		}
	}

	return 0;
}
