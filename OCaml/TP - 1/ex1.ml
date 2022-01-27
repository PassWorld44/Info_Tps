(*
Emile BONDU
découverte du langage OCaml
tentative de description du programme et de prédire son comportement
27/01/2022
*)
let a = ref 9 ;; (* crée une variable int et lui affecte 9 *)
a := 1 ; 2 + !a ;; (* affecte 1 à a et retourne 3 *)
3* (a:=7; 2 + !a) ;; (* affecte 7 à a et retourne 27 *)