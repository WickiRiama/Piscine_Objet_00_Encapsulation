NAME = bank

SRCS_DIR = srcs/
INC_DIR = includes/
OBJ_DIR = objs/

SRCS = ${addprefix ${SRCS_DIR}, \
			DivideAndRule.cpp \
			main.cpp \
		}

OBJS = ${SRCS:${SRCS_DIR}%.cpp=${OBJ_DIR}%.o}
DEPS = ${OBJS:%.o=%.d}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
IFLAGS = -I./includes -MMD
LFLAGS = 

${NAME}: ${OBJ_DIR} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRCS_DIR}%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@ ${IFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf ${OBJ_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}