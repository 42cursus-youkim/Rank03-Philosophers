# ===== Target & FLAGS =====
NAME     := philo

CC       := clang
CFLAGS   := -Wall -Wextra -Werror #-O3

PRE      := src/
INC      := -I includes/

DFLAGS	 := -g #-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"

RM       := rm -rf
TEST     := ./$(NAME) 5 1000 200 100 5 #philos death eat sleep end
# ===== Packages =====
PKGS     := engine philo utils
engineV  := main checks init_engine run_engine del_engine
philoV   := philo manager
utilsV   := ytime ythread yutils ylogging

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
test: docs all cls
	@$(call log, Y, Running Test...)
	@$(TEST)
	@$(call log, G, Ended Test)

log: docs all cls
	@$(call log, Y, Logging Test...)
	@$(TEST) | sed -r "s/\x1B\[[0-9;]*[JKmsu]//g" > res.txt
	@python3 ./fix.py
	@cat res.txt
	@echo
	@$(call log, G, Ended Logging)

# ===== Valgrind =====
VFLAGS := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --show-reachable=no
HFLAG  := --tool=helgrind --history-level=approx
VSFLAGS := --show-reachable=yes --error-limit=no --gen-suppressions=all \
			--log-file=./mlx.supp
leak: docs all cls
	@$(call log, Y, Running Leak Test,...)
	@colour-valgrind $(VFLAGS) $(TEST)

hleak:
	@colour-valgrind $(HFLAG) $(TEST)

supp: docs all cls
	@$(call log, Y, Creating Leak Suppressions,...)
	@valgrind $(HFLAG) --gen-suppressions=all $(TEST)

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