#!/bin/bash

PS=./push_swap
VG="valgrind --leak-check=full --errors-for-leak-kinds=all --track-origins=yes"

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

DEBUG_LOG=debug_inputs.log
> $DEBUG_LOG

run_test () {
    NAME="$1"
    CMD="$2"
    EXPECT_ERROR="$3"

    echo "▶ $NAME"
    if [ "$EXPECT_ERROR" = "error" ]; then
        OUTPUT=$(eval "$CMD" 2>&1)
        if echo "$OUTPUT" | grep -q "Error"; then
            echo -e "${GREEN}✔ Correctly errored${NC}"
        else
            echo -e "${RED}✘ Expected Error, got:${NC}"
            echo "$OUTPUT"
        fi
    else
        OUTPUT=$(eval "$CMD" 2>&1)
        if echo "$OUTPUT" | grep -q "Error"; then
            echo -e "${RED}✘ Unexpected Error${NC}"
            echo "$OUTPUT"
        else
            echo -e "${GREEN}✔ OK${NC}"
        fi
    fi
    echo
}

run_valgrind () {
    NAME="$1"
    CMD="$2"

    echo "▶ $NAME (valgrind)"
    eval "$VG $CMD" > vg_out.txt 2>&1
    if grep -q "ERROR SUMMARY: 0 errors" vg_out.txt; then
        echo -e "${GREEN}✔ No Valgrind errors${NC}"
    else
        echo -e "${RED}✘ Valgrind errors:${NC}"
        grep "Invalid" vg_out.txt
        grep "ERROR SUMMARY" vg_out.txt
    fi
    echo
}

echo "============================"
echo " push_swap automated tests "
echo "============================"
echo

### VALID INPUTS ###
run_test "Valid small"            "$PS 3 1 2" ok
run_test "Already sorted"         "$PS 1 2 3 4 5" ok
run_test "Reverse sorted"         "$PS 5 4 3 2 1" ok
run_test "Quoted input"           "$PS \"4 2 5 1 3\"" ok
run_test "Mixed argv"             "$PS 1 \"2 3\" 4" ok

### INVALID INPUTS ###
run_test "Comma separator"        "$PS \"1,2 3\"" error
run_test "Sign glued"             "$PS \"12-3 4\"" error
run_test "Duplicate numbers"      "$PS 1 2 3 2" error
run_test "Overflow"               "$PS \"2147483648\"" error
run_test "Bad sign"               "$PS \"+-42\"" error

### VALGRIND CHECKS ###
run_valgrind "Valgrind small"      "$PS 1"
run_valgrind "Valgrind small"      "$PS 3 2 1"
run_valgrind "Valgrind edge"       "$PS \"3 2 1 0\""
run_valgrind "Valgrind medium"     "$PS \"8 3 7 1 5 2 6 4\""

rm -f vg_out.txt

############################################
# RANDOM STRESS TESTING
############################################

RANDOM_SEED=42
ITERATIONS=100
SMALL_N=10
MEDIUM_N=100

echo "============================"
echo " Random stress tests "
echo "============================"
echo

# Generate unique random numbers
gen_unique_randoms () {
    COUNT=$1
    MAX=100000
    shuf -i 0-$MAX -n $COUNT
}

rm -f debug_inputs.log

run_random_test () {
    NAME="$1"
    COUNT="$2"
    MODE="$3"   # argv | quoted | valgrind

    NUMS=$(gen_unique_randoms $COUNT | tr '\n' ' ')
    CMD="$PS $NUMS"

    if [ "$MODE" = "quoted" ]; then
        CMD="$PS \"$NUMS\""
    fi

    echo "▶ $NAME ($COUNT numbers)"

    if [ "$MODE" = "valgrind" ]; then
        $VG $CMD > vg_rand.txt 2>&1
        if grep -q "ERROR SUMMARY: 0 errors" vg_rand.txt; then
            echo -e "${GREEN}✔ Valgrind OK${NC}"
        else
            echo -e "${RED}✘ Valgrind errors${NC}"
            echo "[VALGRIND ERROR] $CMD" >> $DEBUG_LOG
            grep "Invalid" vg_rand.txt
            grep "ERROR SUMMARY" vg_rand.txt
        fi
    else
        OUTPUT=$(eval "$CMD" 2>&1)
        if echo "$OUTPUT" | grep -q "Error"; then
            echo -e "${RED}✘ Unexpected Error${NC}"
            echo "[UNEXPECTED ERROR] $CMD" >> $DEBUG_LOG
            echo "↳ INPUT:"
            echo "$CMD"
            echo "↳ OUTPUT:"
            echo "$OUTPUT"
        else
            echo -e "${GREEN}✔ OK${NC}"
        fi
    fi
    echo
}

# Seed randomness (for reproducibility)
RANDOM=$RANDOM_SEED

### SMALL RANDOM TESTS ###
for i in $(seq 1 $ITERATIONS); do
    run_random_test "Random small argv #$i" $SMALL_N argv
done

### MEDIUM RANDOM TESTS ###
for i in $(seq 1 $ITERATIONS); do
    run_random_test "Random medium quoted #$i" $MEDIUM_N quoted
done

### VALGRIND RANDOM TESTS ###
for i in $(seq 1 10); do
    run_random_test "Random valgrind #$i" 20 valgrind
done

rm -f vg_rand.txt

############################################
# INVALID CHAR / GRAMMAR STRESS TESTS
############################################

echo "============================"
echo " Invalid char stress tests "
echo "============================"
echo

INVALID_INPUTS=(
    "\"a100 5 213\""
    "\"100a 5\""
    "\"10a0\""
    "a 500 15 315"
    "1 b 2"
    "\"1_000\""
    "\"12.5\""
    "\"1e3\""
    "\"1+2\""
    "\"3-4\""
    "\"+-42\""
    "\"-+42\""
    "\"42+\""
    "\"42-\""
    "\"4-2\""
    "\"++1\""
    "\"--1\""
    "\"1 - 2\""
    "\"1 + 2\""
    "\"1--2\""
    "\"1,,2\""
    "\"a-1 +2b 003\""
    "a"
    "--"
    "-a"
    "\"1-\""
)

for INPUT in "${INVALID_INPUTS[@]}"; do
    echo "▶ Invalid input test:"
    echo "   $PS $INPUT"

    OUTPUT=$(eval "$PS $INPUT" 2>&1)

    if echo "$OUTPUT" | grep -q "Error"; then
        echo -e "${GREEN}✔ Correctly rejected${NC}"
        echo "[EXPECTED ERROR] $PS $INPUT" >> $DEBUG_LOG
    else
        echo -e "${RED}✘ FAILED — SHOULD ERROR${NC}"
        echo "[BUG] $PS $INPUT" >> $DEBUG_LOG
        echo "$OUTPUT"
    fi
    echo
done