CXX=clang++
INCLUDES=-Iincludes/ -Ilib/
CXX_FLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests
reduced: bin/reduced

bin/exec: src/* includes/*
	${CXX} ${CXX_FLAGS} src/* -o bin/exec

bin/tests: src/* includes/* tests/*
	$(CXX) $(CXX_FLAGS) src/* -o bin/tests

bin/reduced: src/main.cc includes/HashAlgorithm.hpp
	$(CXX) $(CXX_FLAGS) src/main.cc -o bin/reduced


.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*