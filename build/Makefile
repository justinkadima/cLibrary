src=$(wildcard ../*.c)
headers=$(wildcard ../*.h)

cflags=-g -Wall -std=c99
ldflags=

progname=mylib


testsrc=$(wildcard ../test/*.c)
testname=test


$(progname):$(src) $(headers)
	cc $(cflags) -o $@ $(src) $(ldflags)

  
test:$(testsrc) $(src) $(headers)
	 cc $(cflags) -o $(testname) $(testsrc) $(src) $(ldflags)
	./$(testname)
  
lib:$(src) $(headers)
	cc -c $(cflags) $(src) $(ldflags)
	ar rcs $(progname).a $(wildcard *.o)



clean:
	rm -f $(progname) $(progname).* $(testname) $(wildcard *.o)
	
run:
	./$(progname)
  
