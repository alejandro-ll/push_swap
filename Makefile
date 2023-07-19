# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 19:08:16 by marvin            #+#    #+#              #
#    Updated: 2023/07/17 19:48:26 by allera-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo final
NAME = push_swap

# Directorios de código fuente y objetos
SRCDIR = src
UTILSDIR = utils
OBJDIR = objs
LIBFTDIR = libft

# Archivos fuente y objetos
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(UTILSDIR)/*.c) $(wildcard $(LIBFTDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.c, $(SRCS))) \
       $(patsubst $(UTILSDIR)/%.c, $(OBJDIR)/%.o, $(filter $(UTILSDIR)/%.c, $(SRCS)))


# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Regla de construcción del archivo final
$(NAME): $(OBJS) $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTDIR)/libft.a

# Regla de construcción de objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(UTILSDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla de construcción de la biblioteca Libft
$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

# Crear directorio de objetos
$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

# Regla para limpiar archivos generados
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re


