(*
Emile BONDU
sommes des chiffres d'un nombre
23/03/2022
*)

let rec som_chiffres nbr =
if nbr == 0 then 0
else 
	som_chiffres (nbr / 10) + nbr mod 10;;

