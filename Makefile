SHELL := /bin/bash

all:
	cd program_gen; make
	cd spl2icode; make
	cd icode2cpp; make

