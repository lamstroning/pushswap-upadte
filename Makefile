# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: -tdontos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by tdontos-          #+#    #+#              #
#    Updated: 2019/05/29 15:37:44 by tdontos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINDIR		= ./bin/
OBJDIR		= ./obj/
CHECKERNAME = checker
CHECKERDIR = ./checker/
all:
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)
	make -C $(CHECKERDIR)
# 	make -C push_swap
# 	cp ./push_swap/push_swap $(BINDIR)

clean:
	rm -rf $(BINDIR)
	make -C checker clean
# 	make -C push_swap clean

fclean:
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
	make -C checker fclean
# 	make -C push_swap fclean

re: fclean all