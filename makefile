src = main.c util.h
obj = main.o util.o
prog= restaurantManager

$(prog):$(obj)
	gcc $(obj) -o $(prog)

$(obj):$(src)
	gcc -c -g $^
