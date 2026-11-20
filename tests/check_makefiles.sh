#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
for exercise in cpp[0-4]/ex[0-9][0-9]; do
    echo "Checking $exercise"
    make -C "$exercise" fclean
    make -C "$exercise" -j2
    # A second build must not schedule any compile/link command.
    make -C "$exercise" -q
    make -C "$exercise" clean
    make -C "$exercise" -j2
    make -C "$exercise" re
    make -C "$exercise" -q
    make -C "$exercise" fclean
done
echo 'All Makefiles passed.'
