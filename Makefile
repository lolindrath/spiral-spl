SHELL := /bin/bash

all:
	cd program_gen; make
	cd spl2icode; make
	cd icode2cpp; make

clean:
	cd program_gen; make clean
	cd spl2icode; make clean
	cd icode2cpp; make clean
