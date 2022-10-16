CFLAG = -c -fPIC

TARGET = casino

OBJECT = game.o main.o

all: $(OBJECT)
	$(CXX) $(CXXFLAGS) -O $(OBJECT) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -O $(CFLAG) $< -o $@

clean:
	rm -rf $(OBJECT) $(TARGET)
