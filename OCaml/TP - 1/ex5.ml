(*
Emile BONDU
découverte du langage OCaml
boucle while - somme des entiers de 1 a 5
04/02/2022
*)
let somme = ref 0;;
let compteur = ref 1;;
while !compteur <= 5 do
	somme := !somme + !compteur;
	compteur := !compteur + 1;
	print_int !somme;
	print_newline();
done;;