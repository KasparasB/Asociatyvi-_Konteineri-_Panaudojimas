make:
	g++ -c Source.cpp
	g++ -std=c++11 Source.o -o Test
	./Test
valymas:
rm *.o Test 
