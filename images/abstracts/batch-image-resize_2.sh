#!/bin/bash

WIDTH="100"
TAG="100w"

if [ ! -d $TAG ]; then
  mkdir $TAG
fi

 mogrify             \
-resize $WIDTH     \
-format jpg       \
-quality 100       \
-path $TAG      \
 *.jpg

for f in $TAG/*.jpg; do mv "$f" "${f%.jpg}-$TAG.jpg"; done
