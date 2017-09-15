HFILES=Functions.h Network.h Neuron.h RandomGen.h NetworkOptions.h Layer.h Population.h Chromosome.h FileManagement.h
CPPFILES=$(HFILES:.h=.cpp) main.cpp
OBJFILES=$(CPPFILES:.cpp=.o)
CXX=g++
FLAGS=-std=c++11 -fopenmp -Ofast

all: $(OBJFILES)
	$(CXX) $(OBJFILES) $(FLAGS) -o prog 

%.o: %.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	rm *.o
