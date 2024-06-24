BUILD_FLAGS = -Wall -Werror -Wextra -std=c++17
TEST_FLAGS =  -lgtest -lgcov
SOURCES = $(wildcard *.cc)
OS = $(shell uname)
GCOV_FLAG = --no-external

ifneq ($(OS), Darwin)
	TEST_FLAGS = -lgtest -lgcov -pthread -lm
	GCOV_FLAG =
endif

all: set.a test gcov_report

set.a:
	g++ $(BUILD_FLAGS) --coverage -c $(SOURCES)
	ar rcs set.a *.o

test: set.a
	g++ $(BUILD_FLAGS) -g ../test/set/SetTest.cc $(TEST_FLAGS) set.a -o test
	chmod 766 ./test
	./test

gcov_report: test
	lcov -o gcov_test.info $(GCOV_FLAG) -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.gcda *.gcno report test gcov_test.info

rebuild: clean all