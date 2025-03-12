NAME = gs_gset.a

SRC = gs_gset.c gs_utils.c

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

CCA = cc -Wall -Wextra -Werror -g3 -MP -MMD
MAKEFLAGS += --no-print-directory

TOTAL_FILES = $(words $(OBJ))
PROGRESS = 0
TERM_WIDTH = $(shell tput cols)
BAR_WIDTH = $(shell echo $$(( ($(TERM_WIDTH) - 30) > 60 ? 50 : ($(TERM_WIDTH) - 21) - 10 )))
COLORS = "\033[4;30m\033[4;31m\033[4;32m\033[4;33m\033[4;34m\033[4;35m\033[4;36m\033[1;30m\033[1;31m\033[1;32m\033[1;33m\033[1;34m\033[1;35m\033[1;36m\033[1;90m\033[1;91m\033[1;92m\033[1;93m\033[1;94m\033[1;95m\033[1;96m\033[1;97m"
CHARACTERS = "!?@0&:.%=+"
RESET_COLOR = "\033[0m"

PRINT_PROGRESS:=
define PRINT_PROGRESS
	$(eval PROGRESS := $(shell echo $$(( $(PROGRESS) + 1 ))))
	@BARS=$$(($(PROGRESS) * $(BAR_WIDTH) / $(TOTAL_FILES))); \
	EMPTY=$$(( $(BAR_WIDTH) - $$BARS )); \
	PERCENT=$$(($(PROGRESS) * 100 / $(TOTAL_FILES))); \
	printf "\033[1;36m\033[1mgs_gset: \033[37mCompiling: \033[1;32m[+ "; \
	for i in $$(seq 1 $$BARS); do \
		COLOR=$$(echo $(COLORS) | fold -w 7 | shuf -n 1); \
		CHAR=$$(echo $(CHARACTERS) | fold -w 1 | shuf -n 1); \
		echo -n "\033[0;47m"$$COLOR$$CHAR$(RESET_COLOR); \
	done; \
	for i in $$(seq 1 $$EMPTY); do \
		echo -n " "; \
	done; \
	printf "\033[1;32m +] \033[34m$$PERCENT%%\033[0m\r"
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(eval PROGRESS := 0)
	@ar -rc $(NAME) $(OBJ)
	@printf "\n\033[36m\033[1mgs_gset: \033[1;97mBuild Complete !\033[0m\n"

%.o: %.c
	@$(CCA) -o $@ -c $<
	$(PRINT_PROGRESS)

clean:
	@rm -f $(OBJ) $(DEP)
	@printf "\033[36m\033[1mgs_gset: \033[37m666_OBJ/ Cleaned !\033[0m\n"

fclean:
	@rm -f $(OBJ) $(DEP) $(NAME)
	@printf "\033[36m\033[1mgs_gset: \033[37mCleaned !\033[0m\n"

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re

-include $(DEP)
