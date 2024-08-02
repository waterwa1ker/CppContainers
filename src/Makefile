BUILD_FLAGS = -Wall -Werror -Wextra -std=c++17
TEST_FLAGS =  -lgtest -lgcov
SOURCES = $(wildcard containers/*/*.cc)
OS = $(shell uname)
GCOV_FLAG = --no-external
LIB_NAME = containers.a

LIB_GTEST= $(wildcard gtest/lib/*.a)

ifneq ($(OS), Darwin)
	TEST_FLAGS = -lgtest -lgcov -pthread -lm -lrt
	GCOV_FLAG =
endif

all: $(LIB_NAME)

$(LIB_NAME):
	g++ $(BUILD_FLAGS) --coverage -c $(SOURCES)
	ar rcs $(LIB_NAME) *.o

test: $(LIB_NAME)
	g++ $(BUILD_FLAGS) -g $(LIB_GTEST) tests/list_test.cc  $(TEST_FLAGS) $(LIB_NAME) -o tests
	./tests

dvi:
	doxygen
	open documentation/html/index.html

gcov_report: test
	lcov -o gcov_test.info $(GCOV_FLAG) -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

con:
	sh docker/run.sh

clean:
	rm -rf *.o *.a *.gcda *.gcno report gcov_test.info documentation

rebuild: clean all
