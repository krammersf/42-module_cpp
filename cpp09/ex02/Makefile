# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 14:23:56 by fde-carv          #+#    #+#              #
#    Updated: 2024/04/20 12:43:52 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-=-=- COLORS -=-=-=-=-=-=- #
RESET			=	\033[0m
BLACK 			=	\033[1;30m
RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
BLUE			=	\033[1;34m
PURPLE 			=	\033[1;35m
CYAN 			=	\033[1;36m
WHITE 			=	\033[1;37m
BOLD			=	\033[1m
FAINT			=	\033[2m
ITALIC			=	\033[3m
ULINE			=	\033[4m
SBLINK			=	\033[5m
FBLINK			=	\033[6m
REVCOL			=	\033[7m
CORESETEAL		=	\033[8m
CROSS			=	\033[9m

# -=-=-=-=-=-=- VARIABLES -=-=-=-=-=-=- #
NAME			=	PmergeMe
OBJSDIR    		=	objs
OBJS			=	${SRC:%.cpp=${OBJSDIR}/%.o}
INCLUDES		=	-I .
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f
SRC				=	main.cpp\
					PmergeMe.cpp\

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

all:			${NAME}

${OBJSDIR}/%.o: %.cpp
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
				@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

run1:
				@clear; \
				echo; \
				read -p "How many elements do you want to handle: " NUM_ELEMENTS; \
				clear && make re > /dev/null && ./PmergeMe `shuf -i 1-100000 -n $$NUM_ELEMENTS | tr "\n" " " `

run2:
				@clear; \
				echo; \
				read -p "How many elements do you want to handle: " NUM_ELEMENTS; \
				clear && make re > /dev/null && valgrind ./PmergeMe `shuf -i 1-100000 -n $$NUM_ELEMENTS | tr "\n" " " `

run3:
				@clear; \
				echo; \
				make re && clear && ./PmergeMe `shuf -i 1-1000 -r -n 3000 | tr "\n" " " `

clean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@echo "\n[${WHITE}${RED}$(CROSS)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RESET}\n"

re: clean all

.PHONY: all clean re run1