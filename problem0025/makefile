out: main.o ThousandDigitNumber.o
	g++ -std=c++17 -Wpedantic main.o ThousandDigitNumber.o -o out

main.o: main.cpp
	g++ -std=c++17 -Wpedantic -c main.cpp

ThousandDigitNumber.o: ThousandDigitNumber.h ThousandDigitNumber.cpp
	g++ -std=c++17 -Wpedantic -c ThousandDigitNumber.cpp

cleanup:
	rm *.o out *.s

assem:
	g++ -std=c++17 -Wpedantic -S *.cpp

format:
	clang-format -i -style=file *.cpp
