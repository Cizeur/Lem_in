#!/bin/bash

echo "This script runs make fclean for printf and libfg"
rm -r ./libft/*.o
rm -r ./printf/*.o
rm ./libft/libft.a
rm ./printf/libftprintf.a
