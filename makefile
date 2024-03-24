src = main.c
obj = main.o
prog= restaurantManager

$(prog):$(obj)
	gcc $(obj) -o $(prog)

$(obj):$(src)
	gcc -c $^
