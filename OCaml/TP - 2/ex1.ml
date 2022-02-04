(*
Emile BONDU
découverte du langage OCaml
description du comportements de fonctions
04/02/2022
*)
let a = 2;;
let f x = a*x;;
(* val int->int = <fun> *)
let a = 3 in f 1;;
(* - : int=3 NON!
   - : int=2 plutot  
   c'est pas le même a 
   -> il y a des portées de variables*)
let a = 3 ;;
f 1 ;;
(* - : int=2 -> ça ne change quand meme pas *)

(* suite *)
let a = 
let a = 3 and b = 2 in
let a = a+b and b = a-b in
	a-b;;
(* val a : int= 4 *)

let b = 2 in a-b*b;;