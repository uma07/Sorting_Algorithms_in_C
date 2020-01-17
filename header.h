#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{ int data;
                     struct node * next;
      		   }node;
typedef struct queue_node{
	                   node * front;
			   node * rear;
			 }queue_node;
typedef queue_node * Queue;
Queue create_queue();
node * create_node();
bool isempty(Queue Q);
Queue Enqueue(int x,Queue Q);
int Dequeue(Queue Q);
void inst_sort(int *num,int size);
void selection_sort(int *num,int size);
void Shell_sort(int *num,int size);
void bubble_sort(int *num,int size);
void merge_sort(int *num,int size);
void msort(int *num,int *temparray,int left,int right);
void merge(int *num,int *temparray,int LP,int RP,int RE);
void quick_sort(int *num,int size); 
void Q_sort(int *num,int left,int right);
int median3(int *num,int left,int right);
void swap(int *a,int *b);
void RANDOM_NUMBERS(int *a,int size);
void ASCENDING_ORDER(int *a,int size); 
void DESCENDIG_ORDER(int *a,int size);
void SEME_NUMBERS(int *a,int size);
void radix_sort(int *num,int size);
void Heapsort(int *arr, int size);
void buildheap(int *arr, int size);
int delete_root(int *arr, int *size);
void restoredown(int *arr, int i, int size);
void display(int *arr, int size); 
void create_file(int c,int *a,int N);
void file_to_array(int c,int *a,int N);
void array_to_file(int *a,int i,int N,FILE *out);
void do_all_sortings(FILE *in,int *a,int c,int N);
void file_to_array1(FILE *in,int *a,int N);
void do_all_sortings1(FILE *in,int *a,int N);
void BUBBLE_SORT(int *b,int count);
void INSERTION_SORT(int *b,int count);
void SELECTION_SORT(int *b,int count);
void SHELL_SORT(int *b,int count);
void MERGE_SORT(int *b,int count);
void QUICK_SORT(int *b,int count);
void RADIX_SORT(int *b,int count);
void HEAP_SORT(int *b,int count);
void select_sorting_method(int e,int *a,int N);

