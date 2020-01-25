# hydrogen

A simple wrapper around [libhydrogen](https://github.com/jedisct1/libhydrogen)
for Carp.

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@master")

(def CONTEXT (Hydro.context "Examples"))
(def MSG (Hydro.buf "Arbitrary data to hash"))

(defn main []
   (let [key (HydroHash.keygen)]
      (println* &(HydroHash.gen &MSG CONTEXT &key))))
```

## Installation

```clojure
(load "git@github.com:carpentry-org/hydrogen.carp.git@master")
```

## Usage

If you want to see how to use the library, you can look at the
[examples/](/examples) directory or look at the [docs
website](https://veitheller.de/hydrogen/).

<hr/>

Have fun!
