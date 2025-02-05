out: main.o FiftyDigitNumber.o
	g++ -std=c++17 -Wpedantic main.o FiftyDigitNumber.o -o out

main.o: main.cpp
	g++ -std=c++17 -Wpedantic -c main.cpp

FiftyDigitNumber.o: FiftyDigitNumber.h FiftyDigitNumber.cpp
	g++ -std=c++17 -Wpedantic -c FiftyDigitNumber.cpp

cleanup:
	rm *.o out *.s

assem:
	g++ -std=c++17 -Wpedantic -S *.cpp

format:
	clang-format -i -style=file *.cpp
