#!/usr/bin/env bash

SRC="bin"
INPUT="input/input.txt"
DECIMAL_INPUT="input/input_decimal.txt"

print_banner() {
	printf "\e[1;36m\n"

	printf " ███████╗ ██████╗ ██████╗ ████████╗██████╗ ███████╗███╗   ██╗ ██████╗██╗  ██╗\n"
	printf " ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔════╝████╗  ██║██╔════╝██║  ██║\n"
	printf " ███████╗██║   ██║██████╔╝   ██║   ██████╔╝█████╗  ██╔██╗ ██║██║     ███████║\n"
	printf " ╚════██║██║   ██║██╔══██╗   ██║   ██╔══██╗██╔══╝  ██║╚██╗██║██║     ██╔══██║\n"
	printf " ███████║╚██████╔╝██║  ██║   ██║   ██████╔╝███████╗██║ ╚████║╚██████╗██║  ██║\n"
	printf " ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝\n"

	printf "\e[1;33m"
	printf "             Sorting Algorithm Benchmark Suite\n"

  printf "\e[0m"

  printf "\e[94m"
  printf " ──────────────────────────────────────────────────────────────────────\n"

  printf "\e[97m"
  printf "  Author    \e[94m→\e[96m Azmat Ali\n"

  printf "\e[97m"
  printf "  Language  \e[94m→\e[96m C\n"

  printf "\e[97m"
  printf "  Build     \e[94m→\e[96m Makefile\n"

  printf "\e[94m"
  printf " ──────────────────────────────────────────────────────────────────────\n\n"

  printf "\e[0m"
}

print_header() {
	printf "\e[1;34m"
	printf " ┌──────────────────────┬────────────────┐\n"
	printf " │ Algorithm            │ Time           │\n"
	printf " ├──────────────────────┼────────────────┤\n"
	printf "\e[0m"
}

print_footer() {
	printf "\e[1;34m"
	printf " └──────────────────────┴────────────────┘\n"
	printf "\e[0m"
}

run_benchmark() {
	algorithm="$1"
	command="$2"

	exec_time=$(python3 -c "import subprocess,time;start=time.perf_counter();subprocess.run('$command',shell=True,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL);end=time.perf_counter();print(f'{(end-start)*1000:.3f}')")

  printf " \033[1;34m│\033[0m %-21s\033[1;34m│\033[0m %11s ms \033[1;34m│\033[0m\n" \
		"$algorithm" "$exec_time"
}

print_banner
print_header

run_benchmark "Bubble Sort" "./$SRC/bubble_sort $INPUT"

run_benchmark "Insertion Sort" "./$SRC/insertion_sort $INPUT"

run_benchmark "Selection Sort" "./$SRC/selection_sort $INPUT"

run_benchmark "Merge Sort" "./$SRC/merge_sort < $INPUT"

run_benchmark "Quick Sort" "./$SRC/quick_sort < $INPUT"

run_benchmark "Counting Sort" "./$SRC/counting_sort < $INPUT"

run_benchmark "Bucket Sort" "./$SRC/bucket_sort $DECIMAL_INPUT"

run_benchmark "Heap Sort" "./$SRC/heap_sort < $INPUT"

print_footer