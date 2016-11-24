objects = main.o interview.o simplestring.o 
cppsnippets : $(objects)
	g++ -o cppsnippets $(objects)
main.o : interview.h simplestring.h singleton.h 
interview.o : interview.h
simplestring.o : simplestring.h
.PHONY : clean
clean :
	rm cppsnippets $(objects)
