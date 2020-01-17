// AUM SRI SAI RAM
// C PROJECT ON SORTING
// By:A.SeshaSai   
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include"time.h"
int main(int rc , char *rv[])
{
   int N, count=0,p,*b,j,e;
   char c;
   FILE *in,*out;
   time_t start,stop;
   system("clear");
   
 if(rc==2)
 {
                  in=fopen(rv[1],"r");
                   {
                     if(in==NULL)
                      { printf("\nSORRY!!! Input file does not exist\n");
                        return 0;
                      }
                   }
                  if(fgetc(in) == EOF)
                  {
                       printf("\n   ->SORRY!!!\n   ->There is no elements in input file\n\n");
                       return 0;
                  }
                  while((c=fgetc(in))!=EOF)    // COUNTING THE NUMBER FO ELEMENTS IN THE INPUT FILE
		    { 
      		      if(c=='\n')
    		          count++;
   
                    }
		  rewind(in);
                  printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
                  printf("\nThe number of elements are in the given input file is :\n");
                  printf("\n%d\n",count);
                  printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
                  b=malloc(count*sizeof(int));
                  
		  for(j=0;j<count;j++)
		      {
                           fscanf(in,"%d",&b[j]);
                      }
 
      		  fclose(in);
     	        do{ 
                  printf("\n\tIF YOU WANT TO SORT IN A SPECIFIC SORTING METHOD, PRESS:1\n\n\tIF YOU WANT TO SORT IN ALL SORTING METHODS, PRESS:2\n\n\tIf you want to exit,  press:3\n");
		  scanf(" %d",&p);}while(p>3);
	         if(p==1)
		    {      printf("\n*********************************************************************************\n");
                      do{
			   printf("\t\n1:Bubble sort\n2:Insertion sort\n3:Selection sort\n4:Shellsort\n5:Merge sort\n6:Quick sort\n7:Radix sort\n8:Heap sort\n9.exit\n");
                           printf("\nEnter your option:\n"); 
                           scanf("%d",&e);
                        }while(e>9);
                           printf("\n*********************************************************************************\n");
                           select_sorting_method(e,b,count);                   
                    }
                   if(p==2)
                    { printf("\n********************************************************************************\n");  
                      do_all_sortings1(in,b,count);
                  printf("\n**'THE SORTED NUMBERS AER IN BUBBLE-SORT,SHELL-SORT,INSERTION-SORT,MERGE-SORT,QUICK-SORT,SELECTION-SORT,RADIX-SORT,HEAP-SORT FILES'**\n");
                      printf("\n\t\tThank you for using\n\t\tHave a nice dayyyyy!!! \n\n");
                      printf("\t[*_*]\n\n");
                      printf("\n********************************************************************************\n");
  	    
                    }			
                   if(p==3)
                    {
                        printf("\n\t\tThank you for using\n\t\tHave a nice dayyyyy!!! \n\n");
                        return 0;
                    }					      
   }				      
			  	 
if(rc==1) 
{
   int *a,i=0,n,c;
     printf("\n\tThere is no input file given\n");

     printf("\n Please enter how many numbers do you want to sort\n");
     scanf("%d",&N);
     if(N==0)
     {
        printf("\n   ->Sorry!!!\n   ->The generatingfile does not contain any elements\n\n");
        return 0;
     }
   a=malloc((N)*sizeof(int));
   if(a==NULL)
    {
      printf("\nthere is no space\n");
    return 0;
    }
    do{
   
       printf("\nIf you want RANDOM numbers, press:1\nIf you want ASCENDING ORDER, press:2\nIf you want DECENDING ORDER, press:3\nIf you want SAME numbers, press:4\n If you want to exit, press:5\n");
       scanf("%d",&c);
       create_file(c,a,N);
     }while(c>5);
     do{
         printf("\n\tIF YOU WANT TO SORT IN A SPECIFIC SORTING METHOD, PRESS:1\n\n\tIF YOU WANT TO SORT IN ALL SORTING METHODS, PRESS:2\n\n\tIf you want to exit, press:3\n"); 
         scanf("%d",&p);
       }while(p>3);
     if(p==1)
         {       printf("\n*********************************************************************************\n");
             do{   
                 printf("\t\n1:Bubble sort\n2:Insertion sort\n3:Selection sort\n4:Shellsort\n5:Merge sort\n6:Quick sort\n7:Radix sort\n8:Heap sort\n9.exit\n");
                 printf("\nEnter your option:\n");
                 scanf("%d",&e);
               }while(e>9);
                 printf("\n*********************************************************************************\n");               
                 select_sorting_method(e,a,N); 
         }      
                   
     if(p==2)
	 {   
	     printf("\n********************************************************************************************************************\n");
	     do_all_sortings(in,a,c,N); 
             printf("\n**'THE SORTED NUMBERS AER IN BUBBLE-SORT,SHELL-SORT,INSERTION-SORT,MERGE-SORT,QUICK-SORT,SELECTION-SORT,RADIX-SORT,HEAP-SORT FILES'**\n");
             printf("\n\t\tThank you for using\n\t\tHave a nice dayyyyy!!! \n\n");
	     printf("\t[*_*]\n\n");   
	     printf("\n*********************************************************************************************************************\n");
	 }
     if(p==3)
       {
            printf("\n\t\tThank you for using \n\t\tHave a nice dayyyyy!!! \n\n");
            return 0;
       }
}   
      return 0;
}







