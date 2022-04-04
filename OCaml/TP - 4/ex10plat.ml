(*
Emile BONDU
mise a plat d'une liste
01/04/2022
*)


let rec flat f = 
	match f with
	| [] -> []
	| x :: p  -> x@(flat p);;