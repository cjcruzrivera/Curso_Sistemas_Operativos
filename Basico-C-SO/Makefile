clean:
	rm -rf a.out fibo.o libfibo.a main
obj:
	gcc -c fibo.c -o fibo.o
lib:
	ar rcs libfibo.a fibo.o
bin: obj lib
	gcc -static main.c -L. -I. -lfibo -o main
