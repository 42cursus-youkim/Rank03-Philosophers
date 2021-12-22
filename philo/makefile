# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/22 12:38:49 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := philosophers

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror

PRE      := src/
INC      := -I includes/

DFLAGS	 := -g3 -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"

RM       := rm -rf

# ===== Packages =====
PKGS     := engine utils
engineV  := main checks philo init_engine del_engine
utilsV   := ytime ythread yutils

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

# ===== Sources & Objects & Includes =====
SRC = $(call choose_modules, $(PKGS))
OBJ = $(SRC:%.c=%.o)

# ===== Rules =====
%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) -o $@ $^
	@$(call log, V, Linked Object files,\
		\n\twith flag $(R)$(DFLAGS)$(E)$(CFLAGS))
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(call log, R, Cleaned Object files)

fclean: clean
	@$(RM) $(NAME)
	@$(call log, R, Cleaned Names)

re: fclean all

# ===== Test =====
TEST := ./$(NAME) 1 100 50 50 3
test: docs all cls
	@$(call log, Y, Running Test...)
	@$(TEST)
	@$(call log, G, Ended Test)

# ===== Valgrind =====
VFLAGS := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --show-reachable=no \
			# --suppressions=./libft/macos.supp
VSFLAGS := --show-reachable=yes --error-limit=no --gen-suppressions=all \
			--log-file=./mlx.supp
leak: docs all cls
	@$(call log, Y, Running Leak Test,...)
	@colour-valgrind $(VFLAGS) $(TEST)
supp: docs all cls
	@$(call log, Y, Creating Leak Suppressions,...)
	@valgrind $(VFLAGS) --gen-suppressions=all $(TEST)

.PHONY: all re clean fclean test docs cls

# ===== Header Generation ====
HGEN := hgen
docs:
	@$(call log, V, Generating Docs,...)
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I includes/$$p.h src/$$p;\
		done
	@$(call log, G, Updated Docs)

# ===== Colors =====
cls:
	@set -e; clear

R  ?= \033[0;91m
WU ?= \033[4;37m
C  ?= \033[0;96m
CU ?= \033[4;36m
Y  ?= \033[0;33m
YU ?= \033[4;33m
G  ?= \033[0;92m
V  ?= \033[0;35m
E  ?= \033[0m
CNAM ?= for $(YU)$(strip $(NAME)$(E))

# ===== Logging =====
define log
	printf "$($(strip $(1)))<$(strip $(2))\
			$(CNAM)$($(strip $(1)))$(strip $(3))$($(strip $(1)))>$(E)\n"
endef