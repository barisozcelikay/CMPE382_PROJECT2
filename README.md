# CMPE382_PROJECT2
## Project-2 : Creating TEDU_alloc
### Kadir Kaan Yazgan - Barış Özçelikay


#### Work dividing and information:
Project Partners: Barış Özçelikay, Kadir Kaan Yazgan\
\
First, we did a separate research to decide with which algorithm we want to develop the project. Baris while researching about the first fitting algorithm, Kaan researched the best fit algorithm. After the researches, we decided that the first fitting logic would be more appropriate and we planned our code around this algorithm. After this stage, we developed our code by working jointly on the Discord program. Apart from that, we also used github. As a result, we cannot say that we have divided the homework into two because we both took part in every stage of the project.

#### Design overview:
Our goal in this project is to design our own memory allocation. There are mem.c, mem.h, mymain.c files in the project. We have also created a dynamic library called libmem.so. Because of this dynamic library we can added/loaded at runtime. We also created the Makefile file to run the project. With this file, we have made it possible to run multiple files (mem.c, mymain.c, mem.h) with a single command. To run this file, first you need type to shell "make".  Then you can run the project with the "./myprogram" command.

![Screenshot_1](https://user-images.githubusercontent.com/82260968/118028523-d6b52380-b36b-11eb-86dd-30b8f3230310.png)\
From four different fitting algorithms in this project. We decided to make the First Fitting algorithm. Because we aware that this method is faster and more effective on memories that are not very large compared to others. We developed our code in accordance with this algorithm.

#### Complete specification:

We wanted to create a virtual memory in order to use these allocations in the project and we created this with the Mem_Init() function. This function is created up to size of bytes entered by the user and this number is assigned as virtual memory size. We have created two more functions to perform operations on the memory we created with the Mem_Init () function. These are TEDU_alloc () and TEDU_free () functions.\

We have defined TEDU_alloc () function as a function that returns a struct. In order to test the value received from the user whenever we call each function to find the fields, we started the memory from the starting address and checked the next element of the block that was filled until the first suitable field was found and added it to the empty and appropriate place. With split () function, we have ensured that the next block is defined as empty. In the TEDU free () function, we free up and restore the memory we created with the TEDU_alloc() function. In this way, we free up the used memory again and make it usable.\

We also made our code more useful and efficient by creating Mem_GetSize (), Mem_isValid (), TEDU_GetStats () functions. The Mem_GetSize () function takes a sturct parameter and prints the size, if not, it prints an error message. The TEDU_GetStats () function prints a summary of the data used in the program.( Total memory, Empty byte space,  How many times using the allocation and every allocation byte size).Mem_isValid() function we use it to control  allocated  pointer is valid or not. This function facilitate our work in Mem_GetSize() function also.

#### Our Thoughts:
In our program, we were able to create the address of a value and then use that address in the TEDU_alloc () function where we initiliazed it with the Mem_Init () function. Unfortunately, we have not been able to get our TEDU_free () function working exact properly. TEDU_alloc () işlevinde oluşturduğumuz bellek düzenlemesini TEDU_free () işlevi için kullanamadık. Apart from that, we succeeded in adding dynamic library to our project and creating a Makefile. In general, we learned the memory management logic, but we could not show it exactly in the code.

#### Known bugs and problems:

- If the memory to be added is the same as the defined memory, it will give you an error.
- TEDU_free () function does not work properly.
- If the number of bytes sent is not 3 digits, only the first assigned byte number is used when performing multiple allocate operations.
- In our program, alloc works only for one value, and if the same value is called with a different tedu alloc, it may give a wrong result.
- You cannot initialize memory bigger than 50.000 bytes.












