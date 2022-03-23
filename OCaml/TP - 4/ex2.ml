(*
Emile BONDU
nombre de dividions par 2
23/03/2022*)

let rec log2_rec n =
if n <= 1 then 0
else 
	1 + log2_rec (n/2);;

let log2_it n = 
let som = ref 0 in
let div = ref n in
while !div > 1 do
	div := !div / 2;
	incr(som);
done;
!som;;