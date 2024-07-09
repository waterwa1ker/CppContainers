

all: format run

run:
	g++ -Wall -Werror -Wextra -std=c++20 -O3 main.cc list/list.cc 
format:
	clang-format -i -style=google *.cc *.h

dvi:
	doxygen
	open documentation/html/index.html

clean:
	rm -rf documentation