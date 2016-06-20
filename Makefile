build:
	cc -lxcb -lxcb-randr *.c */*.c -o backlighticon

clean:
	rm -f backlighticon

.PHONY: build clean
