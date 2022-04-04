(*
Emile BONDU
max d'un tableau
04/04/2022
*)

let max_tab t =
if Array.length t = 0 then
	failwith("pas de maximum");
let max = ref 0 in
max := t.(0);
for i = 1 to Array.length t - 1 do
	if t.(i) > !max then
		max := t.(i);
done;
!max;;

let max_tab_rec t =
let rec max_tab_aux t a b =
	let millieu = (b + a)/2 in
	if b - a = 1 then
		t.(a)
	else
		let maxG = max_tab_aux t a millieu in
		let maxD = max_tab_aux t millieu b in
		if maxG < maxD then
			maxD
		else
			maxG
in max_tab_aux t 0 (Array.length t);;