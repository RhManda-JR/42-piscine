#!/bin/bash
# Usage : bash tests/run.sh        -> tout tester
#         bash tests/run.sh c05    -> tester seulement les exercices dont le chemin contient "c05"
cd "$(dirname "$0")/.."
FLAGS="-Wall -Wextra -Werror"
FILTER="$1"

# t <dossier> "<fichiers .c a rendre>" <main de test ou -> [arguments du programme...]
t() {
	local dir=$1 srcs=$2 main=$3
	shift 3
	[[ -n "$FILTER" && "$dir" != *"$FILTER"* ]] && return
	echo "===== $dir ====="
	local files="" out="tests/$(echo "$dir" | tr / _).out"
	for s in $srcs; do files="$files $dir/$s"; done
	[ "$main" != "-" ] && files="$files tests/$main"
	gcc $FLAGS -I "$dir" -I c08/ex04 $files -o "$out" || return
	if [ $# -gt 0 ]; then echo "\$ ./prog $*"; fi
	"./$out" "$@"
	echo
}

t c02/ex09 ft_strcapitalize.c main_ex09.c
t c02/ex11 ft_putstr_non_printable.c main_ex11.c
t c02/ex12 ft_print_memory.c main_ex12.c
t c03/ex04 ft_strstr.c main_c03_ex04.c
t c03/ex05 ft_strlcat.c main_c03_ex05.c
t c04/ex00 ft_strlen.c main_c04_ex00.c
t c04/ex01 ft_putstr.c main_c04_ex01.c
t c04/ex02 ft_putnbr.c main_c04_ex02.c
t c04/ex03 ft_atoi.c main_c04_ex03.c
t c04/ex04 ft_putnbr_base.c main_c04_ex04.c
t c04/ex05 ft_atoi_base.c main_c04_ex05.c
t c05/ex00 ft_iterative_factorial.c main_c05_ex00.c
t c05/ex01 ft_recursive_factorial.c main_c05_ex01.c
t c05/ex02 ft_iterative_power.c main_c05_ex02.c
t c05/ex03 ft_recursive_power.c main_c05_ex03.c
t c05/ex04 ft_fibonacci.c main_c05_ex04.c
t c05/ex05 ft_sqrt.c main_c05_ex05.c
t c05/ex06 ft_is_prime.c main_c05_ex06.c
t c05/ex07 ft_find_next_prime.c main_c05_ex07.c
if [[ -z "$FILTER" || "c05/ex08" == *"$FILTER"* ]]; then
	echo "===== c05/ex08 (724 lignes affichees, on montre les 3 premieres) ====="
	gcc $FLAGS c05/ex08/ft_ten_queens_puzzle.c tests/main_c05_ex08.c -o tests/c05_ex08.out \
		&& ./tests/c05_ex08.out | tr -d '\r' > tests/c05_ex08.txt && head -3 tests/c05_ex08.txt
	echo "lignes affichees : $(wc -l < tests/c05_ex08.txt), lignes differentes : $(sort -u tests/c05_ex08.txt | wc -l)"
	echo
fi
t c06/ex00 ft_print_program_name.c -
t c06/ex01 ft_print_params.c - Hello "42 Paris" -x
t c06/ex02 ft_rev_params.c - Hello "42 Paris" -x
t c06/ex03 ft_sort_params.c - zeta Alpha alpha 42 "" beta
t c07/ex00 ft_strdup.c main_c07_ex00.c
t c07/ex01 ft_range.c main_c07_ex01.c
t c07/ex02 ft_ultimate_range.c main_c07_ex02.c
t c07/ex03 ft_strjoin.c main_c07_ex03.c
t c07/ex04 "ft_convert_base.c ft_convert_base2.c" main_c07_ex04.c
t c07/ex05 ft_split.c main_c07_ex05.c
t c08/ex00 "" main_c08_ex00.c
t c08/ex01 "" main_c08_ex01.c a b
t c08/ex01 "" main_c08_ex01.c a b c
t c08/ex02 "" main_c08_ex02.c
t c08/ex03 "" main_c08_ex03.c
t c08/ex04 ft_strs_to_tab.c main_c08_ex04.c
t c08/ex05 "ft_show_tab.c ../ex04/ft_strs_to_tab.c" main_c08_ex05.c

if [[ -z "$FILTER" ]]; then
	echo "===== norminette ====="
	python -m norminette c02 c03 c04 c05 c06 c07 c08 | grep -v ": OK!"
	echo "(seuls les fichiers en erreur sont listes)"
fi
