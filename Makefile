EXS	= \
	module00/ex00 \
	module00/ex01 \
	module00/ex02 \
	module01/ex00 \
	module01/ex01 \
	module01/ex02 \
	module01/ex03 \
	module01/ex04 \
	module01/ex05 \
	module01/ex06 \
	module02/ex00 \
	module02/ex01 \
	module02/ex02 \
	module02/ex03 \
	module03/ex00 \
	module03/ex01 \
	module03/ex02 \
	module03/ex03 \
	module04/ex00 \
	module04/ex01 \
	module04/ex02 \
	module04/ex03

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
