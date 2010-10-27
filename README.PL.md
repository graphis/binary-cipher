Binary cipher
=============

Binary cipher jest darmowanym programem o otwartym źródle służącym do szyfrowania dowolnego typu pliku na kod binarny i odwrotnie.

Budowanie
=========

Otwórz Twój ulubiony emulator terminala i przejdź do katalogu, w którym rozpakowałeś binary-cipher:

`$ cd /pelna/sciezka/do/binary-ciper/`

Uruchom `make` aby skompilować program:

`$ make`

Przykład użycia
===============

Aby wygenerować kod binarny z pliku image.jpg po prostu wpisz:

`$ ./binary-cipher --encrypt image.jpg > image.bin`

Kod binarny pliku image.jpg będzie w image.bin

Aby rozkodować plik image.bin, wpisz

`$ ./binary-cipher --decrypt image.bin > image.jpg`

Originalny plik będzie znajdował się w image.jpg

Licencja
========

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
