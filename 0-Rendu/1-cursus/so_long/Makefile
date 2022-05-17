# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 10:09:10 by mdoquocb          #+#    #+#              #
#    Updated: 2022/04/29 17:20:30 by mdoquocb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PROJECT = so_long

	#  BINARY  #

BIN_PATH = Bin/

BIN_NAME = $(PROJECT)

BIN = $(addprefix $(BIN_PATH),$(BIN_NAME))

	#  INCLUDES  #

INC_PATH = ./Includes

INC_FLAGS += -I $(INC_PATH)

	#  LIB => libft  #

LIB_NAME = ft

LIB_PATH = ../libft/

LIB_INC_PATH = includes

LIB_BIN_PATH = Bin

LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

INC_FLAGS += -I $(LIB_PATH)$(LIB_INC_PATH)

LIB_FLAGS = -L $(LIB_PATH)$(LIB_BIN_PATH) -l $(LIB_NAME)

	#  LIB => minilibx #

LIB2_NAME = mlx

LIB2_PATH = ../minilibx/

LIB2 = $(addprefix $(LIB2_PATH),$(LIB2_NAME))

INC2_FLAGS += -I $(LIB2_PATH)

LIB2_FLAGS = -L $(LIB2_PATH) -l $(LIB2_NAME) -framework OpenGL -framework Appkit

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

CC_FLAGS = -Wall -Wextra -Werror 

CL = rm -rf


	#  COLORS STR #

GREEN = "\x1b[32m""\x1b[M"

RED= "\x1b[31m""\x1b[M"

BLUE = "\x1b[34m""\x1b[M"

	#  COLORS  #

ENDCOL = \033[0m

REDS = \033[1;31m

YEL = \033[1;33m

ORG = \033[0;33m

GRN = \033[1;32m

DGRAY = \033[1;30m

BLU = \033[1;34m

	#  COMPILATION  #

all: $(BIN) 
		@echo $(GREEN) Compilation $(PROJECT) is completed !!

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@$(CC) $(CC_FLAGS) $(INC_FLAGS) $(INC2_FLAGS) -c $< -o $@
		@echo $(BLUE) $(notdir $@) is created !!

$(BIN): libft minilibx title directory $(OBJ)
		@$(CC) $(OBJ) $(LIB_FLAGS) $(LIB2_FLAGS) -o $(BIN)
		@echo $(BLUE) $(notdir $(BIN)) is created !!

title: 
		@echo $(GREEN)******************$(PROJECT)******************

libft: 
		@$(MAKE) -C ../libft

minilibx:
		@$(MAKE) -C ../minilibx

directory: 	
		@mkdir -p $(OBJ_PATH) > /dev/null 2>&1 || true
		@echo $(BLUE) Binary $(PROJECT) directory created !!

norm:
		@printf "\n${GRN}****************${YEL} NORMINETTE ${GRN}****************${ENDCOL}\n"
		@printf "\n${GRN}lib$(LIB_NAME):${BLU}\n\n"
		@norminette $(LIB_PATH)$(INC_PATH)
		@norminette $(LIB_PATH)$(SRC_PATH)
		@printf "\n${GRN}$(PROJECT):${BLU}\n\n"
		@norminette $(INC_PATH)
		@norminette $(SRC_PATH)
		@printf "${NOCOL}"

all_test: test_error test

test: big mini mandatory bonus height long

big:
		@leaks -atExit -- ./Bin/so_long Maps/test/big.ber

height:
		@leaks -atExit -- ./Bin/so_long Maps/test/height.ber

long:
		@leaks -atExit -- ./Bin/so_long Maps/test/long.ber

mini:
		@leaks -atExit -- ./Bin/so_long Maps/test/mini.ber

mandatory:
		@leaks -atExit -- ./Bin/so_long Maps/test/mandatory.ber

bonus:
		@leaks -atExit -- ./Bin/so_long Maps/test/bonus.ber

test_error: bad_extension open_1 open_2 open_3 square

bad_path:
		@leaks -atExit -- ./Bin/so_long Maps/error/bad_extension.ber

bad_extension:
		@leaks -atExit -- ./Bin/so_long Maps/error/bad_extension.bir

open_1:
		@leaks -atExit -- ./Bin/so_long Maps/error/open_1.ber

open_2:
		@leaks -atExit -- ./Bin/so_long Maps/error/open_2.ber

open_3:
		@leaks -atExit -- ./Bin/so_long Maps/error/open_3.ber

square:
		@leaks -atExit -- ./Bin/so_long Maps/error/square.ber

push:
		@git add .
		@read -p "name of commit: " INP \
		&& git commit -m "$${INP}"
		@git push

clean: 
		@$(CL) $(OBJ)
		@$(MAKE) clean -C ../libft
		@$(MAKE) clean -C ../minilibx
		@echo $(RED) Object $(notdir $(OBJ)) is delete !

fclean: clean 
		@$(CL) $(BIN)
		@$(MAKE) fclean -C ../libft
		@$(MAKE) clean -C ../minilibx
		@echo $(RED) Binary $(notdir $(BIN)) is delete !

finish: 
		@$(CL) $(BIN_PATH)
		@$(MAKE) finish -C ../libft
		@$(MAKE) clean -C ../minilibx
		@echo $(RED) All $(PROJECT) is delete !

re:	fclean all

.PHONY :	all clean fclean finish re directory title
