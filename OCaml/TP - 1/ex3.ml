(*
Emile BONDU
découverte du langage OCaml
boucle for
27/01/2022
*)
let x = ref 2;;
for k = 1 to 10 do 
	print_int k;
	print_string " + ";
	print_int !x;
	x := !x + k;
	print_string " = ";
	print_int !x;
	print_newline();
done;;