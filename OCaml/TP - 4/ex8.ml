(* 
Emile BONDU
avant dernier element d'une liste chainee
24/03/2022
*)

let rec avant_dernier a = 
if List.length a <= 1 then
	failwith "liste de taille insuffisante"
else
	List.nth a (List.length a - 2);;
	