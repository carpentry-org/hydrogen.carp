# hydrogen

A simple wrapper around [libhydrogen](https://github.com/jedisct1/libhydrogen)
for Carp.

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@0.2.0")

(def CONTEXT (Hydro.context "Examples"))
(def MSG (Hydro.buf "Arbitrary data to hash"))

(defn main []
   (let [key (HydroHash.keygen)]
      (println* &(HydroHash.gen &MSG CONTEXT &key))))
```

## Installation

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@0.2.0")
```

## Usage

If you want to see how to use the library, you can look at the
[examples/](/examples) directory or look at the [docs
website](https://veitheller.de/hydrogen/).

Every hydrogen artifact—keys, hashes, ciphertexts and probes—is an `(Array
Byte)`. To store one in a config file or print it, run it through
`Hydro.to-hex` and `Hydro.from-hex`:

```clojure
(let-do [key (HydroSecretBox.keygen)
         stored (Hydro.to-hex &key)]
  (println* &stored)
  (match (Hydro.from-hex &stored)
    (Maybe.Just k) (assert (Hydro.= &key &k))
    (Maybe.Nothing) (println* "not valid hex")))
```

Please note that the key exchange API has not been tested exhaustively and
could very well be broken. As of now I’d recommend against using it.

<hr/>

Have fun!
