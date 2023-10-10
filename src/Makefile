.PHONY: all clean style_test test gcov_report 

CC =gcc
STDFLAGS =-std=c++17
GCOV_FLAGS=-fprofile-arcs -ftest-coverage 
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
TESTFLAGS = -lcheck -lm -lpthread -o 

TTP_F=$(wildcard $(addsuffix /*.tpp, $(DIRS)))
CC_F=$(wildcard $(addsuffix /*.cc, $(DIRS)))
H_F=$(wildcard $(addsuffix /*.h, $(DIRS)))

TESTDIRS:= $(shell find ./tests -type d)
DIRS:= $(shell find ./ -type d)

TEST:= $(wildcard $(addsuffix /*.cc, $(TESTDIRS)))

OS := $(shell uname -s)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

LIBS=-lgtest -lstdc++

all : clean style_test test gcov_report

test: clean
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(TEST) -o test $(LIBS) -pthread
else
	$(CC) $(STDFLAGS) $(TEST) -o test $(LIBS) -pthread $(LINUX_FLAGS)
endif
	./test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) $(TEST) -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) $(TEST) -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "stest" -o s21_test.info --no-external --filter range -c -d . --ignore-errors mismatch
	genhtml -o report s21_test.info
	open ./report/index.html

style_test:
	cp ../materials/linters/.clang-format .
	clang-format -n $(TTP_F) $(CC_F) $(H_F)
	rm -rf .clang-format

style_make:
	cp ../materials/linters/.clang-format .
	clang-format -i $(TTP_F) $(CC_F) $(H_F)
	rm -rf .clang-format

clean_obj :
	rm -f *.o

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf unit_test

 clean : clean_obj clean_test
	rm -f *.a
	rm -f check
	rm -f debug
