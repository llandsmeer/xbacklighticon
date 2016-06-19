build:
	cc -lxcb *.c */*.c -o backlighticon

clean:
	rm -f backlighticon

.PHONY: build clean
