# **************************************************************************** #
#                                    Config                                    #
# **************************************************************************** #
MAKE = make --no-print-directory --silent
SHELL = bash
# **************************************************************************** #
#                                    NAMES                                     #
# **************************************************************************** #
NAME = libftprintf.a
EXEC = a.out
# **************************************************************************** #
#                                    Paths                                     #
# **************************************************************************** #
INC_PATH        = ./inc/

SRC_PATH        = ./src/

SRC_FILES       = ft_printf.c
SRC_FILES				+= ft_utils.c
SRC_FILES				+= ft_utils2.c
SRC_FILES				+= ft_printf_ptr.c
SRC_FILES				+= ft_printf_hex.c
SRC_FILES				+= ft_printf_str.c
SRC_FILES				+= ft_printf_uns.c

SRC             = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS_DIR				= obj
OBJS				   	= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                   Compiler                                   #
# **************************************************************************** #
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
INC             = -I $(INC_PATH)
# **************************************************************************** #
#                                   Commands                                   #
# **************************************************************************** #
RM              = rm -rf
AR              = ar rcs
MKDIR           = mkdir -p
# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #
 
all: $(NAME)

$(OBJS_DIR):
	@mkdir -p Obj
#	@echo "📋 Objects directory created (Ft_Printf) 📋"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)
#	@echo "🤎 Compilation completed (Ft_Printf) 🤎"

clean:
	$(RM) $(OBJS)
#	@echo "🌷 Objects removed successfully (Ft_Printf)🌷"

fclean: clean
	 $(RM) $(NAME) $(OBJS_DIR)
#	@echo "✨ Program removed successfully (Ft_Printf) ✨"
    
re: fclean all
#		@echo "🦉 Re-compile was successfull (Ft_Printf) 🦉"

