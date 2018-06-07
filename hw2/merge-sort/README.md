Please read the instructions carefully.

In order to find solution for Problem 2: Recurrences, please read 'p2.pdf'

Solutions for Problem 1: Merge Sort:

(a) Please see the source file 'main.cpp'. Merge sort algorithm is implemented as required in the problem statement. You can test the algorithm with STDIN and STDOUT.

(b) Source file 'random_main.cpp' generates average (random), best case and worst case sequences. In three of the cases it generates a sequence of a fixed length and sorts them every time using different constants K. For the average (random) cases I use the function rand(). For best cases I use already sorted arrays. For worst cases I use a descending sorted array. The plot for merge sort and the previous selection sort can be found in the file 'plot_merge_vs_selection_sort.pdf'.

(c) Worst cases and average cases are grow the same way, but with different rate (they look shifted). However, for the best cases, running time does not depend on K. This is the case, because of the concept of insertion sort:
    Since the running time of regular merge sort is Theta(nlogn), in our case it is Theta(nlogn + K^2) and that is because of the average running time of insertion sort is Theta(n^2). However, the best case of insertion sort is Omega(n) and that is the case when the array is already sorted. Since the best case of our variant of merge sort matches the best case of insertion sort, the running time of the base case of our variant of the merge sort is Omega(nlogn + K). No matter how big is K it is always the case that K <= n, therefore we omit that term and conclude that the best case running time is Omega(nlogn), just like regular merge sort. 

For the average and worst case, the running time makes significant jumps, because of the variation of K. As we said the running time is Theta(nlogn + K^2). When K is smaller, the term nlogn dominates and we "omit" K^2. However, as K grows, the term K^2 becomes dominant and we cannot omit it.

(d) I would choose as small K as possible, so that K << n. In this case, the running time won't vary that much from the regular merge sort, which beats the running time of insertion sort itself. 