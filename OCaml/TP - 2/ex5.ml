(*
Emile BONDU
découverte du langage OCaml
gestion des erreurs dans une fonction
16/02/2022
*)

let sinc x =
	match x with
	| 0. -> failwith "division par 0"
	| _ -> sin(x) /. x ;;