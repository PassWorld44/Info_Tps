(*
Emile BONDU
découverte des chaines de characteres
25/02/2022
*)

let a = 'a' ;;
a = 'b' ;;
a := 'b' ;;

let c = ref 'a' ;;
c := 'd';;
print_char(c);

int_of_char('c');;
int_of_char(!c);;
char_of_int(97);;

for i = 97 to 101 do
	print_char(char_of_int(i));
done;;


"Bonjour les MP2I !";;
let chaine = "bonjour les MP2I";;
chaine;;
print_string (chaine);;
(* parentheses facultatives mais aident a la lecture *)
print_string (chaine.[0]);;
print_char   (chaine.[0]);;
chaine.[14]<-'I';;
chaine.[15]<-' ';;
chaine;;
print_char   (chaine.[16]);;

let s = ref "";;
s:= 'a';;
s :="a";;
s;;

(* operateurs de comparaisons de chaine :
	= / <> : marchent classiquement
	<= : comaraison lexicographique
*)

(* les strings sont des pointeurs : seul un String.copy permet 
	une veritable idépendance des instances 
*)

(* TABLEAUX :*)
[|3. ; 2; 1|];; (* erreur : un seul type a l'interieur *)

[| |];;

let tableau = Array.make 5 8;; (* tab de 5, remplit par des int (égaux a 8) *)

let carre_0 x = x*x in
	Array.init 11 carre_0;;
(* - : int array = [|0; 1; 4; 9; 16; 25; 36; 49; 64; 81; 100|] *)

let carre_1 x = x*x;;
let tableau_1 = Array.init 4 carre_1;;
Array.init 4 carre_1;;
let tableau_2 = Array.init 3 carre_1;;
Array.init 3 carre_1;;

let rire = Array.make 7 "ha";;

for i = 0 to Array.length(rire) - 1 do
	print_string rire.(i);
	print_newline();
done;;

