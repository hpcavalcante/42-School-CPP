#!/bin/bash

test1=$(./swap tests/test1 rato gato)
test2=$(./swap tests/test2 the a)
test3=$(./swap tests/test3 cloud sky)
test4=$(./swap tests/test4 test void)

expected_test1="O gato roeu a roupa do rei de Roma"
expected_test2="The quick brown fox jumps over a lazy dog"
expected_test3="The sun is shining, the birds are singing"
expected_test4=""

$test1
$test2
$test3
$test4

if diff tests/test1.replace <(echo -n "$expected_test1"); then
    echo -e "Test 1 \033[32m[OK]\033[0m"
	cat tests/test1.replace
	echo
else
    echo -e "Test 1 \033[31m[KO]\033[0m"
fi

if diff tests/test2.replace <(echo -n "$expected_test2"); then
    echo -e "Test 2 \033[32m[OK]\033[0m"
	cat tests/test2.replace
	echo
else
    echo -e "Test 2 \033[31m[KO]\033[0m"
fi

if diff tests/test3.replace <(echo -n "$expected_test3"); then
    echo -e "Test 3 \033[32m[OK]\033[0m"
	cat tests/test3.replace
	echo
else
    echo -e "Test 3 \033[31m[KO]\033[0m"
fi

if diff tests/test4.replace <(echo -n "$expected_test4"); then
    echo -e "Test 4 \033[32m[OK]\033[0m"
	cat tests/test4.replace
	echo
else
    echo -e "Test 4 \033[31m[KO]\033[0m"
fi

rm tests/test1.replace tests/test2.replace tests/test3.replace tests/test4.replace