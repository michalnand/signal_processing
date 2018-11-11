OUTPUT_NAME = libs_sp

#NN_LIBS_PATH=$(HOME)/libs/rysy
#DQN_LIBS_PATH=$(HOME)/libs/deep_q_network

INC+= -I.
INC+= -I$(DQN_LIBS_PATH)/libs_dqn
INC+= -I$(NN_LIBS_PATH)/libs_common
INC+= -I$(NN_LIBS_PATH)/libs_dataset
INC+= -I$(NN_LIBS_PATH)/libs_nn
INC+= -I$(NN_LIBS_PATH)/libs_experiment



SRCS+= $(shell find . -name '*.cpp')

CC = g++
CU = nvcc
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size
ARCHIVE = ar

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -fPIC -s -Wall -Wextra -pedantic -std=c++17 $(INC)

OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)
	$(ARCHIVE) rc $(OUTPUT_NAME).a $(OBJS)
	$(CC) -shared -fPIC -o $(OUTPUT_NAME).so $(OBJS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm $(OBJS) -rf
	rm $(OUTPUT_NAME).* -rf
