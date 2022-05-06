(*
Emile BONDU
pile mutable
06/04/2022
*)

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
