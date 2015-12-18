objects = generate.o lex.yy.o y.tab.o parser.o

oa : $(objects)
	g++ -o oa $(objects)

$(objects) : oa.h y.tab.h

.PHONY : clean
clean :
	del oa $(objects)
