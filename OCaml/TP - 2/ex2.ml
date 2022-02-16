(*
Emile BONDU
découverte du langage OCaml
affectation locales d'expressions mathématiques
16/02/2022
*)

let a = (1. +. sqrt 7. +. (sqrt 7.)**3. ) /. (1. +. exp (sqrt 7.) ) ;;
(* val a : float = 1.46852830763451569 *)

let b = (log(cos(1.)) +. sin(log(5.)))/.(cos(1.) +. log(5.));;
(* val b : float = 0.178452741950576838 *)