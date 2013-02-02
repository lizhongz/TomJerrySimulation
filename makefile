CC=g++
CFLAGS='-g'
INFLAGS=-I./
LDFLAGS=
SOURCES=main.cc Coordinate.cc Agent.cc Animal.cc Mouse.cc Cheese.cc Cat.cc Obstacle.cc AgentManager.cc mt19937ar.cc 
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) -c $(INFLAGS) $(CFLAGS) $< -o $@

clean:
	-rm -f $(EXECUTABLE) $(OBJECTS)
