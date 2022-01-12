#include <stdio.h>
int main()
{
   int heap[10], array_size, i, j, c, root, temporary;
   printf("\n Enter size of array to be sorted :");
   scanf("%d", &array_size);
   printf("\n Enter the elements of array : ");
   for (i = 0; i < array_size; i++)
      scanf("%d", &heap[i]);
   for (i = 1; i < array_size; i++)
   {
       c = i;
       do
       {
           root = (c - 1) / 2;            
           if (heap[root] < heap[c])   /* to create MAX heap array */
           {                                  // if child is greater than parent swap them
               temporary = heap[root];      // as structure is of complete binary tree
               heap[root] = heap[c];     // it took logn steps to reach from root to leaf
               heap[c] = temporary;
           }
           c = root;
       } while (c != 0);
   }
   printf("Heap array : ");
   for (i = 0; i < array_size; i++)
       printf("%d\t ", heap[i]);         //printing the heap array
   for (j = array_size - 1; j >= 0; j--)
   {
       temporary = heap[0];
       heap[0] = heap[j] ;   /* swap max element with rightmost leaf element */
       heap[j] = temporary;
       root = 0;
       do
       {
           c = 2 * root + 1;    /* left node of root element */
           if ((heap[c] < heap[c + 1]) && c < j-1)
               c++;
           if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
           {
               temporary = heap[root];
               heap[root] = heap[c];
               heap[c] = temporary;
           }
           root = c;
       } while (c < j);
   }
   printf("\n The sorted array is : ");
   for (i = 0; i < array_size; i++)
      printf("\t %d", heap[i]);
}
