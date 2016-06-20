build:
	cc -lxcb -lxcb-randr *.c */*.c -o xbacklighticon

install:
	install xbacklighticon /usr/bin

clean:
	rm -f xbacklighticon

.PHONY: build install clean
