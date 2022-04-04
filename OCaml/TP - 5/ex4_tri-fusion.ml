(*
Emile BONDU
tri fusion
04/04/2022
*)

let fusion t g m d =
(* fusion de t1 et t2, chacun étant déja trié *)
let tcopie = Array.copy t in
let a = ref 0 and b = ref 0 in
a := g;
b := m;
while(!a < m || !b < d) do
	if(!a = m) then begin
	(* on remplit avec la 2e partie du tableau *)
		t.(!a + !b-m) <- tcopie.(!b);
		incr(b);
		end
	else if(!b = d) then begin
	(*on remplit la 1ere partie du tableau *)
		t.(!a + !b-m) <- tcopie.(!a);
		incr(a);
		end
	else if(tcopie.(!a) < tcopie.(!b)) then begin
	(* on prend un element dans le 1er tableau *)
		t.(!a + !b-m) <- tcopie.(!a);
		incr(a);
		end
	else begin
	(* on prend un element dans le 2e tableau *)
		t.(!a + !b-m) <- tcopie.(!b);
		incr(b);
		end
done;;

let tri_fusion t =
let rec tri_fusion_aux t g d = 
	if d-g > 1 then begin
	(* sinon c'est le cas de base*)
		let millieu = (g + d)/2 in
		tri_fusion_aux t g millieu;
		tri_fusion_aux t millieu d;
		fusion t g millieu d;
	end
in tri_fusion_aux t 0 (Array.length t);
t;;

tri_fusion [|3;2;1|];;

tri_fusion [|13; 8; 42; 3; 23; 7; -3|];;