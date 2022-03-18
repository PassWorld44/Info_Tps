(*
Emile BONDU
invertion d'une chaine de characteres
18/03/2022
*)

let inverse str = 
let taille = String.length (str) in
let retour = String.create taille in
for i = 0 to taille - 1 do
	retour.[i] <- str.[taille - i - 1];
done;
retour ;;

inverse "super" ;;