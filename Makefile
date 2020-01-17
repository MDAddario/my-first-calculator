all: generator

generator: generator.c
	gcc generator.c -o generator

clean:
	rm generator calculator.py -f
