generate_test:
	cd test_case ; python generator.py ; cd ..
build:
	g++ -std=c++20 src/main.cpp -o bin/main
debug:
	g++ -std=c++20 -g src/main.cpp -o bin/main
run:
	./bin/main