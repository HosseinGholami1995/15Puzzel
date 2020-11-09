all:
	mkdir -p build
	gcc 15puzzel.c my_Linux_commands.c -o build/exec
clean:
	rm  build/*.*
