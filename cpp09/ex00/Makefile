# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 14:23:56 by fde-carv          #+#    #+#              #
#    Updated: 2024/04/22 09:18:19 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-=-=- COLORS -=-=-=-=-=-=- #
RESET			=	\033[0m
BLACK			=	\033[1;30m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
PURPLE			=	\033[1;35m
CYAN			=	\033[1;36m
WHITE			=	\033[1;37m
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
NAME			=	btc
OBJSDIR			=	objs
OBJS			=	${SRC:%.cpp=${OBJSDIR}/%.o}
INCLUDES		=	-I .
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f
SRC				=	main.cpp\
					BitcoinExchange.cpp\

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):		${OBJS} #input.csv
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

input.csv:
				@if [ ! -e input.csv ]; then \
					if [ -e ../subject/input.csv ]; then \
						cp ../subject/input.csv .; \
					fi \
				fi

all:			${NAME}

${OBJSDIR}/%.o: %.cpp
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
				@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

download:
				@wget -O cpp_09.tgz https://cdn.intra.42.fr/document/document/24349/cpp_09.tgz > /dev/null 2>&1
				@tar -xzf cpp_09.tgz
				@rm cpp_09.tgz
				@echo "\n[${WHITE}${BLUE}CPP09 ex00 files$(RESET)${WHITE}] ${GREEN}--> $(SBLINK)Downloaded and Ready${RESET}\n"

txt:
				@echo "date | value" > 1_input.txt
				@echo "2011-01-03 | 3" >> 1_input.txt
				@echo "2011-01-03 | 2" >> 1_input.txt
				@echo "2011-01-03 | 1" >> 1_input.txt
				@echo "2011-01-03 | 1.2" >> 1_input.txt
				@echo "2011-01-09 | 1" >> 1_input.txt
				@echo "2012-01-11 | -1" >> 1_input.txt
				@echo "2001-42-42" >> 1_input.txt
				@echo "2012-01-11 | 1" >> 1_input.txt
				@echo "2012-01-11 | 2147483648" >> 1_input.txt
				@echo "\n[${WHITE}${YELLOW}$$(echo 1_input.txt)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

				@echo " 	date | value" > 2_input.txt
				@echo "2012-01-03 | 1" >> 2_input.txt
				@echo "2012-01-03 |2		 " >> 2_input.txt
				@echo "2012-01-03 |  3" >> 2_input.txt
				@echo "2012-01-03 |	 4" >> 2_input.txt
				@echo "2012-01-03 | 	5" >> 2_input.txt
				@echo "2012-12-01 |6.00	" >> 2_input.txt
				@echo "" >> 2_input.txt
				@echo " " >> 2_input.txt
				@echo "	" >> 2_input.txt
				@echo "2012-01-03 |	7" >> 2_input.txt
				@echo "2012-01-09 | 1.0." >> 2_input.txt
				@echo "2012-01-09 | 1.a" >> 2_input.txt
				@echo "2012-01-09 | 1. 9" >> 2_input.txt
				@echo "2012-01-03 | 1.2" >> 2_input.txt
				@echo "2012-01-11 | -1" >> 2_input.txt
				@echo "2012-01-11 | f" >> 2_input.txt
				@echo "2001-42-42" >> 2_input.txt
				@echo "2012-01-11 | 1000" >> 2_input.txt
				@echo "2012-01-11 | 1001" >> 2_input.txt
				@echo "2012-01-11 | &" >> 2_input.txt
				@echo "2012-01-11 | ' '" >> 2_input.txt
				@echo "2023-12-31 | 0.2" >> 2_input.txt
				@echo "20120111 | 5" >> 2_input.txt
				@echo "2012-02-30 | 5" >> 2_input.txt
				@echo "2012-04-31 | 5" >> 2_input.txt
				@echo "2024-12-31 | 3.2" >> 2_input.txt
				@echo "0000-12-31 | 3.2" >> 2_input.txt
				@echo "2012-00-31 | 3.2" >> 2_input.txt
				@echo "2012-12-00 | 3.2" >> 2_input.txt
				@echo "2012-12-01 | 2.5" >> 2_input.txt
				@echo "2012-12-01 |." >> 2_input.txt
				@echo "2012-12-01 |.." >> 2_input.txt
				@echo "2012-12-01 |..." >> 2_input.txt
				@echo "2012-12-01 | 9.5" >> 2_input.txt
				@echo "2012-12-01 |...." >> 2_input.txt
				@echo "2012-12-01 | 2.5 		''" >> 2_input.txt
				@echo "2012-12-01 | 2.5 		\"\"" >> 2_input.txt
				@echo "2012-12-01 | 33.5" >> 2_input.txt
				@echo "2012-12-01 |.5" >> 2_input.txt
				@echo "2012-12-01 |.&5" >> 2_input.txt
				@echo "2012-12-01 |%5" >> 2_input.txt
				@echo "2012-12-01 | 100.54   " >> 2_input.txt
				@echo "2012-12-01 | 100.5.44   " >> 2_input.txt
				@echo "2012-12-01 | 100.544  5 " >> 2_input.txt
				@echo "2012-12-01 | 100.001  %  " >> 2_input.txt
				@echo "2012-12-01 | 100.1234567890 " >> 2_input.txt
				@echo "2012/12/01 | 100.9 " >> 2_input.txt
				@echo "2012-12~01 | 100.8 " >> 2_input.txt
				@echo "2012~12-01 | 100.7 " >> 2_input.txt
				@echo "2012-12-01 | 9.1 " >> 2_input.txt
				@echo "2012-12-01 |  " >> 2_input.txt
				@echo "2012-12-01 |" >> 2_input.txt
				@echo "2012-12-01 | 	 	 	 " >> 2_input.txt
				@echo "[${WHITE}${YELLOW}$$(echo 2_input.txt)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

				@echo " 	dated | value" 	> 3_input.txt
				@echo "2011-01-03 | 3" >> 3_input.txt
				@echo "2011-01-03 | 2" >> 3_input.txt
				@echo "2011-01-03 | 1" >> 3_input.txt
				@echo "2011-01-03 | 1.2" >> 3_input.txt
				@echo "[${WHITE}${YELLOW}$$(echo 3_input.txt)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"
				
				@wget -O cpp_09.tgz https://cdn.intra.42.fr/document/document/24349/cpp_09.tgz > /dev/null 2>&1
				@mv cpp_09.tgz 4_input.txt
				@echo "[${WHITE}${YELLOW}$$(echo 4_input.txt)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"
				
				@wget -O cpp_09.tgz https://cdn.intra.42.fr/pdf/pdf/124521/en.subject.pdf > /dev/null 2>&1
				@mv cpp_09.tgz 5_input.txt
				@echo "[${WHITE}${YELLOW}$$(echo 5_input.txt)$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

clean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@rm -rf output.log
				@echo "\n[${WHITE}${RED}$(CROSS)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RESET}\n"

fclean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@rm -rf output.log
				@rm -rf cpp_09
				@for file in *.txt; do \
					if [ -e "$$file" ]; then \
						rm "$$file"; \
					fi \
				done
				@for file in *.csv; do \
					if [ -e "$$file" ]; then \
						rm "$$file"; \
					fi \
				done
				@echo "\n[${WHITE}${RED}$(CROSS)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RESET}\n"

leaks:
				@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --log-file=output.log ./btc 1_input.txt

re: clean all

.PHONY: all clean re