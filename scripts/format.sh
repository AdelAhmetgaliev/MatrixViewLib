#!/usr/bin/env bash

set -x
find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i
