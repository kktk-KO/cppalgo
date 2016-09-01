#!/bin/sh

cat "${1}-profile-raw.csv" | grep "\"" | sed -e "s/,/ /g" | sed -e 's/^"[^\/]*\/\([0-9]\+\)"/\1/' > ${1}-profile.csv
