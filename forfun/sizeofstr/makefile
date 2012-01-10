TARGET=$(shell basename `pwd`)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)

all: $(TARGET)

$(OBJECTS): $(SOURCES)

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(LDFLAGS) $(OBJECTS) $(LOADLIBES) $(LDLIBS)

clean:
	$(RM) $(OBJECTS) $(TARGET)

x86:
	g++ sizeofstr.cpp -o testx86 -m32


.PHONY: all clean
