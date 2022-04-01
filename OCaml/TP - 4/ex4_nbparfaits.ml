(*
Emile BONDU
nombre parfait
23/03/2022
*)

let est_parfait n =
let sum = ref 0 in
for i = 1 to (n - 1) do
	if n mod i = 0 then begin
		sum := !sum + i;
	end;
done;
!sum = n;;