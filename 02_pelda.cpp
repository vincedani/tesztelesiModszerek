/**
 * Eljárás szintű lefedettség mérése GCC-vel
 *
 * Tesztelési módszerek 2. példaprogram C++ nyelven
 * Bemutatja a GCC fordítóprogram -finstrument-functions használatát a profilozó
 * függvények segítségével és azok attribútumaival.
 *
 * gcc-4.8 -g -finstrument-functions -o 02_binary 02_pelda.c
 * ./02_binary 2> trace.out
 * ./readtracelog.sh 02_binary trace.out
 *
 * @author: Daniel Vince <vinced@inf.u-szeged.hu>
 */
#include <iostream>
#include "stdio.h"
using namespace std;

extern "C" {
  void __cyg_profile_func_enter (void *, void *) __attribute__((no_instrument_function));
  void __cyg_profile_func_exit (void *, void *) __attribute__((no_instrument_function));

  void __cyg_profile_func_enter (void *func, void *caller) {
    fprintf(stderr, "e %p %p\n", func, caller);
  }

  void __cyg_profile_func_exit (void *func, void *caller) {
    fprintf(stderr, "x %p %p\n", func, caller);
  }
} // extern "C"

void printFirstPart() {
  cout << "Tesztel";
}

void printThirdPart() {
  cout << "mód";
}

void printSecondPart() {
  cout << "ési ";
  printThirdPart();
}

void printFourthPart() {
  cout << "szerek";
}

void putNewLine() {
  cout << endl;
}

int main () {
  printFirstPart();
  printSecondPart();
  printFourthPart();

  putNewLine();
}
