#!/bin/bash

rm curry/*.in curry/*.out -f
unzip curry/currydata.zip -d curry
for f in curry/*.in; do
    fn=$(basename $f)
    cat $f | python3 curry_pancake.py > curry_$fn
done
rm curry/*.in curry/*.out -f
