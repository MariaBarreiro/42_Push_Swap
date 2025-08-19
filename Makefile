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


LIB_PATH										=	./Libs/42_Libft/
LIB_NAME										= libft.a
LIB													= $(LIB_PATH)$(LIB_NAME)

PRINTF_PATH									= ./Libs/42_Libft/42_Ft_Printf/
PRINTF_NAME									= libftprintf.a
PRINTF											= $(PRINTF_PATH)$(PRINTF_NAME)

INC_PATH										= ./Includes/

SRC_PATH										= ./Src/

SRC_FILES										= push_swap.c

SORTING_SRC_PATH						= $(SRC_PATH)Sorting/

SORTING_SRC_FILES						= bruteforce_sort.c
SORTING_SRC_FILES						+= sorting_utils.c

STACKS_SRC_PATH							= $(SRC_PATH)Stacks/

STACKS_SRC_FILES						= stack_utils.c
STACKS_SRC_FILES						+= stacks_init.c

UTILS_SRC_PATH							= $(SRC_PATH)Utils/

UTILS_SRC_FILES							= utils.c

OPERATIONS_SRC_PATH					= $(SRC_PATH)Operations/

OPERATIONS_SRC_FILES				= base_operations.c
OPERATIONS_SRC_FILES				+= rotate.c
OPERATIONS_SRC_FILES				+= reverse_rotate.c
OPERATIONS_SRC_FILES				+= swap.c
OPERATIONS_SRC_FILES				+= push.c


SRC													= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC													+= $(addprefix $(OPERATIONS_SRC_PATH), $(OPERATIONS_SRC_FILES))
SRC													+= $(addprefix $(SORTING_SRC_PATH), $(SORTING_SRC_FILES))
SRC													+= $(addprefix $(STACKS_SRC_PATH), $(STACKS_SRC_FILES))
SRC													+= $(addprefix $(UTILS_SRC_PATH), $(UTILS_SRC_FILES))

OBJS_DIR										= Obj
OBJS												= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

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
	@echo "🍄 Libft compilation completed!"

$(OBJS_DIR):
	@mkdir -p Obj
	@echo "📋 Objects directory created!"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) $(PRINTF) -o $(NAME)
	@echo "🤎 Compilation completed!"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(RM) $(OBJS)
	@echo "🌷 Objects removed successfully!"

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "✨ Program removed successfully!"

re: fclean all
		@echo "🦉 Re-compile was successfull!"

