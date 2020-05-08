# hydrogen

A simple wrapper around [libhydrogen](https://github.com/jedisct1/libhydrogen)
for Carp.

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@0.0.2")

(def CONTEXT (Hydro.context "Examples"))
(def MSG (Hydro.buf "Arbitrary data to hash"))

(defn main []
   (let [key (HydroHash.keygen)]
      (println* &(HydroHash.gen &MSG CONTEXT &key))))
```

## Installation

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@0.0.2")
```

## Usage

If you want to see how to use the library, you can look at the
[examples/](/examples) directory or look at the [docs
website](https://veitheller.de/hydrogen/).

Please note that the key exchange API has not been tested exhaustively and
could very well be broken. As of now I’d recommend against using it.

<hr/>

Have fun!
