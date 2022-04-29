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
			Vide, 68, Noeud(Vide, 68, Vide)
			),
			71,
			Noeud(Vide, 79; vide)
		)
	),
	145,
	Noeud(
		Noeud(Vide, 171, Vide),
		190, Vide
	)
)