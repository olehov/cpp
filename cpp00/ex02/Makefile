# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 12:38:47 by ogrativ           #+#    #+#              #
#    Updated: 2025/05/12 12:55:36 by ogrativ          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Account.cpp tests.cpp
BUILD_DIR = build
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
NAME = account
GPP = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror

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