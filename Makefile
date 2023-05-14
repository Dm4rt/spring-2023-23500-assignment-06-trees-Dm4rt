OBJECTS=main.o BSTree.o Node.o
TEST_OBJECTS=tests.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
tests: $(TEST_OBJECTS)
	g++ -o tests $(TEST_OBJECTS)
BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

tests.o: tests.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)
