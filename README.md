simple-ascii-generator
======================

A simple ASCII-Art Generator.

To use, run AsciiGenerator example/input.bmp example/definitions.txt [grid size]

The definitions file maps characters (including unicode characters) to darkness values. Note - space is a reserved character; trying to map a space will cause the program to fail.

The grid size defines scale - for example, a grid size of 2 will average a block of 4 pixels. This argument is optional.
