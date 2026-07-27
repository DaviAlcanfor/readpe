all:
	gcc -o readpe src/readpe.c -L./lib -lpetest

clean:
	rm -f readpe

install:
	install -m 0644 lib/libpetest.so /usr/lib/libpetest.so

uninstall:
	rm -f /usr/lib/libpetest.so
