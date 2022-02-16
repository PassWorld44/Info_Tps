(*
Emile BONDU
découverte du langage OCaml
quelques fonctions !
16/02/2022
*)

let f1 f = (f 0. +. f 1.) /. 2. ;;
(* val f1 : (float -> float) -> float = <fun> *)

let f2 f x = (f x)** 2. ;;
(* val f2 : ('a -> float) -> 'a -> float = <fun> *)

let f3 f = fun x -> (f x)**2. ;;
(* val f3 : ('a -> float) -> 'a -> float = <fun> *)

let f4 f = fun x -> f(x + 1) ;;
(* val f4 : (int -> 'a) -> int -> 'a = <fun> *)
