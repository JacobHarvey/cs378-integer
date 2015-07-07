FILES :=                              \
    .travis.yml                       \
    Integer-tests/jlh5585-RunInteger.in   \
    Integer-tests/jlh5585-RunInteger.out  \
    Integer-tests/jlh5585-TestInteger.c++ \
    Integer-tests/jlh5585-TestInteger.out \
    Integer.c++                       \
    Integer.h                         \
    Integer.log                       \
    html                              \
    RunInteger.c++                    \
    RunInteger.in                     \
    RunInteger.out                    \
    TestInteger.c++                   \
    TestInteger.out

ifeq ($(CXX), clang++)
    COVFLAGS := --coverage
    GCOV     := gcov-4.6
else
    CXX      := g++-4.8
    COVFLAGS := -fprofile-arcs -ftest-coverage
    GCOV     := gcov-4.8
endif

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

all: RunInteger TestInteger

check:
	@for i in $(FILES);                                         \
	do                                                          \
        [ -e $$i ] && echo "$$i found" || echo "$$i NOT FOUND"; \
    done

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunInteger
	rm -f TestInteger

config:
	git config -l

test:   TestInteger.out

Integer-tests:
	git clone https://github.com/cs378-summer-2015/Integer-tests.git

html: Doxyfile Integer.h RunInteger.c++ TestInteger.c++
	doxygen Doxyfile

Integer.log:
	git log > Integer.log

Doxyfile:
	doxygen -g

RunInteger: Integer.h RunInteger.c++
	$(CXX) $(CXXFLAGS) RunInteger.c++ -o RunInteger

TestInteger: Integer.h TestInteger.c++
	$(CXX) $(COVFLAGS) $(CXXFLAGS) TestInteger.c++ -o TestInteger $(LDFLAGS)

TestInteger.out: TestInteger
	$(VALGRIND) ./TestInteger  >  TestInteger.out 2>&1
	$(GCOV) -b TestInteger.c++ >> TestInteger.out
	cat TestInteger.out
