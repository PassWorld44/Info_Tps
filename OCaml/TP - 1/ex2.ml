(*
Emile BONDU
découverte du langage OCaml
detection d'erreurs manuellement
27/01/2022
*)
let x = 2  in x + 2 ;;
let x = 1 and y = 3 in let x = 2 in x + y ;;
let x, y, z = 1, 2, 3 in x + y + z ;;
let x, y, z = true, 2, 3 in x || y = z ;;
let x, y, z = true, 2, 3 in x && y < z ;;