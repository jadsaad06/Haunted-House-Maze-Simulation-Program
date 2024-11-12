CC = g++
FLAGS = -std=c++17 -g -Wall

SOURCES = main.cpp attendees.cpp attractions.cpp dataStructures.cpp
OBJS = $(SOURCES:.cpp=.o)

DEPS = attendees.h attractions.h dataStructures.h

%.o: %.cpp $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJS) main
