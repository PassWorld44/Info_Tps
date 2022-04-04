(*
Emile BONDU
minimum d'une liste
01/04/2022
*)

let ocsmin l =
let rec ocsrec l tuple =
	match l with
	| [] -> tuple
	| x :: p -> match tuple with
				| (y, z) when y = x -> ocsrec p (y, z + 1)
				| (y, z) when x < y || z = 0 -> ocsrec p (x, 1)
				| _ -> ocsrec p tuple
in
ocsrec l (0, 0);;