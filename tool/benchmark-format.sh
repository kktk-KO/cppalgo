#!/bin/sh

cat "${1}-profile.csv" \
  | grep "\"" \
  | sed -e "s/,/ /g" \
  | sed -e 's/k/000/' \
  | sed -e 's/M/000000/' \
  | sed -e "s/^\"\([^\/]*\)\/\([0-9]\+\)\(\/[^\/]*\)*\" [^ ]* \([^ ]*\).*/\#\#teamcity[buildStatisticValue key=\'profile_\1_\2\' value=\'\4\']/" \
