all: cpu gpu

READER = util.o readers.o main.o 
DEBUG = -g -pg
LFLAGS = $(DEBUG)
CFLAGS = -c -std=c++11 -o $(DEBUG) $(OPTFLAGS)
NVCCFLAGS   = $(CFLAGS) -gencode arch=compute_11,code=sm_11

CC = clang++
NVCC = nvcc

#############################

CPU_OBJ = 	cpu_util.o cpu_readers.o 			\
				cpu_relation.o cpu_catalog.o 	\
				cpu_main.o cpu_projection.o cpu_wtime.o

GPU_OBJ = 	gpu_util.o gpu_readers.o 			\
				gpu_relation.o gpu_catalog.o	\
				gpu_main.o gpu_projection.o gpu_wtime.o

# GPU OBJS 
###########
cpu_util.o : base/util.h base/util.cpp
	$(CC) $(CFLAGS) base/util.cpp -o $@

cpu_readers.o : base/readers.h base/readers.cpp
	$(CC) $(CFLAGS) base/readers.cpp -o $@

cpu_relation.o : base/relation.h base/relation.cpp
	$(CC) $(CFLAGS) base/relation.cpp -o $@

cpu_catalog.o : base/catalog.h base/catalog.cpp
	$(CC) $(CFLAGS) base/catalog.cpp -o $@

cpu_projection.o : operators/projection.h operators/projection.cpp
	$(CC) $(CFLAGS) operators/projection.cpp -o $@

cpu_main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp -o $@

cpu_wtime.o: wtime.h wtime.cpp
	$(CC) $(CFLAGS) wtime.cpp -o $@

# GPU OBJS 
###########
gpu_util.o : base/util.h base/util.cpp
	$(NVCC) $(CFLAGS) base/util.cpp -o $@

gpu_readers.o : base/readers.h base/readers.cpp
	$(NVCC) $(CFLAGS) base/readers.cpp -o $@

gpu_relation.o : base/relation.h base/relation.cpp
	$(NVCC) $(CFLAGS) base/relation.cpp -o $@

gpu_catalog.o : base/catalog.h base/catalog.cpp
	$(NVCC) $(CFLAGS) base/catalog.cpp -o $@

gpu_projection.o : operators/projection.h operators/projection.cu
	$(NVCC) $(NVCCFLAGS) operators/projection.cu -o $@

gpu_main.o : main.cpp
	$(NVCC) $(CFLAGS) main.cpp -o $@

gpu_wtime.o: wtime.h wtime.cpp
	$(NVCC) $(CFLAGS) wtime.cpp -o $@

#############################

clean:
	\rm -rf *.o cpu cuda base/*.o operators/*.o

cpu: $(CPU_OBJ)
	$(CC) $(LFLAGS) $(CPU_OBJ) -o cpu

gpu: $(GPU_OBJ)
	$(NVCC) $(LFLAGS) -o cuda $(GPU_OBJ)


