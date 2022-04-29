(*
Emile BONDU
piles non mutables
29/04/2022
*)

let pilevide () = [];;

let empile e p = e::p;;

let depile p = 
match p with 
| [] ->  failwith("pile vide")
| a::b -> b;;

let estVide p =
match p with
| [] -> true
| a::b -> false;;

let sommet p =
match p with
| [] -> failwith("pile vide")
| a::b -> a;;


let pile  = pilevide();;

let pile = empile 6 pile;;
let pile = empile 7 pile;;
let pile = empile 9 pile;;




