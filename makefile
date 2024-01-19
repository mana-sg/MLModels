.PHONY: run

run:
	@gcc -g Modules/main.c Modules/read_csv.c && ./a.out && rm a.out
