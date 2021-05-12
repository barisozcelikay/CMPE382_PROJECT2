#include<stdio.h>
#include<stdlib.h>
#include "mem.h"




int main()
{


        int size_of_region;
        printf("Enter size of Region: ");
        scanf("%d",&size_of_region);
        Mem_Init(size_of_region);

        int size_of_allocation;
        struct block s = TEDU_alloc(25 * sizeof(int));
        struct block *s_ptr = &s;

        struct block m = TEDU_alloc(300*sizeof(struct block));
        struct block *m_ptr = &m;
        struct block b = TEDU_alloc(50*sizeof(char));
        struct block *b_ptr = &b;
        struct block v ;
        struct block *v_ptr = &v;


        Mem_GetSize(m_ptr);
        TEDU_Free(b_ptr);



        int valid2 = Mem_IsValid(v_ptr);
        if(Mem_IsValid(m_ptr) == 1)
        {
            printf("\nThis pointer is valid in memory");
        }
        else
        {
            printf("\nThis pointer is not valid in memory");
        }
        TEDU_GetStats();



/*
        struct block kaan = TEDU_alloc(11000);
        struct block *kaan_ptr = &kaan;
        Mem_GetSize(kaan_ptr);
        //mymemory();
        /*
        struct block baris = TEDU_alloc(11000);
        struct block *baris_ptr = &baris;
    */
/*
        struct block a = TEDU_alloc(2000);
        struct block *a_ptr = &a;
        mymemory();
        //

  */      /*TEDU_Free(kaan_ptr);
        TEDU_Free(baris_ptr);
*/

         //

        //struct block baris = TEDU_alloc(100);
        //struct block *baris_ptr = &baris;
        // ;
        //Mem_GetSize(s_ptr);
        //TEDU_Free(s_ptr);


    return 0;
}
