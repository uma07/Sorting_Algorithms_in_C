#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"header.h"
#define cutoff 3
#include"time.h" 
//**********************************************************************************
//For genetating random numbers
void RANDOM_NUMBERS(int *a,int size)
{
   int i;
   for(i=0;i<size-1;i++)
    {
       a[i]=random()%size;
    }
}


//**********************************************************************************
//For genetating numbers in ascending order
void ASCENDING_ORDER(int *a,int size)
{
    int i;
    for(i=0;i<size-1;i++)
     {
       a[i]=i;
     }
}


//**********************************************************************************
//For genetating numbers in descending order
void DESCENDIG_ORDER(int *a,int size)
{
   int i;
   for(i=size-1;i>=0;i--)
    {
     a[size-1-i]=i;
    }
}


//**********************************************************************************
//For genetating same numbers
void SEME_NUMBERS(int *a,int size)
{
   int i,r;
   r=9;
   for(i=0;i<size-1;i++)
    {
      a[i]=9;
    }
}

//**********************************************************************************
//Inserion Sort
void inst_sort(int *num,int size)
{
  int i,j,k;
  for(i=1;i<size;i++)
   {
     k=num[i];
     for(j=i-1;j>=0 && k<num[j];j--)
     {
       num[j+1]=num[j];
     }
     num[j+1]=k;
   }
}


//**********************************************************************************
//Selection sort
void selection_sort(int *num,int size)
{
   int i,j,temp,min;
   for(i=0;i<size-1;i++)
     {
       min=i;
       for(j=i+1;j<size;j++)
         {
            if(num[min]>num[j])
                 min=j;
         }
       if(i!=min)
         {
           temp=num[i];  
           num[i]=num[min];
           num[min]=temp;
         }
     }
}




//**********************************************************************************
//Shell Sort
void Shell_sort(int *num,int size)
{
   int i,j,inc,temp;//,count=0;
   for(inc=size/2;inc>0;inc/=2)
   {
     for(i=inc;i<size;i++)
     {
       temp=num[i];
       for(j=i-inc;(j>=0 && num[j]>temp);j=j-inc)
          { num[j+inc]=num[j];
          //  count=count+1;
          }
       num[j+inc]=temp;
     }
   }
  // printf("\n%d\n",count);
}



//**********************************************************************************
//Bubble Sort
void bubble_sort(int *num,int size)
{
   bool done=false;
   int i,j,k;
 // int count=0;
   for(i=0;(i<size) && (!done);i++)
      {
        done=true;
        for(j=0;j<size-i-1;j++)
           {
             if(num[j]>num[j+1])
               {
                 k=num[j+1];
                 num[j+1]=num[j];
                 num[j]=k;
              //   count++;
                 done=false;
               }
           }
   
      }
  // printf("\n %d \n",count);
} 



//**********************************************************************************
//Merge Sort
void merge_sort(int *num,int size)
{
   int *temparray;
   temparray=malloc( size * sizeof(int) );
   if(temparray!=NULL)  
   {
     msort(num,temparray,0,size-1);
     free(temparray);
   }
   else
     printf("\nThere is no space for temparray\n");
  
}        


void msort(int *num,int *temparray,int left,int right)
{
   int center;
   if(left<right)
   {
     center=(left+right)/2;
     msort(num,temparray,left,center);
     msort(num,temparray,center+1,right);      
     merge(num,temparray,left,center+1,right);
   }
}

void merge(int *num,int *temparray,int LP,int RP,int RE)
{
   int i,LE,numelements,temppos;
   LE=RP-1;
   temppos=LP;
   numelements=RE-LP+1;
   while( (LP<=LE) && (RP<=RE) )  
   {
     if(num[LP]<=num[RP])
        temparray[temppos++]=num[LP++];
     else
        temparray[temppos++]=num[RP++];
   }
   while( LP<=LE )
      temparray[temppos++]=num[LP++];
   while( RP<=RE )
      temparray[temppos++]=num[RP++]; 
   for(i=0;i<numelements;i++,RE--)
      num[RE]=temparray[RE];
}



//**********************************************************************************
//Quick Sort
void quick_sort(int *num,int size)
{
   Q_sort(num,0,size-1);
}


void Q_sort(int *num,int left,int right)
{
   int i,j;int pivot;
   if((left+cutoff)<right)    
   {
     pivot=median3(num,left,right);
     i=left;
     j=right-1;
     for(;;)    
     {
       while(num[++i]<pivot)
         {
         }
       while(pivot<num[--j])
         {
         }
       if(i<j)
         swap(&num[i],&num[j]);
       else 
         break;
     }
     swap(&num[i],&num[right-1]);
     Q_sort(num,left,i-1);
     Q_sort(num,i+1,right);     
   }
   else
     inst_sort((num+left),(right-left+1));
}


int median3(int *num,int left,int right)
{
   int center=(left+right)/2;
   if(num[left]>num[center])
        swap(&num[left],&num[center]);
   if(num[left]>num[right])
        swap(&num[left],&num[right]);
   if(num[center]>num[right])
        swap(&num[center],&num[right]);
   swap(&num[center],&num[right-1]);
   return num[right-1];
}


void swap(int *a,int *b)
{
   int c;
     c=*a;
    *a=*b;
    *b=c;
}


// ********************************************************************************
//Radix sort
void radix_sort(int *num,int size)
{
    Queue Q[10];
    int i,j,b,cnt,N,pos,max;
    max=num[0];
    for(i=0;i<10;i++)   
        Q[i]=create_queue();

    for(i=0;i<size;i++)	
      {
	      if(num[i]>max)
              max=num[i];
      }
    for(N=0;max>0;N++) 
      {
	    max=max/10;
      }
    for(b=1,cnt=1;cnt<=N;b*=10,cnt++)  
      {
	    for(i=0;i<size;i++) 
           {
	         pos=(num[i]/b)%10;
	         Q[pos] = Enqueue(num[i],Q[pos]);

	   }
	    j=0;
	    for(i=0;i<10;i++) 
           {
              while(!isempty(Q[i]))
                 {  num[j++]=Dequeue(Q[i]); }
				   
           }

      }


}      


Queue create_queue()
{
    Queue Q;
    Q=(Queue)calloc(1,sizeof(queue_node));
    return Q;
}


node * create_node()
{
    node * p;
    p=(node *)calloc(1,sizeof(node));
    if(p==NULL)
    {
	  printf("\n*******Sorry memory full*******\n");
  	  exit(1);
    }
    return p;
}    


Queue Enqueue(int x,Queue Q)
{
    node * t;
    t=create_node();
    t->data=x;
    t->next=NULL;
    if(Q->rear==NULL)
    {   
	 Q->front=Q->rear=t;
    }
else {
    (Q->rear)->next=t;
    Q->rear=t;
}
    return Q;
}




int  Dequeue(Queue Q)
{
     node * t;int a;
     if(Q==NULL)
           return 0;
     if(Q->front==Q->rear)
           Q->rear=NULL;
     t=Q->front;
     a=t->data;
     (Q->front)=(Q->front)->next;
     free(t);

     return a;
}



bool isempty(Queue Q)
{
     return Q->front==NULL;
}
		




void Heapsort(int *arr, int size)
{
	 int max;
	 buildheap(arr,size);
	 while(size>0)
	 {
			 max=delete_root(arr,&size);
			 arr[size+1]=max;
	 }
}



void buildheap(int *arr, int size)
{
	 int i;
	 for(i=size/2;i>=1;i--)
	 {
			 restoredown(arr,i,size);
	 }
}




int delete_root(int *arr, int*size)
{
	 int max;
	 max=arr[1];
	 arr[1]=arr[*size];
	 (*size)--;
	 restoredown(arr,1,*size);
	 return max;
}


void restoredown(int *arr , int i, int size)
{
	 int left,right,num;
	 left=(2*i);
	 right=(2*i)+1;
	 num=arr[i];
     while(right<=size)
	 {
		 if((num >= arr[left]) && (num >= arr[right]))
		 {
			 arr[i]=num;
			 return;
	     }
		 else if(arr[left]>arr[right])
		 {
			 arr[i]=arr[left];
			 i=left;
		 }
		 else
		 {
			 arr[i]=arr[right];
			 i=right;
		 }
		 left=(2*i);
		 right=(2*i)+1;
	 }
	 if((left == size) && (num <= arr[left]))
	 {
	     arr[i]=arr[left];
		 i=left;
	 }
	 arr[i]=num;
}




void display(int *arr, int size)
{
	 int i;
	 for(i=1;i<size;i++)
			{
			  printf("%d  ",arr[i]);
            }
	 printf("\n");		
}



void create_file(int c,int *a,int N)
{
 int i;
 FILE *in;
 switch(c)
 
  {
    case 1: RANDOM_NUMBERS(a,N);
            break;
    case 2: ASCENDING_ORDER(a,N);
            break;
    case 3: DESCENDIG_ORDER(a,N);
            break;
    case 4: SEME_NUMBERS(a,N);
              break;
    case 5:
           printf("\n\t\tThank you for using\n\t\tHave a nice dayyyyy!!! \n\n"); 
            exit(1);
   }
             
   if(c==1)
    {in=fopen("RANDOM","w");
     if(in==NULL)
      { printf("\nthere is no space\n");
        return ;
      }
     for(i=0;i<N;i++)
       fprintf(in,"%d\n",a[i]);
     fclose(in);
    }
   else if(c==2)
      {in=fopen("ASCENDING","w");
       if(in==NULL)
        { printf("\nthere is no space\n");
          return ;
        }
       for(i=0;i<N;i++)
          fprintf(in,"%d\n",a[i]);
     fclose(in);
      }
   else if(c==3)
      {in=fopen("DECENDING","w");
       if(in==NULL)
        { printf("\nthere is no space\n");
          return ;
        }
       for(i=0;i<N;i++)
         fprintf(in,"%d\n",a[i]);
     fclose(in);
      }
   else
      {in=fopen("SAME","w");
       if(in==NULL)
        { printf("\nthere is no space\n");
          return ;
        }
       for(i=0;i<N;i++)
         fprintf(in,"%d\n",a[i]);
       fclose(in);
      }
 return ;
}


void file_to_array(int c,int *a,int N)
{
   FILE *fi;
   int i;
   if(c==1)
      fi=fopen("RANDOM","r");                                          
     else if(c==2)                                                     
         fi=fopen("ASCENDING","r");                                    
       else if(c==3)
           fi=fopen("DECENDING","r");                                  
           else
             fi=fopen("SAME","r");                                     
        
    if(fi==NULL){  printf("File does not exist\n"); return ; }        
    for(i=0;i<N;i++)
     { fscanf(fi,"%d",&a[i]);}                                         
    fclose(fi);
}

void array_to_file(int *a,int i,int N,FILE *out)
{ 
 
    while(i<N)
    {
         fprintf(out,"%d\n",a[i]);                                                 
         i=i+1;                                                                    
    }         
}                                                                                    

void do_all_sortings(FILE *in,int *a,int c,int N)
{  
   
   int i;
   FILE *out;
   time_t start,stop;  

   // *********************************************************************************************************
   // BUBBLE-SORT
   file_to_array(c,a,N);
   start=clock();
   bubble_sort(a,N);
   stop=clock();
   out=fopen("BUBBLE-SORT","w");
   i=0;
   array_to_file(a,i,N,out);
   printf("\n The time taken for bubble sort is :");
   printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);

  fclose(out);
  

  // *********************************************************************************************************
  // SHELL-SORT

   file_to_array(c,a,N);
    start=clock();
   Shell_sort(a,N);
    stop=clock();
    out=fopen("SHELL-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for shell sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);
 
  // *********************************************************************************************************
  // INSERTION-SORT

   file_to_array(c,a,N);
   start=clock();
   inst_sort(a,N);
    stop=clock();
    i=0;
    out=fopen("INSERTION-SORT","w");
    array_to_file(a,i,N,out);
    printf("\n The time taken for insertion sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // MERGE-SORT

   file_to_array(c,a,N);
   start=clock();
   merge_sort(a,N);
    stop=clock();
    out=fopen("MERGE-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for meege sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);

 
   // *********************************************************************************************************
   // QUICK-SORT

    file_to_array(c,a,N);
    start=clock();
    quick_sort(a,N);
    stop=clock();
    out=fopen("QUICK-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for quick sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // SELECTION-SORT

   file_to_array(c,a,N);
    start=clock();
   selection_sort(a,N);
    stop=clock();
    out=fopen("SELECTION-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for selection sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // RADIX-SORT

   file_to_array(c,a,N);
   start=clock();
   radix_sort(a,N);
   stop=clock();
   out=fopen("RADIX-SORT","w");
   i=0;
   array_to_file(a,i,N,out);
   printf("\n The time taken for radix sort is :");
   printf(" %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
   fclose(out);

 
   // *********************************************************************************************************
   // HEAP-SORT

    file_to_array(c,a,N);
    start=clock();
    Heapsort(a,N);
    stop=clock();
    out=fopen("HEAP-SORT","w");
    i=1;
    array_to_file(a,i,N,out);
    printf("\n The time taken for heap sort is :");
    printf(" %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);

}


void file_to_array1(FILE *in,int *a,int N)
{
   FILE *fi;
   fi=fopen("inputfile","r");
   int i;
   if(fi==NULL){  printf("File does not exist\n"); return ; }
    for(i=0;i<N-1;i++)
     { fscanf(fi,"%d",&a[i]);}
    fclose(fi);


}
void do_all_sortings1(FILE *in,int *a,int N)
{
  
   int i;
   FILE *out;
   time_t start,stop;
   
     // *********************************************************************************************************
     // BUBBLE-SORT
 
  file_to_array1(in,a,N);
   start=clock();
   bubble_sort(a,N);
   stop=clock();
   out=fopen("BUBBLE-SORT","w");
   i=0;
   array_to_file(a,i,N,out);
   printf("\n The time taken for bubble sort is :");
   printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);

  fclose(out);

     // *********************************************************************************************************
     // SHELL-SORT

   file_to_array1(in,a,N);
    start=clock();
   Shell_sort(a,N);
    stop=clock();
    out=fopen("SHELL-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for shell sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


     // *********************************************************************************************************
     // INSERTION-SORT

   file_to_array1(in,a,N);
   start=clock();
   inst_sort(a,N);
    stop=clock();
    i=0;
    out=fopen("INSERTION-SORT","w");
    array_to_file(a,i,N,out);
    printf("\n The time taken for insertion sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // MERGE-SORT

  file_to_array1(in,a,N);
   start=clock();
   merge_sort(a,N);
    stop=clock();
    out=fopen("MERGE-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for merge sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // QUICK-SORT

    file_to_array1(in,a,N);
    start=clock();
    quick_sort(a,N);
    stop=clock();
    out=fopen("QUICK-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for quick sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


    // *********************************************************************************************************
    // SELECTION-SORT

   file_to_array1(in,a,N);
    start=clock();
   selection_sort(a,N);
    stop=clock();
    out=fopen("SELECTION-SORT","w");
    i=0;
    array_to_file(a,i,N,out);
    printf("\n The time taken for selection sort is :");
    printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


   // *********************************************************************************************************
   // RADIX-SORT

   file_to_array1(in,a,N);
   start=clock();
   radix_sort(a,N);
   stop=clock();
   out=fopen("RADIX-SORT","w");
   i=0;
   array_to_file(a,i,N,out);
   printf("\n The time taken for radix sort is :");
   printf(" %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
   fclose(out);

    // *********************************************************************************************************
    // HEAP-SORT

    file_to_array1(in,a,N);
    start=clock();
    Heapsort(a,N);
    stop=clock();
    out=fopen("HEAP-SORT","w");
    i=1;
    array_to_file(a,i,N,out);
    printf("\n The time taken for heap sort is :");
    printf(" %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
    fclose(out);


}



void BUBBLE_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;       

       start=clock();
       bubble_sort(b,count);
       stop=clock();
       out=fopen("BUBBLE-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for bubble sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}


void INSERTION_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
      inst_sort(b,count);
       stop=clock();
       out=fopen("INSERTION-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for insertion sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}




void SELECTION_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       selection_sort(b,count);
       stop=clock();
       out=fopen("SELECTION-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for selection sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}




void SHELL_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       Shell_sort(b,count);
       stop=clock();
       out=fopen("SHELL-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for shell sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}




void MERGE_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       merge_sort(b,count);
       stop=clock();
       out=fopen("MERGE-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for merge sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}


void QUICK_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       quick_sort(b,count);
       stop=clock();
       out=fopen("QUICK-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for quick sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}



void RADIX_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       radix_sort(b,count);
       stop=clock();
       out=fopen("RADIX-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for radix sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}




void HEAP_SORT(int *b,int count)
{

       int j;
       FILE *out;
       time_t start,stop;

       start=clock();
       Heapsort(b,count);
       stop=clock();
       out=fopen("HEAP-SORT","w");
       j=0;
       array_to_file(b,j,count,out);
       printf("\n The time taken for heap sort is :");
       printf("  %f sec\n",(float)(stop-start)/CLOCKS_PER_SEC);
       printf("\n****************************************************************\n");
       fclose(out);
       free(b);

}


void select_sorting_method(int e,int *a,int N)
{

                          switch(e)
                           {

                         case 1:
                              BUBBLE_SORT(a,N);
                              printf("\nTHE SORTED NUMBERS IN BUBBLE-SORT FILE\n ");
                              printf("\n   *** SAI RAM ***\n");
                              printf("\t[*_*]\n\n");

                              break;

                          case 2:
                              INSERTION_SORT(a,N);
                              printf("\nTHE SORTED NUMBERS IN INSERTION-SORT FILE\n ");
                              printf("\n   *** SAI RAM ***\n");
                              printf("\t[*_*]\n\n");

                              break;

                         case 3:
                                SELECTION_SORT(a,N);
                                printf("\nTHE SORTED NUMBERS IN SELECTION-SORT FILE\n ");
                                printf("\n   *** SAI RAM ***\n");
                                printf("\t[*_*]\n\n");

                                break;

                         case 4:
                                SHELL_SORT(a,N);
                                printf("\nTHE SORTED NUMBERS IN SHELL-SORT FILE\n ");
                                printf("\n   *** SAI RAM ***\n");
                                printf("\t[*_*]\n\n");

                                break;

                         case 5:
                                MERGE_SORT(a,N);
                                printf("\nTHE SORTED NUMBERS IN MERGE-SORT FILE\n ");
                                printf("\n   *** SAI RAM ***\n");
                                printf("\t[*_*]\n\n");

                                break;

                         case 6:
                                 QUICK_SORT(a,N);
                                 printf("\nTHE SORTED NUMBERS IN QUICK-SORT FILE\n ");
                                 printf("\n   *** SAI RAM ***\n");
                                 printf("\t[*_*]\n\n");

                                   break;

                        case 7:
                                RADIX_SORT(a,N);
                                printf("\nTHE SORTED NUMBERS IN RADIX-SORT FILE\n ");
                                printf("\n   *** SAI RAM ***\n");
                                printf("\t[*_*]\n\n");

                                break;
                        case 8:
                                HEAP_SORT(a,N);
                                printf("\nTHE SORTED NUMBERS IN HEAP-SORT FILE\n ");
                                printf("\n   *** SAI RAM ***\n");
                                printf("\t[*_*]\n\n");
                                break;
                        case 9: 
                                printf("\n\t\tThank you for using\n\t\tHave a nice dayyyyy!!! \n\n");
                                exit(1);
                                break;
                        }

}



