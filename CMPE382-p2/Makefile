myprogram: libmem.so mem.o mem.h
	gcc mymain.c mem.c -lmem -L. -o myprogram
        setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:/mnt/c/Users/NEW/Desktop/CMPE382-PROJECT2/libmem.so

libmem.so: mem.o mem.h
	gcc -shared -o libmem.so mem.o


mem.o: mem.c mem.h
	gcc -c -fPIC mem.c


