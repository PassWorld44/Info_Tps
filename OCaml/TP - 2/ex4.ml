(*
Emile BONDU
découverte du langage OCaml
une fonction de tri (extremement basique
16/02/2022
*)

let choix a b c = 
	match a with
	| true -> b
	| false -> c ;;

choix true 1. 2. ;;
choix false "meh" "bon" ;;
choix false 5 2 ;;