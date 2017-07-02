HFILES=Functions.h Network.h Neuron.h RandomGen.h
CPPFILES=$(HFILES:.h=.cpp) main.cpp
OBJFILES=$(CPPFILES:.cpp=.o)
CXX=g++
FLAGS=-g3 -std=c++11

all: $(OBJFILES)
	echo $(OBJFILES)
	$(CXX) $(OBJFILES) $(FLAGS) -o prog 

%.o: %.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	rm *.o
