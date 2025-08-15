# **************************************************************************** #
#                                    Config                                    #
# **************************************************************************** #

MAKE = make --no-print-directory --silent
SHELL = bash

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME = push_swap 

# **************************************************************************** #
#                                    Paths                                     #
# **************************************************************************** #


LIB_PATH						=	./Libs/42_Libft/
LIB_NAME						= libft.a
LIB								= $(LIB_PATH)$(LIB_NAME)

PRINTF_PATH						= ./Libs/42_Libft/42_Ft_Printf/
PRINTF_NAME						= libftprintf.a
PRINTF							= $(PRINTF_PATH)$(PRINTF_NAME)

INC_PATH						= ./Includes/

SRC_PATH						= ./Src/

SRC_FILES						= main.c
SRC_FILES						+= stacks_init.c

#MAP_SRC_PATH					= $(SRC_PATH)Maps/

#MAP_SRC_FILES					= handle_map.c
#MAP_SRC_FILES					+= validate_map.c
#MAP_SRC_FILES					+= validate_map2.c

SRC								= $(addprefix $(SRC_PATH), $(SRC_FILES))
#SRC							+= $(addprefix $(MAP_SRC_PATH), $(MAP_SRC_FILES))

OBJS_DIR						= Obj
OBJS							= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                   Compiler                                   #
# **************************************************************************** #

CC   			           = cc
CFLAGS          		   = -Wall -Wextra -Werror -g
INC            		       = -I $(INC_PATH)
INC						   += -I $(LIB_PATH)/42_Gnl/ 
INC						   += -I $(LIB_PATH)
INC						   += -I $(PRINTF_PATH)

# **************************************************************************** #
#                                   Commands                                   #
# **************************************************************************** #

RM              = rm -rf

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #
 
all: depends $(NAME)

depends: 
	@$(MAKE) -C $(PRINTF_PATH)
	@$(MAKE) -C $(LIB_PATH)
	@echo "🍄 Libft compilation completed 🍄"

$(OBJS_DIR):
	@mkdir -p Obj
	@echo "📋 Objects directory created 📋"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) depends $(LIB)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) $(PRINTF) -o $(NAME)
	@echo "🤎 Compilation completed 🤎"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(RM) $(OBJS)
	@echo "🌷 Objects removed successfully 🌷"

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "✨ Program removed successfully ✨"

re: fclean all
		@echo "🦉 Re-compile was successfull 🦉"

