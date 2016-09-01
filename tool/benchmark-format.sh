#!/bin/sh

cat "${1}-profile-raw.csv" | grep "\"" | sed -e "s/,/ /g" | sed -e 's/^"[^\/]*\/\([0-9]\+\)"/\1/' | sed -e 's/k/000/' | sed -e 's/M/000000/' > ${1}-profile.csv
