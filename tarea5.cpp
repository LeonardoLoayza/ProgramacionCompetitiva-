// modificar el programa para modificar los nodos 
// usar functores y adaptarlo para no tener que uar 
// que sean clases LIBROS que tengan esos datos, que 
// se puedan ordenar ascendentemente o descendentemente 
// usando AUTOR O TITULO O PRECIO O CLASIFICACION
// Lista enlazada ordenada de Libros usando functores
// Se puede ordenar por: titulo, autor, precio o clasificacion
// Ascendente o descendente segun el functor que uses

#include <iostream>
#include <string>
using namespace std;

struct Libro {
	string titulo;
	string autor;
	string clasificacion;
	double precio;
};

struct Ascedente {
	bool titulo(const Libro& a, const Libro& b){
		return a.titulo > b.titulo; 
	}
		
	
	
	
};


struct PorTituloAsc { 
	bool operator()(const Libro& a, const Libro& b) {
		return a.titulo < b.titulo; 
	} 
};
struct PorTituloDesc { 
	bool operator()(const Libro& a, const Libro& b) { 
		return a.titulo > b.titulo; } 
};
struct PorAutorAsc { 
	bool operator()(const Libro& a, const Libro& b) { 
		return a.autor < b.autor; } 
};
struct PorAutorDesc { 
	bool operator()(const Libro& a, const Libro& b) { 
		return a.autor > b.autor; } 
};
struct PorPrecioAsc { 
	bool operator()(const Libro& a, const Libro& b) { 
		return a.precio < b.precio; }
};
struct PorPrecioDesc { 
	bool operator()(const Libro& a, const Libro& b) {
	return a.precio > b.precio; } 
};
struct PorClasifAsc { 	
	bool operator()(const Libro& a, const Libro& b) {
		return a.clasificacion < b.clasificacion; }
};
struct PorClasifDesc { 
	bool operator()(const Libro& a, const Libro& b) {
		return a.clasificacion > b.clasificacion; } 
};

struct CNode {
	Libro    val;
	CNode* next;
	
	CNode(Libro libro) : val(libro), next(nullptr) {}
};

template <typename Cmp>
struct Forward_List {
	CNode* head;
	int    nelem;
	Cmp    cmp;     
	
	Forward_List() : head(nullptr), nelem(0) {}
	
	bool find(const Libro& x, CNode**& p) {
		while (*p && cmp((*p)->val, x)) {
			p = &((*p)->next);
		}
		return (*p && (*p)->val.titulo == x.titulo);
	}
	
	void ins(Libro x) {
		CNode** p = &head;
		if (find(x, p)) return;         
		CNode* t = new CNode(x);
		t->next = *p;
		*p = t;
		nelem++;
	}
	
	void pop(Libro x) {
		CNode** p = &head;
		if (!find(x, p)) return;        
		CNode* borrar = *p;
		*p = borrar->next;              
		delete borrar;
		nelem--;
	}
	
	void print() const {
		CNode* p = head;
		while (p) {
			cout << "  [" << p->val.titulo << "] "
				<< "Autor: " << p->val.autor << " | "
				<< "Precio: " << p->val.precio << " | "
				<< "Clasif: " << p->val.clasificacion << "\n";
			p = p->next;
		}
	}
	
	~Forward_List() {
		CNode* p = head;
		while (p) {
			CNode* sig = p->next;
			delete p;
			p = sig;
		}
	}
};

int main() {
	Libro b1 = { "Dune", "Herbert",  "Sci-Fi",   45.00 };
	Libro b2 = { "1984","Orwell", "Distopia", 30.00 };
	Libro b3 = { "El Principito","Saint","Infantil", 20.00 };
	Libro b4 = { "Can't Hurt me","Goggins", "Self-Improvement", 55.00 };
	
	cout << "\nPor Titulo ascendetne\n";
	Forward_List<PorTituloAsc> listaTitulo;
	listaTitulo.ins(b1);
	listaTitulo.ins(b2);
	listaTitulo.ins(b3);
	listaTitulo.ins(b4);
	listaTitulo.print();
	
//	cout << "\nPor Precio\n";
//	Forward_List<PorPrecioDesc> listaPrecio;
//	listaPrecio.ins(b1);
//	listaPrecio.ins(b2);
//	listaPrecio.ins(b3);
//	listaPrecio.ins(b4);
//	listaPrecio.print();
	
//	cout << "\nPor Autor ascendente \n";
//	Forward_List<PorAutorAsc> listaAutor;
//	listaAutor.ins(b1);
//	listaAutor.ins(b2);
//	listaAutor.ins(b3);
//	listaAutor.ins(b4);
//	listaAutor.print();
//	
//	listaTitulo.pop(b1);
//	listaTitulo.print();
	
	return 0;
}
