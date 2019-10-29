#include <stdint.h>
#include <stdlib.h>

#include "libhydrogen/hydrogen.h"

typedef uint8_t* HydroBufRaw;
typedef hydro_hash_state HydroHashState;
typedef hydro_sign_state HydroSignState;
typedef hydro_sign_keypair HydroSignKeyPair;

typedef struct {
  HydroBufRaw buf;
  size_t length;
} HydroBuf;

HydroBuf Hydro_allocate(int n) {
  HydroBuf res;
  res.length = n;
  res.buf = malloc(n);
  return res;
}

void HydroBuf_delete(HydroBuf b) {
  free(b.buf);
}

HydroBuf Hydro_buf(String* s) {
  HydroBuf res;
  res.length = strlen(*s);
  res.buf = malloc(res.length);
  memcpy(res.buf, *s, res.length);
  return res;
}

String Hydro_unbuf(HydroBuf* s) {
  String res = malloc(s->length);
  memcpy(res, s->buf, s->length);
  return res;
}

Array Hydro_to_MINUS_array(HydroBuf* s) {
  Array res;
  res.data = malloc(s->length);
  res.len = s->length;
  res.capacity = s->length;
  memcpy(res.data, s->buf, s->length);
  return res;
}

String HydroBuf_str(HydroBuf* buf) {
  char* res = malloc(buf->length*2+1);
  for (int i = 0; i < buf->length; i++) {
    sprintf(res+i*2, "%02x", buf->buf[i]);
  }
  return res;
}

int HydroBuf_length(HydroBuf* buf) {
  return buf->length;
}

HydroBufRaw HydroBuf_raw(HydroBuf* buf) {
  return buf->buf;
}

hydro_hash_state HydroHash_state() {
  hydro_hash_state state;
  return state;
}

hydro_sign_keypair HydroSign_keypair() {
  hydro_sign_keypair pair;
  return pair;
}

HydroBufRaw HydroSign_sk(hydro_sign_keypair* p) {
  return p->sk;
}

HydroBufRaw HydroSign_pk(hydro_sign_keypair* p) {
  return p->pk;
}

hydro_sign_state HydroSign_state() {
  hydro_sign_state state;
  return state;
}
