all:
	clang -I. -I kremlib/dist/minimal -Wall -Wextra *.c && ./a.out
clean:
	rm -rf *.o *.out