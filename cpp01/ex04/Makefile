# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 10:11:22 by fde-carv          #+#    #+#              #
#    Updated: 2024/03/18 10:53:58 by fde-carv         ###   ########.fr        #
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
SBLINK			=	\033[5m
FBLINK			=	\033[6m

# -=-=-=-=-=-=- VARIABLES -=-=-=-=-=-=- #
NAME			=	replace
OBJSDIR    		=	objs
OBJS			=	${SRC:%.cpp=${OBJSDIR}/%.o}
INCLUDES		=	-I .
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f
FILE_NAME		?=	input.txt
SRC				=	main.cpp\

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

all:			${NAME}

${OBJSDIR}/%.o: %.cpp
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
				@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

txt:
				@echo ""
				@read -p "Write the name of the .txt arquive: " new_file_name && \
				new_file_name=$$new_file_name".txt" && \
				echo "user: fde-carv   Texto para CPP01 ex04\n" >> $$new_file_name && \
				echo "Eu estou a estudar na 42 e quero ir apanhar ar!" >> $$new_file_name && \
				echo "Aqui vamos nos." >> $$new_file_name && \
				echo "Ja estou cansado de estudar!" >> $$new_file_name && \
				echo "Vou comer qualquer coisa!" >> $$new_file_name && \
				echo "Mas vou querer comer ao ar livre ..." >> $$new_file_name && \
				echo "... e ficar aqui a apanhar SOL!!!" >> $$new_file_name && \
				echo "\n[${WHITE}${YELLOW}$$(echo $$new_file_name)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

clean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

fclean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@rm -f *.txt.replace
				@rm -f *.replace
				@rm -f *.txt
				@rm -f .txt
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo "*.txt files")$(RESET)${WHITE}] ${RED}--> removed${RESET}"
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

re: clean all

.PHONY: all clean re

#txt2:
#				@echo "user: fde-carv   Texto para CPP01 ex04\n" >> $(FILE_NAME)
#				@echo "Eu estou a estudar na 42 e quero ir apanhar ar!" >> $(FILE_NAME)
#				@echo "Aqui vamos nos." >> $(FILE_NAME)
#				@echo "Ja estou cansado de estudar!" >> $(FILE_NAME)
#				@echo "Vou comer qualquer coisa!" >> $(FILE_NAME)
#				@echo "Mas vou querer comer ao ar livre ..." >> $(FILE_NAME)
#				@echo "... e ficar aqui a apanhar SOL!!!" >> $(FILE_NAME)
#				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo $(FILE_NAME))$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"