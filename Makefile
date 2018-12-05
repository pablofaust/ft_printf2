# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaust <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 11:10:04 by pfaust            #+#    #+#              #
#    Updated: 2018/12/05 10:35:41 by pfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

FLAGS 		= -Wall -Wextra -Werror

LIBS 		= ./libs/libft/libft.a

INCLUDES 	= -I includes/ \
		  -I ./libs/libft/includes/
HEADER		= ./includes/ft_printf.h
SRC 		= ft_printf \
			  conv_char \
			  conv_float \
			  conv_int \
			  conv_parsing \
			  conversions \
			  double_binary \
			  flags \
			  handle_floats \
			  list \
			  parsing \
			  plain_parsing \
			  precision \
			  handling \
			  width \
			  write_char \
			  write_int \

LIB_SRC = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_itoa ft_lstadd ft_lstdel \
	ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc \
	ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel \
	ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd \
	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
	ft_strdel ft_strdup ft_strequ ft_striter ft_striteri \
	ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
	ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew \
	ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub \
	ft_strtrim ft_tolower ft_toupper ft_pow ft_wordlen \
	ft_nbwords ft_itoa_base_ll ft_itoa_base_ull ft_itoa_base \
	ft_never_negative ft_itoa_ll ft_itoa_base_uint \
	ft_itoa_db ft_nb_entiers ft_print_bits ft_binary_long\
	ft_truncate ft_cpyalpha ft_putbinstr ft_dir_strncpy \
	ft_int_pow

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(SRC) \
	 ))

LIB_OBJS = $(addprefix libs/libft/objs/, $(addsuffix .o, \
	   $(LIB_SRC) \
	 ))

all: $(NAME)

$(NAME): objs $(OBJS)
	@printf  "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@ar rcs $(NAME) $(OBJS) $(LIB_OBJS)
	ranlib $(NAME)

objs/%.o: src/%.c $(HEADER)
	@printf  "\033[1:92m Bin Compiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES) 
	@printf "\033[A\033[2K"

objs:
	@mkdir -p objs/

clean:
	@rm -rf objs/
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -rf $(LIB_SRC)
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@make -C ./libs/libft clean
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libs/libft/libft.a
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"

re:
	@$(MAKE) fclean
	@make -C ./libs/libft
	@$(MAKE)

.PHONY: 	all clean fclean re
