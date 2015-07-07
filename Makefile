all: compile

compile: clean
	mkdir build
	cd build && cmake .. && $(MAKE)

ctags:
	ctags -R -f ./.git/tags .

clean:
	rm -rf build/
	rm -rf *.*~
	rm -rf *.out
