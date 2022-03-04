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

let rire = Array.make 7 "ha" ;;

for i = 0 to Array.length(rire) - 1 do
	print_string rire.(i);
	print_newline();
done;;

rire.(3)<- "ho";;

for i = 0 to Array.length(rire) - 1 do
	print_string rire.(i);
	print_newline();
done;;

let affiche_premier tab = (*val affiche_premier : int array -> unit = <fun> *)
	print_int tab .(0) ;
	print_newline();
in
let t1 = [| 4; 6; -3 |] in
affiche_premier t1; (* 4 : le 1er de t1 *)
let t2 = Array . make 23 (-2) in
affiche_premier t2 ;; (* -2 : le 1er de t2 *)

(* Note : les parentheses autour du -2 sont nécéssaires, 
sinon Ocaml l'interprete comme une soustraction *)

let t3 = Array.make 3 2;;
t3;;
let t4 = t3;; (* les valeurs sont partagées !*)
t3.(0)<-0;;
t3;;
t4;;
let a = Array.length t3;;
a;;

let t5 = Array.copy t4;; (* Casse le partage de valeur pour t4 *)
t4;;
t5;;
t4.(1)<-4;;
t3;;
t4;;
t5;;

let ts1 = Array.make 3 "baba";;
let ts2 = Array.make 3 ts1.(0);
ts1;;
ts2;;

ts2.(0)<-"bibi";;
ts1.(0).[3] = 'a';;
ts1.(0).[3]<- 'o';;
ts1;;
ts2;;
(* les valeurs sont encore aprtagées !*)

[| 1; 2; 3|] = [| 1; 2; 3|];;
[| 1; 2; 3|] = [| 3; 2; 1|];;
let t = [| 1; 2; 3|] 
	in t = Array.copy t;;
(* permet de juger si les valeurs des tab sont équivalentes *)
	
[| 1; 2; 3|] == [| 1; 2; 3|];;

let t = [| 1; 2; 3|] 
	in t == Array.copy t;;


let t = [| 1; 2; 3|] 
	in let s = t in
	t==s;;
(* permet de juger si les instances des tab sont équivalentes *)

(* fonction double_elements
int array -> int array

parametre t : int array = tableau
dont on veut doubler les elts

val renvoyee : int array = nouveau tableau 
	dont les elts sont le double de ceux de t *)

let double_element t = 
	let n = Array.length t in
	let t1 = Array.make n 0 in
	for i = 0 to n-1 do
		t1.(i) <- 2*t.(i)
	done;
	t1;;
	
let tab = Array.make 3 2;;
let tab_bis = double_element tab;;

(* fonction doubler_elements
int array -> unit

parametre t : int array = tableau
dont on veut doubler les elts

action : double les elts de t (t est modifié) *)

let doubler_element t = 
	let n = Array.length t in
	for i = 0 to n-1 do
		t.(i) <- 2*t.(i)
	done;;

let table = Array.make 3 4;;
doubler_element table;;
table;;

let t = [| 4; 2|];;
match t with
| [| |]->"Vide"
| [|1;_|]->"Commence par 1"
| [|2;_|]->"Commence par 2"
| [|x;y|]->"t commence par "^string_of_int(x)
| _->"Autre cas";;

let matrice_1 =
[| [|(0,0);(0,1);(0,2)|];
	[|(1,0);(1,1);(1,2)|];
	[|(2,0);(2,1);(2,2)|];
	[|(3,0);(3,1);(3,2)|] |];;

let triplet_1 = (1,2,"cou");;
triplet_1;;

let mat_1 = 
	let t = Array.make 4 [| |] in
	for i = 0 to 3 do
		let ligne = Array.make 3 (0,0) in
		for j = 0 to 2 do
			ligne.(j)<- (i,j)
		done;
		t.(i)<-ligne
	done;
	t;;

let mat_2 =
let elt i j = (i,j) in
let ligne i = Array.init 3 (elt i) in
	Array.init 4 ligne;;

let mat_3 = Array.make_matrix 2 3 (1,1);;

mat_2.(1);;

mat_2.(1)<-[|(0,0); (0,0); (0,0) |];;
mat_2.(1);;
mat_2;;

let mat_4 =
let t = Array.make 3 (Array.make 4 (0,0)) in 
for i = 0 to 2 do
	for j = 0 to 3 do
		t.(i).(j)<-(i,j)
	done;
done;
t;;

mat_4.(0).(0)<-(0,0);;
mat_4;;

mat_4.(0) == mat_4.(1);; (* TRUE ??? *)