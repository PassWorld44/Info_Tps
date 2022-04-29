(*
Emile BONDU
arbres
29/04/2022
*)

type arbre =
| Vide
| Noeud of arbre * int * arbre;;

(* exemple *)

let abr1 = 
Noeud(
	Noeud(
		Noeud(
			Noeud(
				Vide, 21, 
				Noeud(Vide, 23, Vide)
			),
			27, Vide
		),
		63,
		Noeud(
			Noeud(
			Vide, 67, Noeud(Vide, 68, Vide)
			),
			71,
			Noeud(Vide, 79, Vide)
		)
	),
	145,
	Noeud(
		Noeud(Vide, 171, Vide),
		190, Vide
	)
);;

(* =========== parcours d'arbre =============*)

(* ----------- non recursif -----------------*)

let rec parcoursPrefixe a = 
match a with
| Vide -> print_string ""
| Noeud (x, y, z) -> print_int y;
							print_string " ";
							parcoursPrefixe x;
							parcoursPrefixe z;;

let rec parcoursInfixe a = 
match a with
| Vide -> print_string ""
| Noeud (x, y, z) -> parcoursPrefixe x;
							print_int y;
							print_string " ";
							parcoursPrefixe z;;

let rec parcoursPostfixe a = 
match a with
| Vide -> print_string ""
| Noeud (x, y, z) -> parcoursPrefixe x;
							parcoursPrefixe z;
							print_int y;
							print_string " ";;

parcoursInfixe abr1;;
parcoursPrefixe abr1;;
parcoursPostfixe abr1;;

(* on a besoin de piles pour gerer la pile d'appels
 pour faire sans sans récursivité*)