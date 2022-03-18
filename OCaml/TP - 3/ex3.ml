(*
Emile BONDU
nombre jours dans un mois 
18/03/2022
*)

let sous_chaine str debut fin =
let taille = String.length str in 
if not (0 <= debut && debut <= fin && fin < taille) then
	failwith("indices des bords de la sous-chaine impossibles");
let retour = String.create (fin - debut) in
for i = 0 to fin - debut do
	retour.[i] <- str.[debut + i];
done;
retour;;