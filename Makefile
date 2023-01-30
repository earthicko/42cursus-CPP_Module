all:
	@make -C module00/ex00 all
	@make -C module00/ex01 all
	@make -C module00/ex02 all

re:
	@make fclean
	@make all

clean:
	@make -C module00/ex00 clean
	@make -C module00/ex01 clean
	@make -C module00/ex02 clean

fclean: clean
	@make -C module00/ex00 fclean
	@make -C module00/ex01 fclean
	@make -C module00/ex02 fclean

.PHONY: all clean fclean
