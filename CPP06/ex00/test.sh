#!/usr/bin/env bash

_green="\e[32m"
_reset="\e[0m"

EXECUTE_FILE=./convert

while read -r line
do
  TEST_STRING=`echo $line | tr -d '\n' | tr -d '\r'`
  echo -e "\n************************************************"
  echo -e " input:" $_green $TEST_STRING $_reset
  $EXECUTE_FILE $TEST_STRING
  echo -e "************************************************"
done < testlist.txt

