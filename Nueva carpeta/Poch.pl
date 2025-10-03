/*
 * PARADIGMAS DE PROGRAMACION - 2do PARCIAL 2023 - 15/12/23
 *	
 * APELLIDO Y NOMBRE: POCH IÑAKI
 * 
 * Base de Conocimiento ALMACEN DON MANOLO
 *
 */

 

producto(lacteo, leche).
producto(lacteo, manteca).
producto(lacteo, crema).
producto(lacteo, yogurt).
producto(fiambre, queso).
producto(fiambre, jamonCrudo).
producto(fiambre, jamonCocido).
producto(fiambre, salame).
producto(panaderia, pan).
producto(panaderia, factura).
producto(panaderia, tortilla).
producto(panaderia, galleta).
producto(bebida, agua).
producto(bebida, gaseosa).
producto(bebida, jugo).
producto(bebida, soda).
producto(golosina, chocolate).
producto(golosina, caramelo).
producto(golosina, mantecol).
producto(golosina, bombones).
producto(golosina, nugaton).

precio(leche, 177).
precio(manteca, 262).
precio(crema, 195).
precio(yogurt, 153).
precio(queso, 380).
precio(jamonCrudo, 270).
precio(jamonCocido, 150).
precio(salame, 185).
precio(pan, 180).
precio(factura, 85).
precio(tortilla, 50).
precio(galleta, 150).
precio(agua, 100).
precio(gaseosa, 230).
precio(jugo, 198).
precio(soda, 130).
precio(chocolate, 150).
precio(caramelo, 50).
precio(mantecol, 210).
precio(bombones, 340).
precio(nugaton, 150).

canastaFamiliar(leche).
canastaFamiliar(queso).
canastaFamiliar(pan).
canastaFamiliar(tortilla).
canastaFamiliar(factura).
canastaFamiliar(agua).
canastaFamiliar(jugo).
canastaFamiliar(jamonCocido).

noBebidas(a, b) :- producto(bebida, Y), producto(X, Y1), Y \= Y1, precio(Y, p), p > a, p < b.

canastaAcotada(p) :- canastaFamiliar(X), precio(X, Y), pFinal is Y * 0.85, pFinal < p.

totalPagar([], 0).
totalPagar([H | T], Total) :- canastaFamiliar(H), precio(H, Y), Descuento is Y * 0.15, p is Y - Descuento, totalPagar(T, tParcial),
				Total is p + tParcial.
totalPagar([H | T], Total) :- precio(H, Y), totalPagar(T, tParcial), Total is Y + tParcial.


