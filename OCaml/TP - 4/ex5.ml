(*
Emile BONDU
ordre lexicographique
24/03/2022
*)

let rec ordre_lexico t1 t2 =
	if int_of_char t1.[0] <> int_of_char t2.[0]  || 
			String.length t1 = 1 || String.length t2 = 1 then
		int_of_char t1.[0] < int_of_char t2.[0]
	else
		ordre_lexico (String.sub t1 (String.length t1 - 1) 1 )
				 (String.sub t2 (String.length t2 - 1) 1 );;