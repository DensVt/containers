WWW = -Wall -Werror -Wextra
TEST = -lgtest -lgmock -pthread
STD = -std=c++17
FILES = ./source_code/*.cc
F_TEST = ./source_code/*.cc ./test/test.cc
CHECK = -n
# -n review -i fix

all: clean main

main:
	mkdir -p build
	g++ $(STD) $(WWW) main.cc s21_array.cc -o build/a.out
	./build/a.out

s21_matrix_oop.a:
	mkdir -p build
	g++ $(STD) $(WWW) -c $(FILES)
	ar rcs build/s21_matrix_oop.a ./*.o
	ranlib build/s21_matrix_oop.a
	rm -rf ./*.o

test: clean
	mkdir -p build
	g++ $(STD) $(WWW)  $(F_TEST) -lm -o build/test.out $(TEST)
	./build/test.out

gcov_report: clean test
	g++ $(STD) $(WWW) $(TEST) $(F_TEST) -fprofile-arcs -ftest-coverage -o test.out
	./test.out
	lcov -c -d . -o test.info --ignore-errors inconsistent --no-external
	genhtml -o report test.info --ignore-errors inconsistent 
	gcovr -r ./source_code/*.cc --html --html-details -o ./report/coverage_report.html
	open ./report/index.html

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf test.out
	rm -rf ./report
	rm -rf *.dSYM
	rm -rf build

leaks:
	mkdir -p build
	g++ $(STD) $(WWW) $(TEST) $(F_TEST) -o build/test.out
	leaks -atExit -- ./build/test.out

check: clean
	@cp ../materials/linters/.clang-format .
	cd source_code/ && clang-format $(CHECK) *.cc *.h
	cd test/ && clang-format $(CHECK) *.cc *.h
	@rm .clang-format 

cpplint:
	cpplint test/*.cc test/*.h source_code/*.cc source_code/*.h
