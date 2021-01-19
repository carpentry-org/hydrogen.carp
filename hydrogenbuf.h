#include <stdint.h>
#include <stdlib.h>

#include "libhydrogen/hydrogen.h"

typedef hydro_hash_state HydroHashState;
typedef hydro_sign_state HydroSignState;
typedef hydro_sign_keypair HydroSignKeyPair;
typedef hydro_kx_state HydroKXState;
typedef hydro_kx_keypair HydroKXKeyPair;
typedef hydro_kx_session_keypair HydroKXSessionKeyPair;

uint8_t* Hydro_raw(Array* buf) {
  return buf->data;
}

HydroSignKeyPair HydroSign_keypair() {
  hydro_sign_keypair pair = {};
  return pair;
}

uint8_t* HydroSign_pk(hydro_sign_keypair* pair) {
  return pair->pk;
}

uint8_t* HydroSign_sk(hydro_sign_keypair* pair) {
  return pair->sk;
}

hydro_hash_state HydroHash_state() {
  hydro_hash_state state = {};
  return state;
}

hydro_sign_state HydroSign_state() {
  hydro_sign_state state = {};
  return state;
}

hydro_kx_keypair HydroKX_keypair() {
  hydro_kx_keypair pair = {};
  return pair;
}

hydro_kx_session_keypair HydroKX_session_MINUS_keypair() {
  hydro_kx_session_keypair pair = {};
  return pair;
}

hydro_kx_state HydroKX_state() {
  hydro_kx_state state = {};
  return state;
}

uint8_t* HydroKX_pk(hydro_kx_keypair* pair) {
  return pair->pk;
}

Array HydroKX_rx(hydro_kx_session_keypair* pair) {
  Array res;
  res.data = CARP_MALLOC(hydro_kx_SESSIONKEYBYTES);
  res.len = hydro_kx_SESSIONKEYBYTES;
  res.capacity = hydro_kx_SESSIONKEYBYTES;
  memcpy(res.data, pair->rx, hydro_kx_SESSIONKEYBYTES);
  return res;
}

Array HydroKX_tx(hydro_kx_session_keypair* pair) {
  Array res;
  res.data = CARP_MALLOC(hydro_kx_SESSIONKEYBYTES);
  res.len = hydro_kx_SESSIONKEYBYTES;
  res.capacity = hydro_kx_SESSIONKEYBYTES;
  memcpy(res.data, pair->tx, hydro_kx_SESSIONKEYBYTES);
  return res;
}

Array Hydro_make_x_array(uint8_t e[hydro_kx_SESSIONKEYBYTES]) {
  Array res;
  res.len = hydro_kx_SESSIONKEYBYTES;
  res.capacity = hydro_kx_SESSIONKEYBYTES;
  res.data = CARP_MALLOC(hydro_kx_SESSIONKEYBYTES);
  memcpy(res.data, e, hydro_kx_SESSIONKEYBYTES);
  return res;
}

Array HydroSign_tx(hydro_kx_session_keypair* pair) {
  return Hydro_make_x_array(pair->tx);
}

Array HydroSign_rx(hydro_kx_session_keypair* pair) {
  return Hydro_make_x_array(pair->rx);
}
