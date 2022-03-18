(*
Emile BONDU
nombre jours dans un mois 
18/03/2022
*)

let nb_jours numMois = 
let nb_jours = [| 31 ; 28 ; 31 ; 30 ;
						31 ; 30 ; 31 ; 31 ;
						30 ; 31 ; 30 ; 31 |] in
if (numMois < 1) || (numMois > 12) then
	failwith("mois incorrect")
else
	nb_jours.(numMois - 1);;