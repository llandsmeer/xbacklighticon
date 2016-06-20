# XBacklightIcon

Backlight control for your system tray - X only.

Scroll to change the brightness values of your screen(s).

## Installation

    $ make
    cc -lxcb -lxcb-randr *.c */*.c -o xbacklighticon
    $ sudo make install
    [sudo] password for user:
    install xbacklighticon /usr/bin
