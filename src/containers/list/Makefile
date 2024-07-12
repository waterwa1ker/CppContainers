

all: format run

t: 
	g++ -Wall -Werror -Wextra -std=c++20 main.cc
	./a.out

run:
	g++ -Wall -Werror -Wextra -std=c++20 list.cc main.cc
	./a.out

format:
	clang-format -i -style=google *.cc *.h

dvi:
	doxygen
	open documentation/html/index.html

clean:
	rm -rf documentation