Binary cipher
=============

Binary cipher is an open source program to encrypt any file to binary code and vice versa

Building
========

Run your favourite terminal emulator and go to binary-cipher directory:

`$ cd /full/path/to/your/binary-ciper/`

Run `make` to compile the program:

`$ make`

Simple usage
=====

To generate binary code from file image.jpg just type:

`$ ./binary-cipher --encode image.jpg > image.bin`

Now you have binary code of image.jpg in image.bin

To decode file from binary code just type:

`$ ./binary-cipher --decode image.bin > image.jpg`

Now you have your file in image.jpg

Working with filters
====================

To encrypt your file just type:

`$ ./binary-cipher --encode -f stdcipher -k 168 -k 93 -k 12 -k 168 image.jpg > image.encrypted.bin`

The program will use all above keys to encrypt your file.

To decrypt file, you must use the same keys in the same order:

`$ ./binary-cipher --decode -f stdcipher -k 168 -k 93 -k 12 -k 168 image.encrypted.bin > image.origin.jpg`

License
=======

Copyright (C) 2010 Patryk Jaworski <skorpion9312@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses.

Licence - PL
============

Copyright (C) 2010 Patryk Jaworski <skorpion9312@gmail.com>

Niniejszy program jest wolnym oprogramowaniem - możesz go rozpowszechniać dalej
i/lub modyfikować na warunkach Powszechnej Licencji Publicznej GNU wydanej przez
Fundację Wolnego Oprogramowania, według wersji 3 tej Licencji lub dowolnej
z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on użyteczny - jednak
BEZ ŻADNEJ GWARANCJI, nawet domyślnej gwarancji PRZYDATNOŚCI HANDLOWEJ
albo PRZYDATNOŚCI DO OKREŚLONYCH ZASTOSOWAŃ. Bliższe informacje na ten temat
można uzyskać z Powszechnej Licencji Publicznej GNU.

Kopia Powszechnej Licencji Publicznej GNU powinna zostać ci dostarczona razem
z tym programem. Jeżeli nie została dostarczona, odwiedź http://www.gnu.org/licenses.

Nieoficjalne, tłumaczenie licencji znajdziesz pod adresem: http://itlaw.computerworld.pl/index.php/gpl-3/
