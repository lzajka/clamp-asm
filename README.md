Ten program w języku C++ wykorzystuje słowo kluczowe `asm` w celu ograniczenia wartości zmiennych, tak aby mieściły się one w określonym przedziale.

Assembly zawarty w `asm` używa składni AT&T. Mimo, że kod nie jest bezpośrednio kompatybilny z mikroprocesorami MSP430, program ma na celu służyć jako wzorzec.

Program był jedynie testowany na Linuxie z procesorem intel x86_64. Nie mam pojęcia czy zadziała dla innych konfiguracji. W celu wykonania programu w środowisku Linux można wykorzystać znajdujący się w tym projektcie [dev container](https://code.visualstudio.com/docs/devcontainers/containers). Visual studio code powinien być sam w stanie go wykryć.
# Działanie i składnia
`./clamp`

Po uruchomieniu programu można podawać polecenia na standardowe wejście.

Program domyślnie zaczyna działanie na przedziale od 0 do 256. Imituje to sytuacje w której mikroprocesor MSP430 działa jako generator bez ograniczeń. Co każde polecenie podaje ustawiony przedział.

W celu zmniejszenia przedziału o 1 z każdej strony wykorzystujemy polecenie `<`. Polecenie `>` służy do zwiększenia przedziału o 1 z każdej strony.

W celu podania liczby, na której program ma zastosować ograniczenie wystarczy ją podać na standardowe wejście. Program zwróci wartość po zastsowowaniu operacji.

# Makefile
- `make`/`make all`/`make clamp` - kompilacja kodu źródłowego do pliku wykonywalnego `clamp`
- `make clean` - usunięcie plików powstałych na skutek kompilacji.
- `make run` - buduje i uruchamia program.
