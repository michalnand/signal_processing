ELF = bin/generate_signal.elf

#NN_LIBS_PATH=$(HOME)/libs/rysy
#DQN_LIBS_PATH=$(HOME)/libs/deep_q_network

INC+= -I.
INC+= -I../libs
INC+= -I$(DQN_LIBS_PATH)/libs_dqn
INC+= -I$(NN_LIBS_PATH)/libs_common
INC+= -I$(NN_LIBS_PATH)/libs_dataset
INC+= -I$(NN_LIBS_PATH)/libs_nn
INC+= -I$(NN_LIBS_PATH)/libs_experiment
INC+= -I$(NN_LIBS_PATH)/libs_preprocessing

LIBS+= ../libs/libs_sp.a
LIBS+= $(DQN_LIBS_PATH)/libs_dqn/libs_dqn.a
LIBS+= $(NN_LIBS_PATH)/libs_experiment/libs_experiment.a
LIBS+= $(NN_LIBS_PATH)/libs_dataset/libs_dataset.a
LIBS+= $(NN_LIBS_PATH)/libs_nn/libs_nn.a
LIBS+= $(NN_LIBS_PATH)/libs_common/libs_common.a
LIBS+= $(NN_LIBS_PATH)/libs_preprocessing/libs_preprocessing.a

CC = g++
CU = nvcc
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -s -Wall -Wextra -pedantic -std=c++17 $(INC)
CUDAFLAGS = -O3 -D_FORCE_INLINES -ccbin=$(CXX) -Xcompiler -fPIC -std=c++11 $(INC)

LDFLAGS = $(DEGUBFLAGS) -lstdc++fs -lm -lpthread -pthread -std=c++17 -lglut -lGL -lGLU -lX11 -ljsoncpp -L/usr/local/cuda/lib64 -lcuda -lcudart


SRCS+= $(shell find -name '*.cpp')
SRCS_CUDA+= $(shell find -name '*.cu')


OBJS = $(SRCS:.cpp=.o)
OBJS_CUDA = $(SRCS_CUDA:.cu=.oc)

all: $(ELF)
	$(SIZE) $(ELF)

$(ELF): $(LIBS) $(OBJS) $(OBJS_CUDA)
	$(LD) -o $@ $(OBJS) $(OBJS_CUDA) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

%.oc: %.cu
	$(CU) -c $(CUDAFLAGS) $< -o $@

clean:
	rm $(OBJS) -rf
	rm $(OBJS_CUDA) -rf
	rm $(ELF) -rf
