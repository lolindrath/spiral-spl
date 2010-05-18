DEFINES = -DDEBUG
OPTIMIZE = -O0
CC = gcc -c
C_FLAGS = -g -Wall $(OPTIMIZE)
CXX = g++  -c
LINK = g++
CXX_FLAGS = -g  -Wall $(OPTIMIZE)
LD_FLAGS = -g 
LD_PATH = /usr/local/lib64 /usr/lib64 /usr/local/lib /usr/lib
C_FLAGS += $(DEFINES)
CXX_FLAGS += $(DEFINES)
LIBS = -lm -lstdc++ -L/usr/lib/libfl.a 
INC = -I /usr/include -I /usr/local/include -I .
ERASE = rm -rf
OBJS = 
EXECS = icode2c
LEXX = flex
YACC = bison -vd

all: $(EXECS)

%.o : %.cc
	$(CXX) $(CXX_FLAGS) $(INC) $< -o $@

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) $(INC) $< -o $@

%.o : %.c
	$(CXX) $(C_FLAGS) $(INC) $< -o $@

%.tab.hpp : %.ypp
	$(YACC) $<
	
%.lex.c: %.l %.tab.hpp
	$(LEXX) -o $@ $<

%.tab.o : %.tab.hpp %.tab.cpp
	$(CXX) $(CXX_FLAGS) $(INC) $< -o $@

%.lex.o : %.lex.c
	$(CXX) $(CXX_FLAGS) $(INC) $< -o $@
	
icode2c: ICode.lex.c ICode.tab.hpp ICode.tab.cpp
	$(LINK) $(LD_FLAGS) $(INC) main.cpp ICode.lex.c ICode.tab.cpp $(LIBS) -o $@

clean:
	$(ERASE) $(OBJS) $(EXECS) *.tab.hpp *.lex.c *.tab.cpp location.hh position.hh stack.hh *.output *.o
