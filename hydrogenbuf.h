#include <stdint.h>
#include <stdlib.h>
#include <core.h>

#include "libhydrogen/hydrogen.h"

typedef uint8_t* HydroBufRaw;
typedef hydro_hash_state HydroHashState;

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

HydroBuf Hydro_buf(String* s) {
  HydroBuf res;
  res.length = strlen(*s);
  res.buf = malloc(res.length);
  memcpy(res.buf, *s, res.length);
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
