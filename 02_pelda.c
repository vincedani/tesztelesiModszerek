/**
 * Eljárás szintű lefedettség mérése GCC-vel
 *
 * Tesztelési módszerek 2. példaprogram C nyelven
 * Bemutatja a GCC fordítóprogram -finstrument-functions használatát a profilozó
 * függvények segítségével és azok attribútumaival.
 *
 * gcc-4.8 -g -finstrument-functions -o 02_binary 02_pelda.c
 * ./02_binary 2> trace.out
 * ./readtracelog.sh 02_binary trace.out
 *
 * @author: Daniel Vince <vinced@inf.u-szeged.hu>
 */
#include <stdio.h>

void __cyg_profile_func_enter (void *, void *) __attribute__((no_instrument_function));
void __cyg_profile_func_exit (void *, void *) __attribute__((no_instrument_function));

void __attribute__ ((constructor)) __attribute__((no_instrument_function)) trace_begin (void) { }
void __attribute__ ((destructor)) __attribute__((no_instrument_function)) trace_end (void) { }

void __cyg_profile_func_enter (void *func, void *caller) {
  fprintf(stderr, "e %p %p\n", func, caller);
}

void __cyg_profile_func_exit (void *func, void *caller) {
  fprintf(stderr, "x %p %p\n", func, caller);
}

void printFirstPart() {
  printf ("Tesztel");
}

void printThirdPart() {
  printf ("mód");
}

void printSecondPart() {
  printf ("ési ");
  printThirdPart();
}

void printFourthPart() {
  printf ("szerek");
}

void putNewLine() {
  printf ("\n");
}

int main () {
  printFirstPart();
  printSecondPart();
  printFourthPart();

  putNewLine();
}
