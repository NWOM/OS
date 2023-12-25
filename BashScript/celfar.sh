#!/bin/bash

echo "Enter temperature in Celsius:"
read celsius

# Convert Celsius to Fahrenheit
fahrenheit=$(( ($celsius * 9/5) + 32 ))

echo "$celsius degrees Celsius is equal to $fahrenheit degrees Fahrenheit"
