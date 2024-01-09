CC = gcc
#--------------------------------------------------------------------------------------------
CFLAGS = -std=c11 -pedantic -Wall -Wextra -Werror
#--------------------------------------------------------------------------------------------
TEST_FLAGS = -lcheck
TESTS = test
#--------------------------------------------------------------------------------------------
REPORT = gcov_report
GCOV_REPORT = gcov/$(REPORT)
GCOV_INFO = $(GCOV_REPORT).info
GCOV_FLAGS  = --coverage -lcheck
#--------------------------------------------------------------------------------------------
OS = $(shell uname)
3DVIEWER = 3DViewer.app
#--------------------------------------------------------------------------------------------
ifeq ($(OS), Linux)
	TEST_FLAGS += -lm -lsubunit -D_GNU_SOURCE -lrt
	GCOV_FLAGS += -lrt -lsubunit -lpthread -lm
	SMARTCALC = smartcalc
endif
#--------------------------------------------------------------------------------------------

.PHONY: all install open dvi dist test gcov_report open uninstall clean rebuild

all: install open

test: clean
	$(CC) $(CFLAGS) ./back/$(TESTS).c ./back/s21_parcer.c $(TEST_FLAGS) -o $(TESTS)
	./$(TESTS)


check_leaks_qt:
	make clean
	make install_qt
	CK_FORK=no leaks --atExit -- ./build/OpenGL_1.app/Contents/MacOS/OpenGL_1 > logfile.log #leaks --atExit --
	make clean

$(REPORT): clean
	mkdir -p gcov
	gcc $(CFLAGS) ./back/s21_parcer.c ./back/$(TESTS).c $(GCOV_FLAGS) -o $(GCOV_REPORT) -DUNIT_TESTING -ggdb3 -fPIC -O0 --coverage
	./$(GCOV_REPORT)
ifeq ($(OS), Darwin)
	mv *.gcno *.gcda gcov
endif
	lcov -t "$(REPORT)" -o $(GCOV_INFO) -c -d gcov
	genhtml -o report $(GCOV_INFO) $(GCOV_INFO)
	open report/index.html

install: uninstall clean
	cd ../ && mkdir build
	cd 3DViewer && qmake && make && make clean && rm Makefile && cd ../ && mv 3DViewer/OpenGL_1.app ../build/

install_qt: uninstall clean
	rm -rf build
	mkdir build
	cp -rf ./3DViewer/OpenGL_1.pro build
	cp -rf ./back/*.c build
	cp -rf ./3DViewer/*.C build
	cp -rf ./3DViewer/*.cpp build
	cp -rf ./3DViewer/*.h build
	cp -rf ./back/*.h build
	cp -rf ./3DViewer/*.ui build
	cd build && qmake OpenGL_1.pro
	make -C build
	cd build && make clean
	# open ./build/OpenGL_1.app/Contents/MacOS/OpenGL_1

check_leaks:
ifeq ($(OS) ,Darwin)
	$(CC) $(CFLAGS) ./back/s21_parcer.c $(TESTS).c $(TEST_FLAGS) -o $(TESTS)
	leaks -atExit -- ./$(TESTS)
else
ifeq ($(OS) ,Linux)
	$(CC) $(CFLAGS) -g $(TESTS).c -o test ./back/s21_parcer.c $(TEST_FLAGS)
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.txt ./test
endif
endif

dvi:
	open dvi/index.html

dist:
	rm -rf ../Archive_3DViewer/
	mkdir ../Archive_3DViewer/
	cp -a **/ ./* Makefile ../build/OpenGL_1.app ../Archive_3DViewer
	cd ../ && tar -cvzf Archive_3DViewer.tar.gz Archive_3DViewer

open:
	cd ../build && open OpenGL_1.app

open_qt:
	cd ./build && open OpenGL_1.app

uninstall:
	rm -rf ../build*

clean:
	rm -rf *.{a,o,dSYM,out}
	rm -rf gcov_report
	rm -rf report
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf Tests/test
	rm -rf ../*.gz
	rm -rf ../Archive_3DViewer
	rm -rf gcov
	rm -rf test
	rm -rf RESULT.txt
	rm -rf ../src/3DViewer/*.o



style:
	cp ../materials/linters/.clang-format ./
	echo "======= CHECK GOOGLE CODE STYLE ======="
	sleep 1
	clang-format -n ./back/*.c  ./back/*.h ./3DViewer/*.C 3DViewer/*.cpp 3DViewer/*.h
	rm -rf .clang-format