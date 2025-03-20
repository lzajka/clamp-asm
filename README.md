# Clamp-asm

Ten program w języku C++ wykorzystuje słowo kluczowe `asm` do ograniczania wartości zmiennych, tak aby mieściły się w określonym przedziale.

Kod asemblera zawarty w `asm` używa składni AT&T. Mimo że kod nie jest bezpośrednio kompatybilny z mikroprocesorami MSP430, program ma na celu służyć jako wzorzec.

Program był testowany jedynie na Linuxie z procesorem Intel x86_64. Nie wiem, czy działa na innych konfiguracjach. Aby uruchomić program w środowisku Linux, można użyć [dev containeru](https://code.visualstudio.com/docs/devcontainers/containers) dostępnego w tym projekcie. Visual Studio Code powinien automatycznie go wykryć.

# Działanie i składnia

`./clamp`

Po uruchomieniu programu można wprowadzać polecenia przez standardowe wejście.

Program domyślnie działa w przedziale od 0 do 256, imitując sytuację, w której mikroprocesor MSP430 działa jako generator bez ograniczeń. Każde polecenie ustawia nowy przedział.

- `<` - zmniejsza przedział o 1 z każdej strony.
- `>` - zwiększa przedział o 1 z każdej strony.

Aby podać liczbę, na której program ma zastosować ograniczenie, wystarczy ją wprowadzić przez standardowe wejście. Program zwróci wartość po zastosowaniu operacji.

# Makefile

- `make` / `make all` / `make clamp` - kompiluje kod źródłowy do pliku wykonywalnego `clamp`.
- `make clean` - usuwa pliki powstałe w wyniku kompilacji.
- `make run` - buduje i uruchamia program.
