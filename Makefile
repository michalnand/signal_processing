NN_LIBS_PATH=$(HOME)/libs/rysy
DQN_LIBS_PATH=$(HOME)/libs/deep_q_network

export NN_LIBS_PATH
export DQN_LIBS_PATH
 

all:
	cd libs && make -j4
	cd test && make -j4
	

clean:
	cd libs && make clean
	cd test && make clean
	
