.PHONY: clean
C_FILES = \
	main.cpp \
	MyVisitor.cpp \
	MyVisitor.h \
	MyTreeMap.h
GENERATED_FILES = \
	lolBaseVisitor.cpp \
	lolBaseVisitor.h \
	lolLexer.cpp \
	lolLexer.h \
	lolParser.cpp \
	lolParser.h \
	lolVisitor.h \
	lolVisitor.cpp
OBJS = \
	lolBaseVisitor.o \
	lolLexer.o \
	lolParser.o \
	lolVisitor.o \
	MyVisitor.o \
	main.o
test: interp.exe
	./interp lel
interp.exe: $(OBJS)
	g++ -g $^ -L./LIBANTLR4/lib -l:libantlr4-runtime.dll.a -o interp
%.o: %.cpp
	g++ -c -g $^ -I./LIBANTLR4/include/antlr4-runtime
$(GENERATED_FILES): lol.g4
	java -jar antlr-4.13.2-complete.jar -visitor -Dlanguage=Cpp lol.g4
clean:
	rm $(OBJS)
clean_src:
	rm $(GENERATED_FILES)
