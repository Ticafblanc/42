# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 10:09:10 by mdoquocb          #+#    #+#              #
#    Updated: 2022/03/23 10:16:18 by mdoquocb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = push_swap

	#  BINARY  #

BIN_PATH = Bin/

BIN_NAME = $(PROJECT)

BIN = $(addprefix $(BIN_PATH),$(BIN_NAME))

	#  SOURCES  #

SRC_PATH = Sources/

SRC_NAME = $(notdir $(wildcard Sources/*.c))

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

	#  OBJECTS  #

OBJ_PATH = $(BIN_PATH)Objects/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

	#  FLAGS  #

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -I./includes

CL = rm -rf

LIBFT = ../libft/Bin/libft.a

	#  COLORS  #

GREEN = "\x1b[32m""\x1b[M"

RED = "\x1b[31m""\x1b[M"

BLUE = "\x1b[34m""\x1b[M"

	#  COMPILATION  #

all: $(BIN) 
		@echo $(GREEN) Compilation $(PROJECT) is completed !!

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@$(CC) $(CC_FLAGS) -c $< -o $@
		@echo $(BLUE) $(notdir $@) is created !!

$(BIN): title libft directory $(OBJ)
		@$(CC) $(OBJ) $(LIBFT) -o $(BIN)
		@echo $(BLUE) $(notdir $(BIN)) is created !!

title: 
		@echo $(GREEN)****************$(PROJECT)****************

libft: 
		@$(MAKE) -C ../libft

directory: 	
		@mkdir -p $(OBJ_PATH) > /dev/null 2>&1 || true
		@echo $(BLUE) Binary $(PROJECT) directory created !!

command:
		@echo $(GREEN) "make/ to start!"
		@echo $(GREEN) "make eval/ to eval!"
	# ARG="`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`"; ./Bin/push_swap $ARG | ./Bin/checker_Mac $ARG #
		@echo $(GREEN) "make v3/ push_swap_visualizer -1 -> 1!"
		@echo $(GREEN) "make v5/ push_swap_visualizer -2 -> 2!"
		@echo $(GREEN) "make v100/ push_swap_visualizer -49 -> 50!"
		@echo $(GREEN) "make v500/ push_swap_visualizer -249 -> 250!"
	# python3 Bin/pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` #
	# `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` #
	# bash Bin/basic_test.sh #
	# bash Bin/loop.sh 100 10 #
		@echo $(GREEN) "make clean/ remove all object!"
		@echo $(GREEN) "make fclean/ remove all binary!"
		@echo $(GREEN) "make finish/ remove Bin directory!"


ARG = `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`

eval: all mac check pst viz nor test

nor:
		@echo $(GREEN) "norminette push_swap.c!"
		norminette includes/
		@echo $(GREEN) "norminette push_swap.h!"
		norminette Sources/
		@echo $(GREEN) "norminette libft.h!"
		norminette ../libft/includes/
		@echo $(GREEN) "norminette libft.c!"
		norminette ../libft/Sources/
		@echo $(GREEN) "norminette checker.h!"
		norminette Checker/includes/
		@echo $(GREEN) "norminette checker.c!"
		norminette Checker/Sources/

test: basic loop

basic:
		@cd Bin/push_swap_tester/; bash basic_test.sh

l3:
		@cd Bin/push_swap_tester/; bash loop.sh 3 10

l5:
		@cd Bin/push_swap_tester/; bash loop.sh 5 10

l100:
		@cd Bin/push_swap_tester/; bash loop.sh 100 10

l500:
		@cd Bin/push_swap_tester/; bash loop.sh 500 10
	
loop: l3 l5 l100 l500

v3:
		python3 Bin/pyviz.py `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`

v5:
		python3 Bin/pyviz.py `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`
		
v100:
		python3 Bin/pyviz.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`

v500:
		python3 Bin/pyviz.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

check:
		@$(MAKE) -C ./Checker
		@cp  Checker/Bin/checker Bin/ > /dev/null 2>&1 || true
		@echo $(BLUE) checker home made is ready !!
mac:
		@cp Tester/checker_Mac Bin/ > /dev/null 2>&1 || true
		@echo $(BLUE) checker_Mac is ready !!

pst:
		@mkdir -p Bin/push_swap_tester/ > /dev/null 2>&1 || true
		@cp -r Tester/push_swap_tester/ Bin/push_swap_tester/ > /dev/null 2>&1 || true
		@echo $(BLUE) push_swap_tester is ready !!

viz:
		@cp Tester/pyviz.py Bin/ > /dev/null 2>&1 || true
		@echo $(BLUE) push_swap_visualizer is ready !!

clean: 
		@$(CL) $(OBJ)
		@$(MAKE) clean -C ../libft
		@echo $(RED) Object $(notdir $(OBJ)) is delete !

fclean: clean 
		@$(CL) $(BIN)
		@$(MAKE) fclean -C ../libft
		@echo $(RED) Binary $(notdir $(BIN)) is delete !

finish: 
		@$(CL) $(BIN_PATH)
		@$(MAKE) finish -C ../libft
		@$(MAKE) finish -C Checker
		@echo $(RED) All $(PROJECT) is delete !

re:	fclean all

.PHONY :	all clean fclean finish re directory
