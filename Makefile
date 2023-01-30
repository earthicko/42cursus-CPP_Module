EXS	= \
	module00/ex00 \
	module00/ex01 \
	module00/ex02 \
	module01/ex00 \
	module01/ex01 \
	module01/ex02 \
	module01/ex03

all:
	for ex in $(EXS); \
	do \
		make -C $$ex all; \
	done

re:
	@make fclean
	@make all

clean:
	for ex in $(EXS); \
	do \
		make -C $$ex clean; \
	done

fclean: clean
	for ex in $(EXS); \
	do \
		make -C $$ex fclean; \
	done

.PHONY: all clean fclean
