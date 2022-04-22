(*
Emile BONDU
arbre bicolore
19/04/2022
*)

type couleur = R | N;; (* Rouge ou Noir *)

type arbre_binaire =
| Vide
| Noeud of arbre_binaire * int * couleur * arbre_binaire;;

let a1 =
Noeud(
	Noeud( Noeud(Vide, 12, R, Vide),
		   22, N,
		   Noeud(Vide, 27, R, Vide) ),
	32, N,
	Noeud(Vide, 62, N, Vide)
);;

let a2 = 
Noeud(
	Noeud( Noeud(Vide, 30, R, Vide),
		   20, N, Vide),
	40, N,
	Noeud(Vide, 60, N, Vide)
);;

let a3 =
Noeud(
	Noeud(
		Noeud(
			Noeud(Vide, 11, N, Vide),
			21, R,
			Noeud(Vide, 16, N, Vide)
		),
		31, N,
		Noeud(Vide, 36, N, Vide)
	),
	41, N,
	Noeud(
		Vide, 61, N,
		Noeud(Vide, 71, N, Vide)
	)
);;