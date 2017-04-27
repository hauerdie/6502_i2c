# 6502_i2c
Bitbang i2c with MOS 6502 and 6522

This is the code I use to bitbang i2c on my MOS 6052 homebrew computer via an VIA 6522.

cc65 is used for assembly and compilation of the examples.

The code is not optimized, setting SDA and SCL are subroutines, which slows down communication a lot.

## Examples:
1. i2sscan.c - can be used to scan the i2c bus.
2. ds3231_date.c - read the date of a ds3231 realtime clock attached to the i2c bus.

