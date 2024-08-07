BUILD_FLAGS = -Wall -Werror -Wextra -std=c++17
TEST_FLAGS =  -lgtest -lgcov
SOURCES = $(wildcard containers/*/*.cc)
TEST_SOURCES = $(wildcard s21tests/*.cc)
OS = $(shell uname)
GCOV_FLAG = --no-external
LIB_NAME = containers.a

TEST_EXECUTE = containers_tests

ifneq ($(OS), Darwin)
	TEST_FLAGS = -lgtest -lgcov -pthread -lm -lrt
	GCOV_FLAG =
endif

all: $(LIB_NAME)

$(LIB_NAME):
	g++ $(BUILD_FLAGS) --coverage -c $(SOURCES)
	ar rcs $(LIB_NAME) *.o

test: $(LIB_NAME)
	g++ $(BUILD_FLAGS) -g $(LIB_GTEST) $(LIB_NAME) $(TEST_SOURCES)  $(TEST_FLAGS) -o $(TEST_EXECUTE)
	./$(TEST_EXECUTE)

dvi:
	doxygen
	open documentation/html/index.html

gcov_report: test
	lcov -o gcov_test.info $(GCOV_FLAG) -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

valgrind: clean test
	clear
	valgrind --tool=memcheck --leak-check=yes ./$(TEST_EXECUTE)
	
con:
	sh docker/run.sh

format:
	clang-format -style=google -i $(TEST_SOURCES) $(SOURCES)

check:
	clang-format -style=google -n $(TEST_SOURCES) $(SOURCES)

clean:
	rm -rf *.o *.a *.gcda *.gcno report gcov_test.info documentation $(TEST_EXECUTE)

rebuild: clean all
