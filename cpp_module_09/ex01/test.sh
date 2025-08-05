#!/usr/bin/env sh

compare() {
    if [[ $1 != $2 ]]; then
        echo "Error: got $1; want $2"
    fi
}

got=$(./RPN "1 1 +")
want=2
compare "$got" "$want"

got=$(./RPN "1 2 +")
want=3
compare "$got" "$want"

got=$(./RPN "1 2 -")
want=-1
compare "$got" "$want"

got=$(./RPN "1     2 -")
want=-1
compare "$got" "$want"

got=$(./RPN "1 a 2" 2>&1)
want=Error
compare "$got" "$want"

got=$(./RPN "8 2 /")
want=4
compare "$got" "$want"

got=$(./RPN "3 0 *")
want=0
compare "$got" "$want"

got=$(./RPN "3 0 /" 2>&1)
want="Error"
compare "$got" "$want"

got=$(./RPN "3 6 3 / *")
want=6
compare "$got" "$want"

got=$(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +")
want=42
compare "$got" "$want"

got=$(./RPN "1 2 * 2 / 2 * 2 4 - +")
want=0
compare "$got" "$want"

got=$(./RPN "7 7 * 7 -")
want=42
compare "$got" "$want"

got=$(./RPN "(1 + 1)" 2>&1)
want=Error
compare "$got" "$want"

got=$(./RPN "+" 2>&1)
want=Error
compare "$got" "$want"

got=$(./RPN "5")
want=5
compare "$got" "$want"

got=$(./RPN "3 4 5 +" 2>&1)
want="Error"
compare "$got" "$want"

got=$(./RPN "5 1 2 + 4 * + 3 -")
want=14
compare "$got" "$want"

got=$(./RPN "0 0 +")
want=0
compare "$got" "$want"

got=$(./RPN "2 3 + 4 5 + *")
want=45
compare "$got" "$want"

got=$(./RPN "8 2 /")
want=4
compare "$got" "$want"

got=$(./RPN "2 3 * 2 * 4 /")
want=3
compare "$got" "$want"

got=$(./RPN "9 8 +" 2>&1)
want="17"
compare "$got" "$want"

got=$(./RPN "2 3 * 2 * 4 / * * *" 2>&1)
want="Error"
compare "$got" "$want"
