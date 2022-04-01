(* 
Emile BONDU
avant dernier element d'une liste chainee
24/03/2022
*)

let prefixe a =
	let rec prefixe_current a l =
	match List.rev a with
	| [] -> l
	| x :: p -> let temp = ( List.map (function y -> x :: y) l )in
		 	 	let suite = [[x]]@temp in
		 	 	prefixe_current (List.rev p) suite;
	in
prefixe_current a [];;