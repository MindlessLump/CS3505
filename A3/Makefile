CC = g++
CFLAGS = -Wall -std=c++11

INCLUDE = -I./

TrieTest: TrieTest.o ./Trie.h Trie.o ./Node.h Node.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o Node.o $(INCLUDE)
TrieTest.o: TrieTest.cpp ./Trie.h
	$(CC) $(CFLAGS) -c TrieTest.cpp $(INCLUDE)
Trie.o: ./Trie.h Trie.cpp ./Node.h
	$(CC) $(CFLAGS) -c Trie.cpp $(INCLUDE)
Node.o: ./Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp $(INCLUDE)
clean:
	rm -f TrieTest *.o
test:
	./TrieTest dictionary.txt query.txt
valgrind:
	valgrind --tool=memcheck --leak-check=full ./TrieTest dictionary.txt query.txt
