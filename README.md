# SortBench

> A CLI benchmarking suite for classic sorting algorithms written in C.

SortBench is a small systems-style C project focused on implementing and
benchmarking classic sorting algorithms from scratch.

The project includes:

- multiple sorting algorithm implementations
- benchmark automation
- dataset generators
- formatted terminal output
- Makefile-based build system

Built mainly as a low-level programming and algorithm practice project.

---

## 📸 Preview

### Benchmark Output

[Benchmark Screenshot](docs/screenshots/benchmark.png)

---

# ✨ Features

- 🔹 Multiple sorting algorithms implemented from scratch
- 🔹 Benchmark runner with formatted terminal UI
- 🔹 Integer + floating point dataset support
- 🔹 Random dataset generators
- 🔹 ANSI-colored CLI interface
- 🔹 Modular project structure
- 🔹 Makefile build system
- 🔹 Dynamic memory cleanup and allocation checks

---

# 🧠 Algorithms Included

| Algorithm      | Best       | Average    | Worst      | Stable  |
| -------------- | ---------- | ---------- | ---------- | ------- |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | ✅      |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | ✅      |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | ❌      |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | ✅      |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | ❌      |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | ❌      |
| Counting Sort  | O(n + k)   | O(n + k)   | O(n + k)   | ✅      |
| Bucket Sort    | O(n + k)   | O(n + k)   | O(n²)      | Depends |

---

# 📂 Project Structure

```bash
sortbench/
├── bin/            # compiled binaries
├── include/        # header files
├── input/          # generated datasets
├── obj/            # object files
├── src/            # source files
├── Makefile
├── script.sh       # benchmark runner
└── README.md
```

---

# Build

Clone the repository:

```bash
git clone https://github.com/AzzVipe/sortbench.git
cd sortbench
```

Compile the project:

```bash
make
```

Clean build files when needed:

```bash
make clean
```

---

# Generating Input Files

Generate integer dataset:

```bash
./bin/num_generator <SIZE>
```

Generate floating-point dataset:

```bash
./bin/decimal_generator <SIZE>
```

Example:

```bash
./bin/num_generator 100000

./bin/decimal_generator 100000
```

Generated files are stored inside:

```bash
input/
```

---

# Running Benchmarks

Run all sorting benchmarks:

```bash
./script.sh
```

The benchmark runner:

- executes each sorting implementation
- measures execution time
- displays results in a formatted table

---

# 🛠️ Architecture

Each sorting algorithm is implemented as a separate executable inside `src/`.

Example:

```bash
src/quick_sort.c
src/merge_sort.c
src/heap_sort.c
```

The benchmark workflow is:

```text
input file
   ↓
sorting executable
   ↓
script.sh measures execution time
   ↓
formatted benchmark output
```

The project intentionally separates:

- sorting logic
- benchmarking logic
- dataset generation
- terminal UI

into independent components.

---

# 📝 Notes

- Benchmarks currently measure executable runtime rather than isolated
  in-process sorting time.
- Bucket sort uses linked-list buckets internally.
- ANSI escape sequences are used for terminal colors and formatted CLI output.
- The project was built and tested on Linux.
- Compiler warnings are enabled using:

```bash
-Wall -Wextra -Werror
```

---

# 📊 Example Output

```text
┌───────────────────────┬────────────────┐
│ Algorithm             │ Time           │
├───────────────────────┼────────────────┤
│ Bubble Sort           │ 21146.573 ms   │
│ Insertion Sort        │  3571.044 ms   │
│ Selection Sort        │  5156.427 ms   │
│ Merge Sort            │   152.325 ms   │
│ Quick Sort            │   157.089 ms   │
│ Counting Sort         │   150.858 ms   │
│ Bucket Sort           │    60.998 ms   │
│ Heap Sort             │     0.883 ms   │
└───────────────────────┴────────────────┘
```

---

# 🎨 Terminal UI

SortBench includes:

- ANSI-colored output
- formatted benchmark tables
- custom CLI banner
- aligned timing output

Designed mainly to improve readability and terminal presentation.

---

# 🔍 Things Learned While Building This

- dynamic memory management in C
- sorting algorithm internals
- linked lists
- file handling
- Makefiles
- benchmarking basics
- modular C project structure
- ANSI terminal formatting

---

# 🚧 Future Improvements

- CSV benchmark export
- graph generation using Python
- in-process benchmarking
- multithreaded merge sort
- comparison against libc `qsort()`
- ncurses-based terminal UI

---

## 📜 License

MIT License
