#include<stdio.h>
#include "mem.h"



int global_size = 0;
int free_size = 0;

void TEDU_split(struct block *fitting_slot,size_t size){

 struct block *new_block=(void*)((void*)fitting_slot+size);
 new_block->size=(fitting_slot->size)-size;
 new_block->free=1;
 new_block->next_block=fitting_slot->next_block;
 fitting_slot->size=size;
 printf("%ld bytes allocated in to the memory\n",fitting_slot->size);
 fitting_slot->free=0;
 fitting_slot->next_block=new_block;
}

struct block *memory = NULL;
struct block *nul = NULL;
void Mem_Init(int sizeOfRegion)
{

        global_size = sizeOfRegion;
        char init[sizeOfRegion];
        free_size = sizeOfRegion;
        memory = (struct block*)init;
        memory->size = sizeOfRegion;
        memory->free = 1;
        memory->next_block = NULL;
        memory->init = 1;
}



struct block TEDU_alloc(size_t byte_size)
{
        struct block * current_block ;
        struct block * prev_block;

    //printf("memory starting byte %ld\n",memory->size);
    current_block = memory;
    while((((current_block->size)<byte_size)||((current_block->free)==0))&&(current_block->next_block!=NULL))
    {
      prev_block=current_block;
      current_block=current_block->next_block;
      //printf("1 block passed\n");
    }

    //printf("first fit tamamlandi %ld\n",current_block->size);

    if((current_block->size)==byte_size)
    {
        //printf("esit\n");
        current_block->free = 0;
        struct block *ptr = current_block++;
        struct block temp = *ptr;
        return temp;
    }
    else if((current_block->size)>byte_size)
    {
        //printf("alan > gelen \n");
        TEDU_split(current_block,byte_size);
        struct block *ptr = current_block++;
        struct block temp = *ptr;
        return temp;

    }
    else
    {

        printf("No allocated space found!\n");
        // bug & problem

    }



}



int Mem_GetSize(struct block *ptr)
{
    struct block test = *ptr;
    if(Mem_IsValid(ptr)==1)
    {
    printf("Allocated size of this pointer : %ld\n",test.size);
    }
    else
    {
        printf("This pointer has not been allocated\n");

    }

}


void TEDU_merge(){
 struct block *curr,*prev;
 curr=memory;
 while(curr &&curr->next_block!=NULL){
  if((curr->free) && (curr->next_block->free)){
   curr->size+=(curr->next_block->size);
   curr->next_block=curr->next_block->next_block;
  }
  prev=curr;
  curr=curr->next_block;
 }
}

int TEDU_Free(struct block *ptr)
{
      printf("Program is trying to deallocate %ld bytes from the memory",ptr->size);
     if((memory<=ptr)&&(ptr<=(memory+global_size))){

        struct block* curr=ptr;
        curr->free=0;
        --curr;
        TEDU_merge();
        }
        else{
            printf("Please provide a valid pointer allocated by MyMalloc\n");
        }
}

int TEDU_GetStats()
{
    int full_size = 0;
    int i = 0;
    struct block *curr = memory;
    while(curr->next_block != NULL)
    {
            full_size += curr->size;
            i++;
            curr = curr->next_block;
    }
    printf("\n---Summary of our memmory---\n");
    printf("Empty Byte Space :%ld\nFilled Byte Size: %d\nNumber Of Allocated Size: %d\n",curr->size,full_size,i);
    curr = memory;
    int a = 1;
    while(a<i+1)
    {

            if(a==1 || ((a>20) && (a%10 == 1)))
            {
            printf("%d'st allocated space is %ld\n",a,curr->size);
            }
            else if(a==2 || ((a>20) && (a%10 == 2)))
            {
            printf("%d'nd allocated space is %ld\n",a,curr->size);
            }
            else if(a==3 || ((a>20) && (a%10 == 3)))
            {
            printf("%d'rd allocated space is %ld\n",a,curr->size);
            }
            else
            {
            printf("%d'th allocated space is %ld\n",a,curr->size);
            }


        a++;
        curr = curr->next_block;

    }

}

int Mem_IsValid(struct block *ptr)
{
    if(ptr->size <500000 && ptr->size>0)
    {
    return 1;
    }
    else
    {
    return 0;
    }
}




