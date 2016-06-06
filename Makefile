all: cpu gpu

CPU_OBJ = 	util.o readers.o 		\
			relation.o catalog.o 	\
			main.o cpu_projection.o

GPU_OBJ = 	util.o readers.o 		\
			relation.o catalog.o	\
			main.o gpu_projection.o

READER = util.o readers.o main.o 
DEBUG = -g -pg
LFLAGS = $(DEBUG)
CFLAGS = -c $(DEBUG) $(OPTFLAGS)
NVCCFLAGS   = $(CFLAGS) --ptxas-options=-v -gencode arch=compute_11,code=sm_11


CC = g++
NVCC = nvcc

#############################

util.o : base/util.h base/util.cpp
	$(CC) $(CFLAGS) base/util.cpp

readers.o : base/readers.h base/readers.cpp
	$(CC) $(CFLAGS) base/readers.cpp

relation.o : base/relation.h base/relation.cpp
	$(CC) $(CFLAGS) base/relation.cpp

catalog.o : base/catalog.h base/catalog.cpp
	$(CC) $(CFLAGS) base/catalog.cpp

cpu_projection.o : operators/projection.h operators/projection.cpp
	$(CC) $(CFLAGS) operators/projection.cpp -o $@

gpu_projection.o : operators/projection.h operators/projection.cu
	$(NVCC) $(NVCCFLAGS) operators/projection.cu -o $@

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

#############################

clean:
	\rm -rf *.o cpu cuda base/*.o operators/*.o

cpu: $(CPU_OBJ)
	$(CC) $(LFLAGS) $(CPU_OBJ) -o cpu

gpu: $(GPU_OBJ)
	$(NVCC) $(LFLAGS) $(GPU_OBJ) -o cuda