# vocabulary.mk

OBJS = graph.o vocabulary.o stringNodeId.o word.o main.o
CC = g++
CFLAGS = -std=c++11 -c
LFLAGS = -s

# $@ - the target of this rule
# $^ - all prerequisites of this rule
vocabulary : $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

vocabulary.o : vocabulary.cpp vocabulary.h graph.h node.h nodeId.h stringNodeId.h word.h
	$(CC) $(CFLAGS) vocabulary.cpp

stringNodeId.o : stringNodeId.cpp stringNodeId.h nodeId.h
	$(CC) $(CFLAGS) stringNodeId.cpp

graph.o : graph.cpp graph.h node.h nodeId.h
	$(CC) $(CFLAGS) graph.cpp

word.o : word.cpp word.h
	$(CC) $(CFLAGS) word.cpp

main.o : main.cpp vocabulary.h graph.h node.h nodeId.h stringNodeId.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
