

spl: spl.l spl.ypp spl.h spl.cpp symbol.h symboltable.h symboltable.cpp spl-print.cpp
	bison -vd spl.ypp
	flex -o spl.lex.c spl.l
	g++ -g -o $@ spl.tab.cpp spl.lex.c spl.cpp symboltable.cpp spl-print.cpp /usr/lib/libfl.a

clean:
	rm -f spl *.o *.tab.hpp *.lex.c *.tab.cpp location.hh position.hh stack.hh
