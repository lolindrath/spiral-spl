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
OBJS = main.o dft_rule.o spl_program.o spl_program_list.o
EXECS = program_gen
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
	
program_gen: $(OBJS)
	$(LINK) $(LD_FLAGS) $(OBJS) $(LIBS) -o $@

clean:
	$(ERASE) $(OBJS) $(EXECS)
