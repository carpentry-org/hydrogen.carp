# hydrogen

**WIP**

A simple wrapper around [libhydrogen](https://github.com/jedisct1/libhydrogen)
for Carp.

Currently the library does not support password hashing, key derivation, or
utilities.

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@master")

(def CONTEXT (Hydro.context "Examples"))
(def MSG (Hydro.buf "Arbitrary data to hash"))

(defn main []
   (let [key (HydroHash.keygen)]
      (println* &(HydroHash.gen &MSG CONTEXT &key))))
```

## Usage

This is an early WIP. The functions should work, though. If you want to try the
library out, you should be able to get it by adding the following line to your
program:

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@master")
```

If you want to see how to use the library, you can look at the
[examples/](/examples) directory.

<hr/>

Have fun!
