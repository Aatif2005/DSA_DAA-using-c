cmake_minimum_required(VERSION 4.2)
project(DSA_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Assingment_dsa)
include_directories("DSA PRACTICE")
include_directories("LAB 3 DSA")
include_directories("LAB 4 DSA")
include_directories("LAB 5 DSA")
include_directories("LAB 6 DSA")
include_directories("LAB 7 DSA")
include_directories("LAB1 DSA")
include_directories("LAB2 DSA")

add_executable(DSA_C
        Assingment_dsa/aaing2_3.c
        Assingment_dsa/asing1.c
        Assingment_dsa/assing2.c
        Assingment_dsa/assing2_lab3.c
        Assingment_dsa/assing3.c
        "DSA PRACTICE/Stack C/stack_linked_list.c"
        "DSA PRACTICE/Stack C/stack_multi_parnth.c"
        "DSA PRACTICE/Stack C/stack_operation.c"
        "DSA PRACTICE/Stack C/stack_paranthesis.c"
        "DSA PRACTICE/Stack C/stack_peek_.c"
        "DSA PRACTICE/Stack C/stack_top_bottam.c"
        "DSA PRACTICE/Stack C/stack_using_arr.c"
        "DSA PRACTICE/arrays_adt.c"
        "DSA PRACTICE/circular_linked_list.c"
        "DSA PRACTICE/deletion_arr.c"
        "DSA PRACTICE/deletion_in_linkedlist.c"
        "DSA PRACTICE/insertion_arr.c"
        "DSA PRACTICE/insertion_in_first.c"
        "DSA PRACTICE/linear_binarysearch.c"
        "DSA PRACTICE/lined_list_insertion_at_index.c"
        "DSA PRACTICE/linked_list_insertend.c"
        "DSA PRACTICE/linked_list_insertion.c"
        "DSA PRACTICE/linked_list_traverse.c"
        "DSA PRACTICE/time_complex1.c"
        "LAB 3 DSA/exp1.c"
        "LAB 3 DSA/exp1a.c"
        "LAB 4 DSA/exp1.c"
        "LAB 4 DSA/exp2.c"
        "LAB 5 DSA/exp1.c"
        "LAB 5 DSA/exp2.c"
        "LAB 5 DSA/exp3.c"
        "LAB 5 DSA/tempCodeRunnerFile.c"
        "LAB 6 DSA/assing1.c"
        "LAB 6 DSA/assing2.c"
        "LAB 6 DSA/assing3.c"
        "LAB 6 DSA/tempCodeRunnerFile.c"
        "LAB 7 DSA/exp1.c"
        "LAB1 DSA/exp1.c"
        "LAB1 DSA/exp2.c"
        "LAB1 DSA/exp3.c"
        "LAB2 DSA/exp1.c"
        "LAB2 DSA/exp2.c"
        "LAB2 DSA/exp3.c"
        "LAB2 DSA/exp4.c"
        "DSA PRACTICE/Stack C/stack1.c"
        "DSA PRACTICE/Stack C/stack1.c"
        "DSA PRACTICE/Queue C/queue_arr.c"
        "DSA PRACTICE/Queue C/circular_queue_arr.c"
        "LAB 8 DSA/binary_search_tree.c"
        "DSA PRACTICE/Queue C/queue_using_linked_list.c"
        "DSA PRACTICE/Queue C/DE_queue.c"
        "LAB 9 DSA/bubble_sort.c"
        "LAB 9 DSA/insertion_sort.c"
        dsa1.cpp
        dsa1.h
        "LOOPS PROBLEM/sumof_n_number.cpp"
        "LOOPS PROBLEM/sumof_n_number.h"
        "LOOPS PROBLEM/factorial.c"
        "LOOPS PROBLEM/count_number.c"
        "LOOPS PROBLEM/sum_of_digit.c"
        "LOOPS PROBLEM/reverse_number.c"
        "LOOPS PROBLEM/palindrome.c"
        "LOOPS PROBLEM/amstrong.c"
        "LOOPS PROBLEM/amstrong.c"
        "LOOPS PROBLEM/gcd_num.c"
        DAA/binarysearch_iterative.c
        DAA/binarysearch_recursion.c
        DAA/merge_sort.c
        DAA/binarysearchtree_iterative.c
        DAA/binarysearchtree_recursive.c
        DAA/quick_sort.c)
