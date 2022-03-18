(*
Emile BONDU
manipulation de strings
18/03/2022
*)

let crochets str =
let taille = String.length (str) in
let retour = String.create (taille * 3) in
for i = 0 to taille -1 do
	retour.[3*i] <- '[';
	retour.[3*i + 1] <- str.[i];
	retour.[3*i + 2] <- ']';
done;
retour;;

let decrochets str = 
let taille = String.length (str) in
let retour = String.create (taille/3) in
for i = 0 to taille/3 - 1 do
	retour.[i] <- str.[3*i + 1];
done;
retour;;