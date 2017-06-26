all: get_bit_at test_strcat

get_bit_at: get_bit_at.c
	gcc -g -o get_bit_at get_bit_at.c

test_strcat: test_strcat.c mystrcat.c
	gcc -g -o test_strcat test_strcat.c mystrcat.c

clean:
	rm test_strcat get_bit_at
