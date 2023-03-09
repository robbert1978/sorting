generate_test:
	cd test_case ; python3 generator.py ; cd ..
build:
	g++ src/main.cpp -o bin/main
debug:
	g++ -g src/main.cpp -o bin/main
run:
	./bin/main