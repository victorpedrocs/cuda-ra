all: cpu gpu

READER = util.o readers.o main.o 
DEBUG = -g -pg
LFLAGS = $(DEBUG)
CFLAGS = -c $(DEBUG) $(OPTFLAGS)
NVCCFLAGS   = $(CFLAGS) -gencode arch=compute_11,code=sm_11

CC = g++
NVCC = nvcc

#############################

H_FILES     = 	base/util.h base/readers.h 		\
				base/relation.h base/catalog.h	\
				operators/projection.h

CPU_SRC     = 	base/util.cpp base/readers.cpp 		\
				base/relation.cpp base/catalog.cpp	\
				operators/projection.cpp main.cpp

GPU_SRC     = 	base/util.cpp base/readers.cpp 		\
				base/relation.cpp base/catalog.cpp	\
				operators/projection.cu main.cpp

CPU_OBJ_TEST = 	cpu_util.o cpu_readers.o 		\
				cpu_relation.o cpu_catalog.o 	\
				cpu_main.o cpu_projection.o cpu_wtime.o

GPU_OBJ_TEST = 	gpu_util.o gpu_readers.o 		\
				gpu_relation.o gpu_catalog.o	\
				gpu_main.o gpu_projection.o gpu_wtime.o

CPU_OBJ     = $(CPU_SRC:%.c=%.o)
$(CPU_OBJ): $(H_FILES)

GPU_OBJ     = $(GPU_SRC:%.c=%.o)
$(GPU_OBJ): $(H_FILES)

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

cpu: seq_main
gpu: cuda_main

cuda_main: $(GPU_OBJ)
	$(NVCC) $(LFLAGS) -o cuda $(GPU_OBJ)

seq_main: $(CPU_OBJ) $(H_FILES)
	$(CC) $(LFLAGS) -o cpu $(CPU_OBJ)

cpu_test: $(CPU_OBJ_TEST)
	$(CC) $(LFLAGS) $(CPU_OBJ_TEST) -o cpu

gpu_test: $(GPU_OBJ_TEST)
	$(NVCC) $(LFLAGS) -o cuda $(GPU_OBJ_TEST)


