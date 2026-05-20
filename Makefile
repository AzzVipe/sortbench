CC=gcc
HEADSPATH=include
SRCSPATH=src
BINPATH=bin
OBJSPATH=obj
OBJS=$(OBJSPATH)/helper.o

CFLAGS=-g -I $(HEADSPATH) -Wall -Wextra -Werror

all: helper bubble_sort selection_sort insertion_sort merge_sort quick_sort counting_sort bucket_sort run

clean:
	rm -rf bin/* obj/*

helper: $(SRCSPATH)/helper.c
	$(CC) -c -o $(OBJSPATH)/helper.o $(SRCSPATH)/helper.c $(CFLAGS)

run: run.c
	$(CC) -o run run.c $(CFLAGS)

num_generator: $(SRCSPATH)/num_generator.c 
	$(CC) -o num_generator $(SRCSPATH)/num_generator.c $(CFLAGS) $(OBJS)

decimal_generator: $(SRCSPATH)/decimal_generator.c
	$(CC) -o decimal_generator $(SRCSPATH)/decimal_generator.c $(CFLAGS) $(OBJS)

bubble_sort: $(SRCSPATH)/bubble_sort.c
	$(CC) -o $(BINPATH)/bubble_sort $(SRCSPATH)/bubble_sort.c $(CFLAGS) $(OBJS)

selection_sort: $(SRCSPATH)/selection_sort.c
	$(CC) -o $(BINPATH)/selection_sort $(SRCSPATH)/selection_sort.c  $(CFLAGS) $(OBJS)

insertion_sort: $(SRCSPATH)/insertion_sort.c
	$(CC) -o $(BINPATH)/insertion_sort $(SRCSPATH)/insertion_sort.c  $(CFLAGS) $(OBJS)

merge_sort: $(SRCSPATH)/merge_sort.c
	$(CC) -o $(BINPATH)/merge_sort $(SRCSPATH)/merge_sort.c  $(CFLAGS) $(OBJS)

quick_sort: $(SRCSPATH)/quick_sort.c
	$(CC) -o $(BINPATH)/quick_sort $(SRCSPATH)/quick_sort.c  $(CFLAGS) $(OBJS)

counting_sort: $(SRCSPATH)/counting_sort.c
	$(CC) -o $(BINPATH)/counting_sort $(SRCSPATH)/counting_sort.c  $(CFLAGS) $(OBJS)

bucket_sort: $(SRCSPATH)/bucket_sort.c
	$(CC) -o $(BINPATH)/bucket_sort $(SRCSPATH)/bucket_sort.c  $(CFLAGS) $(OBJS)

heap_sort: $(SRCSPATH)/heap_sort.c
	$(CC) -o $(BINPATH)/heap_sort $(SRCSPATH)/heap_sort.c  $(CFLAGS) $(OBJS)

min_heap_sort: $(SRCSPATH)/min_heap_sort.c
	$(CC) -o $(BINPATH)/min_heap_sort $(SRCSPATH)/min_heap_sort.c  $(CFLAGS) $(OBJS)
