EIGEN_INC_DIR=../eigen
DCO_INC_DIR=../dco/include 
DCO_LIB_DIR=../dco/lib
DCO_LIB=dcoc

DCO_FLAGS=-DDCO_DISABLE_AUTO_WARNING -DDCO_CHUNK_TAPE -DDCO_EXT_EIGEN_IGNORE_VERSION -DDCO_NO_INTERMEDIATES -DDCO_DISABLE_AVX2_WARNING

EIGEN_FLAGS=-DEIGEN_STACK_ALLOCATION_LIMIT=0

CPPC=g++
CPPC_FLAGS=-Wall -Wextra -pedantic -O3 

DIM=25
N_STEPS=1000
R_PREC=1e-15

all: Alg3.1.exe Alg3.2.exe Alg3.3.exe

Alg3.1.exe : Alg3.1.cpp F.h Euler.h main.h
	$(CPPC) -I$(EIGEN_INC_DIR) -I$(DCO_INC_DIR) $(DCO_FLAGS) $(EIGEN_FLAGS) $(CPPC_FLAGS) -DDIM=$(DIM) -DN_STEPS=$(N_STEPS) -DR_PREC=$(R_PREC) $< -o $@ -L$(DCO_LIB_DIR) -l$(DCO_LIB)
	./Alg3.1.exe > Alg3.1.out

Alg3.2.exe : Alg3.2.cpp F.h Euler.h main.h
	$(CPPC) -I$(EIGEN_INC_DIR) $(EIGEN_FLAGS) $(CPPC_FLAGS) -DDIM=$(DIM) -DN_STEPS=$(N_STEPS) -DR_PREC=$(R_PREC) $< -o $@ 
	./Alg3.2.exe > Alg3.2.out

Alg3.3.exe : Alg3.3.cpp F.h Euler.h main.h
	$(CPPC) -I$(EIGEN_INC_DIR) $(EIGEN_FLAGS) $(CPPC_FLAGS) -DDIM=$(DIM) -DN_STEPS=$(N_STEPS) -DR_PREC=$(R_PREC) $< -o $@ 
	./Alg3.3.exe  > Alg3.3.out

clean:
	rm -f *.exe *.out

PHONY: all clean
