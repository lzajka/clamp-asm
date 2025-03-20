#include <sys/types.h>

/**
 * Funkcja ograniczającą wartość value do przedziału <min, max> implementacja wykorzystuje assembly.
 * @param value wartość do ograniczenia
 * @param min minimalna wartość przedziału
 * @param max maksymalna wartość przedziału
 * @return ograniczona wartość
 */
int clamp(u_int16_t value, u_int16_t min, u_int16_t max);
/**
 * Funkcja wypisująca przedział na wyjście
 * @param range zakres przedziału
 * @param middle środek przedziału
 * @return void
 */
void print_przedzial(int range, int middle);