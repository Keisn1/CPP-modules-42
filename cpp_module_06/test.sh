#!/usr/bin/env sh

got=$(./convert 0)
want='char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0'

if [ "$got" != "$want" ]; then
    echo "error"
fi

echo "$got" | xxd
echo "$want" | xxd
