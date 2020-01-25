#include <stdint.h>
#include <stdlib.h>

#include "libhydrogen/hydrogen.h"

typedef hydro_hash_state HydroHashState;
typedef hydro_sign_state HydroSignState;

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

hydro_kx_keypair HydroKX_keypair() {
  hydro_kx_keypair pair;
  return pair;
}

hydro_kx_session_keypair HydroKX_session_MINUS_keypair() {
  hydro_kx_session_keypair pair;
  return pair;
}

uint8_t* HydroKX_pk(hydro_kx_keypair* pair) {
  return pair->pk;
}

uint8_t* HydroSign_tx(hydro_session_keypair* pair) {
  return pair->tx;
}

uint8_t* HydroSign_rx(hydro_session_keypair* pair) {
  return pair->rx;
}
