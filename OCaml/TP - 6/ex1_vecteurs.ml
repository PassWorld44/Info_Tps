(*
Emile BONDU
vecteurs
19/04/2022
*)

type point   = {mutable x : float  ; mutable y : float  };;
type vecteur = {mutable dx : float ; mutable dy : float };;

let extremite pt vect =
{ x = pt.x +. vect.dx ; y = pt.y +. vect.dy };;

let rotation v =
{ dx = -. v.dy ; dy = v.dx };;
(* roattio d'un vecteur d'un quart de tour 
	dans le sens trigonométrique *)

let p = {x = 1. ; y = 1.};;
let v = {dx = 2. ; dy = -1. };;

extremite p v;;
rotation v;;