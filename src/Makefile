BUILD_FLAGS = -Wall -Werror -Wextra -std=c++17
TEST_FLAGS =  -lgtest -lgcov
SOURCES = $(wildcard containers/*/*.cc)
OS = $(shell uname)
GCOV_FLAG = --no-external
LIB_NAME = containers.a
TEST_SOURCE = test/tree/NodeTest.cc

ifneq ($(OS), Darwin)
	TEST_FLAGS = -lgtest -lgcov -pthread -lm -lrt
	GCOV_FLAG =
endif

all: $(LIB_NAME) test gcov_report

$(LIB_NAME):
	g++ $(BUILD_FLAGS) --coverage -c $(SOURCES)
	ar rcs $(LIB_NAME) *.o

test: $(LIB_NAME)
	g++ $(BUILD_FLAGS) -g $(TEST_SOURCE) $(TEST_FLAGS) $(LIB_NAME) -o tests
	./tests

gcov_report: test
	lcov -o gcov_test.info $(GCOV_FLAG) -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

dvi:
	doxygen
	open documentation/html/index.html

clean:
	rm -rf *.o *.a *.gcda *.gcno report tests gcov_test.info documentation

rebuild: clean all
