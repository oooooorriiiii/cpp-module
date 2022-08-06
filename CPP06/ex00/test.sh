#!/usr/bin/env bash

_green="\e[32m"
_reset="\e[0m"

EXECUTE_FILE=./convert

while read line
do
  TEST_STRING=$line
  echo -e "\n************************************************"
  echo -e " input:" $_green $TEST_STRING $_reset
  $EXECUTE_FILE $TEST_STRING
  echo -e "************************************************"
done < testlist.txt

