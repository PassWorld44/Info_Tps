(*
Emile BONDU
arbres
06/04/2022
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

type 'a file = {mutable contenu : 'a list};;

let fileVide = 
{contenu = []};;

let estVide l = 
match l.contenu with
| [] -> true
| a::p -> false
;;

let enfile elt l =
l.contenu <- elt :: l.contenu;;

let defile l =
match l.contenu with
| [] -> failwith("liste donnee vide")
| a::p -> l.contenu <- p
;;

let tete l =
match l.contenu with
| [] -> failwith("liste donnee vide")
| a::p -> a
;;

(* parcours avec les piles *)

let parcoursPrefixePile abr = 
let p = fileVide in
enfile abr p;
let rec aux p =
	let n = tete p in
	defile p;
	match n with
	| Vide -> print_string ""
	| Noeud (x, y, z) -> print_int y;
								print_char ' ';
								enfile z p;
						 		enfile x p;
								aux p;
								aux p
	in
aux p;;

let parcoursInfixePile abr = 
let p = fileVide in
enfile abr p;
let rec aux p =
	let n = tete p in
	defile p;
	match n with
	| Vide -> print_string ""
	| Noeud (x, y, z) -> enfile z p;
						 		enfile x p;
								aux p;
								print_int y;
								print_char ' ';
								aux p
	in
aux p;;

let parcoursSuffixePile abr = 
let p = fileVide in
enfile abr p;
let rec aux p =
	let n = tete p in
	defile p;
	match n with
	| Vide -> print_string ""
	| Noeud (x, y, z) -> enfile z p;
						 		enfile x p;
								aux p;
								aux p;
								print_int y;
								print_char ' '
	in
aux p;;


parcoursPrefixePile abr1;;
parcoursInfixePile abr1;;
parcoursSuffixePile arb1;;