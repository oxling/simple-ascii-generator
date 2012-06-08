A simple ASCII-Art Generator.

To use, run AsciiGenerator example/input.bmp example/definitions.txt [grid size width] [grid size height]

The definitions file maps characters (including unicode characters) to darkness values. The format of the file is [character]:[value], where the entries are separated by newlines and the last entry ends with a semicolon. Note - ':' and ';' are reserved characters; trying to map a colon or semi-colon will cause the program to fail.

The grid size defines scale - for example, a grid size of 2, 3 will average a block of 6 pixels two pixels wide and three pixels tall. This argument is optional.
