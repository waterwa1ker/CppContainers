

all: run

test: 	
	g++ -g -fsanitize=address -Wall -Werror -Wextra -std=c++20 list.cc main.cc
	./a.out

build:
	g++ -Wall -Werror -Wextra -std=c++20 list.cc main.cc

run: build
	./a.out

format:
	clang-format -i -style=google *.cc *.h

dvi:
	doxygen
	open documentation/html/index.html

docker: ../../docker
	sh ../../docker/run.sh

valgrind: clean build
	clear
	valgrind --tool=memcheck --leak-check=yes ./a.out

clean:
	rm -rf documentation