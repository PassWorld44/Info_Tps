(*
Emile BONDU
coef binomiaux
23/03/2022
*)

let rec coef_bin k n =
if k = 0 || k = n then n
else 
	(coef_bin (k-1) (n-1) ) * n / k;;
