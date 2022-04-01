(*
Emile BONDU
minimum d'une liste
01/04/2022
*)

let oscmin l =
let rec oscrec l t=
	match l with
	| [] -> t
	| x :: p -> match t with
				| (x, _) -> oscrec p (x, t.second + 1)
				| (y, z) when y < x || z = 0 -> oscrec p (y, 1)
				| _ -> oscrec p t
in
oscrec l (0, 0);;