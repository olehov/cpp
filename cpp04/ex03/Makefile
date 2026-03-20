#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogrativ <ogrativ@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 12:38:47 by ogrativ           #+#    #+#              #
#    Updated: 2026/03/20 12:32:55 by ogrativ          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
BUILD_DIR = build
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
NAME = test
GPP = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME): $(OBJS)
	$(GPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(GPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@rmdir --ignore-fail-on-non-empty $(BUILD_DIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)
	@rm -rf $(BUILD_DIR)


re: fclean all

.PHONY: all clean fclean re