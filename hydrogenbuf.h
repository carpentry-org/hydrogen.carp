#include <stdint.h>
#include <stdlib.h>

#include "libhydrogen/hydrogen.h"

typedef hydro_hash_state HydroHashState;
typedef hydro_sign_state HydroSignState;
typedef hydro_sign_keypair KeyPair;

uint8_t* Hydro_raw(Array* buf) {
  return buf->data;
}

hydro_sign_keypair HydroSign_keypair() {
  hydro_sign_keypair pair;
  return pair;
}

uint8_t* HydroSign_pk(hydro_sign_keypair* pair) {
  return pair->pk;
}

uint8_t* HydroSign_sk(hydro_sign_keypair* pair) {
  return pair->sk;
}

hydro_hash_state HydroHash_state() {
  hydro_hash_state state;
  return state;
}

hydro_sign_state HydroSign_state() {
  hydro_sign_state state;
  return state;
}
