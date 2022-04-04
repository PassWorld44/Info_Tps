(*
Emile BONDU
recherche dichotomique
04/04/2022
*)

let dicho_naive tab e =
(* version iterative naive *)
let indice = ref (-1) in
for i = 0 to (Array.length tab) -1 do
	if tab.(i) = e then
		indice := i;
done;
!indice;;

let dicho tab e =
let rec dicho_rec tab e a b =
	let millieu = (b + a)/2 in
	if b-a <= 0 then
		failwith("l'element recherche n'est pas dans le tableau");
	if tab.(millieu) = e then
		taille/2
	else if tab.(millieu) < e then
		( dicho_rec tab e (millieu + 1) b )
	else ( dicho_rec tab e a (millieu - 1) )
in dicho_rec tab e 0 (Array.length tab - 1);;