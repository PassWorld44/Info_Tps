(*
Emile BONDU
découverte du langage OCaml
boucle for
04/02/2022
*)
let x = ref 9;;
for k = 1 to 20 do 
	print_int !x;
	print_string " * ";
	print_int k;
	print_string " = ";
	print_int (!x * k);
	print_newline();
done;;