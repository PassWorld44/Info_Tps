(*
Emile BONDU
découverte du langage OCaml
boucle while - entiers etant des carrés parfait ou 
	des multiples de 31
04/02/2022
*)
let isSquare = ref false in
for i = 1 to 100 do
	for j = 1 to 10 do
		if j*j = i then
			isSquare := true;
	done ;
	if  !isSquare = true || i mod 31 = 0 then begin
		print_int i;
		print_newline();
	end;
	isSquare := false;
done ;;

let diff f g =
  let n = ref 0 in
  	while abs(f !n - g !n) < 1 do
  		incr n done;
 	n! ;;