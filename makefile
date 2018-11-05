COMPILER = g++ -std=c++11

main: main.cpp
	$(COMPILER) main.cpp -o AwesomeCoin
	

clean:
	rm AwesomeCoin