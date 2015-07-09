all: compile
	./build/EPI

compile: clean
	mkdir build
	cd build && cmake .. && $(MAKE)

ctags:
	ctags -R -f ./.git/tags .

clean:
	rm -rf build/
	rm -rf *.*~
	rm -rf *.out

install:
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make && sudo cp *.a /usr/lib
