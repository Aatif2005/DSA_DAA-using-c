#include <stdio.h>
#include <stdlib.h>

struct myArray
{
   int total_size;
   int used_size;
   int*ptr;  // ye Pahle elemnt of array ko point kre ga
};

void createAarray(struct myArray*a, int tSize, int uSize) {
   //(*a).total_size = tSize;
   //(*a).used_size = uSize;
  //(*a).ptr = (int *) malloc(tSize*sizeof(int));

  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = (int*)malloc(tSize*sizeof(int));

}

void show(struct myArray *a) {
   for (int i = 0; i < a->used_size; i++) {
     printf("%d ", a->ptr[i]);
   }
}

void setVal(struct myArray*a) {
   int n;
    for (int i = 0; i < a->used_size; i++) {
    scanf_s("%d", &n);
    (a->ptr)[i] = n;
   }
}
int main() {
   struct myArray marks;
   createAarray(&marks, 10, 2);
   printf("we are running setValue now\n");
   setVal(&marks);

   printf("We are running show now\n");
   show(&marks);

   return 0;
}