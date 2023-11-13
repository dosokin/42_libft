CC=cc
NAME = libft.a
SRCS = ft_memmove.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_striteri.c ft_putchar_fd.c ft_strmapi.c ft_split.c ft_strtrim.c ft_strjoin.c ft_itoa.c ft_substr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_memcpy.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_memset.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strnstr.c ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_atoi.c ft_bzero.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
HEADER = libft.h
OBJS = $(SRCS:.c=.o)
OBJSB = $(BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)
	rm -f $(OBJSB)

re : fclean all

bonus : $(OBJS) $(OBJSB)
	ar -rc $(NAME) -o $^

.PHONY: all fclean clean re bonus
