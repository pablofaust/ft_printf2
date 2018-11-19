# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaust <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:46:59 by pfaust            #+#    #+#              #
#    Updated: 2018/10/17 09:19:43 by pfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
HEADER = includes/libft.h
SRC = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
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
	ft_never_negative ft_itoa_ll ft_itoa_base_uint

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(SRC) \
	 ))

all : $(NAME)

$(NAME): objs $(OBJS)
	@printf  "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@ar rcs $(NAME) $(OBJS)

objs/%.o: src/%.c $(HEADER)
	@printf  "\033[1:92m Bin Compiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)
	@printf "\033[A\033[2K"
objs:
	@mkdir -p objs/
clean :
	@rm -rf $(OBJS)
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
fclean : clean
	@rm -rf $(NAME)
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
re : fclean all
