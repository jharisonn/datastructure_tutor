#include <stdio.h>

//link : https://github.com/jharisonn/datastructure_tutor

/* Struct Node atribut data yang bertipe integer dan mempunyai Node setelahnya yang kita namakan next
 */
struct Node{
	int data;
	Node* next;
};

/* Struct linked list sendiri adalah kumpulan semua Node. Tetapi kita menyimpan kepala dan ekor dari linkedlist
 * Mengapa kita harus menyimpan kepala?
 * Karena pointer akan menunjuk alamat memori mana kita meletakkan Node pertama yang kita masukkan.
 * Mengapa kita harus menyimpan ekornya?
 * Karena jika kita tidak menyimpan ekor untuk melakukan operasi push_back kompleksitasnya adalah O(n),
 * dimana kita harus iterasi dari 0...N untuk melakukan penambahan sebuah data.
 * Dan secara default mereka masih himpunan yang hampa atau NULL
 */
struct linkedList{
	Node* head = NULL; //default value
	Node* tail = NULL; //default value
};

/* Kita instansiaikan struct linkedList dengan nama variable linkedlist
 * Lalu setelah itu kita alokasikan memori untuk variable linkedlist (new linkedList())
 * atau bisa kita instansikan sama seperti dibawah ini
 * linkedList* linkedlist = (linkedList*) malloc(sizeof(linkedList));
 * atau
 * linkedList* linkedlist = (struct linkedList*) malloc(sizeof(struct linkedList));
 * Ketiga hal itu sama saja. malloc adalah kependekan dari memory allocation
 */
linkedList* linkedlist = new linkedList();


/* Saat kita memanggil fungsi push_back,
 * kita akan membuat Node baru dengan atribut data yang isinya adalah value yang mau kita masukkan kedalam linked list
 * Lalu ada 2 kemungkinan disini
 * 1. Linked List masih kosong
 * Flag dari terisi atau bukannya bisa kita lihat apakah head dari Linked List itu NULL atau tidak
 * Jika head dari LinkedList NULL sudah dipastikan Linked List itu masih kosong
 * Karena masih kosong maka kita masukkan Node baru yang kita buat kedalam head dan tail dari Linked List itu sendiri.
 * Mengapa head dan tail yang kita masukkan?
 * Karena jumlah node dalam linked list masih 1 buah node, yang bisa merepresentasikan head dan tail.
 *
 * 2. Linked List sudah terisi
 * Kalau sudah terisi maka kita ambil tail dari linked list
 * Lalu dari node yang sudah terbuat itu kita masukkan kedalam Node next punya tail yang kita ambil
 * Lalu set Tail baru dari linked list menjadi node yang sudah kita buat.
 */
void push_back(int data){
	Node* node = new Node(); // Instansiasi Node baru
	node->data = data; // Masukkan variable data kedalam variable data yang ada di struct Node
	node->next = NULL; // Karena sudah pasti Node dibelakang linked list adalah NULL, maka kita set NULL untuk variable next
					   // di dalam struct Node

	if(linkedlist->head==NULL){  // Jika head dari linked list tidak ada atau linked list masih kosong
		linkedlist->head = node; // Maka kita masukkan node yang sudah kita buat kedalam variable head
		linkedlist->tail = node; // dan head dari struct linked list.

		return; // Kita return supaya fungsi untuk melakukan perpindahan tail tidak berjalan
				// Mengapa tidak menggunakan else?
				// Terkadang dalam dunia software engineering terlalu banyak if-else dapat membingungkan
				// Saya mengajarkan kalian clean code dalam dunia software engineering sejak dini :)
	}

	linkedlist->tail->next = node; // Pertama kita ambil tail yang berada di linked list sekarang
								   // Lalu node yang sudah kita buat diatas, kita masukkan menjadi next dari tail sekarang.
	linkedlist->tail = node; // Karena tail nya sudah berubah menjadi node yang sudah kita buat
							 // Maka kita update status tail yang ada di linked list menjadi node yang kita baru buat.
}

/* Push front sendiri hampir mirip dengan push back dimana push front menambahkan data didepan head linked list
 * Step pertama tetap kita instansiasi Node baru lalu masukkan data
 * Step kedua adalah ketika kita mau memasukkan next node, kita harus check apakah linked list masih kosong?
 * Jika iya maka next nodenya kita set NULL dan kita exit dari fungsi tersebut.
 * Jika sudah terbuat next nodenya kita set menjadi head dari linked list sekarang , lalu
 * set Node yang kita buat menjadi head dari linked list.
 */
void push_front(int data){
	Node* node = new Node(); // Instansiasi Node
	node->data = data; // Masukkan data yang kita passing menjadi variable data dari Node
	node->next = (linkedlist->head==NULL) ? NULL : linkedlist->head;
				// Syntax seperti ini sudah banyak digunakan di bahasa pemrograman lain
				// Apa arti dari syntax diatas?
				// syntax yang berada di dalam () berarti :
				// Apakah head dari linked list masih kosong?
				// setelah tanda ? berarti menunjukkan "TRUE"
				// setelah tanda : berarti menunjukkan "FALSE"
				// Jadi bisa kita simpulkan
				// Next node dari Node yang kita buat akan berisi :
				// 1. NULL jika head dari linked list, jika linked list masih kosong / NULL
				// 2. head dari linked list sekarang, jika linked list sudah terisi

	if(linkedlist->head==NULL){ // Jika head dari linked list kosong maka akan masuk fungsi ini
		linkedlist->head = node; // Head dari linked list yang masih kosong akan di set menjadi node yang kita buat.
		linkedlist->tail = node; // Tail dari linked list yang masih kosong akan di set menjadi node yang kita buat.

		return; // Kita langsung exit dari fungsi. Penjelasan ada di fungsi push_back
	}

	linkedlist->head = node; // Kita set head dari linked list menjadi Node yang baru kita buat.
}

/*
 * Untuk iterasi linked list agak sedikit berbeda
 * Pertama kita buat node yang merepresentasikan dari head linked list.
 * Lalu kita iterasi sampai node nextnya null
 */
void display(){
	Node* node = linkedlist->head; // Kita buat struct Node dengan variable node
								   // Karena node ini representasi head dari linked list
								   // Dan kita tidak mau kehilangan semua data yang ada di linked list
								   // Maka kita masukkan kedalam variable baru ( kita buat copy-an dari headnya linked list)
								   // Karena tipe data head linked list adalah Node maka kita gunakan struct Node* node.

	/*
	 * Selama node sekarang tidak NULL, maka kita masukkan data yang ada di node kedalam variable integer baru
	 * yang kita beri nama data.
	 * Lalu kita print data tersebut.
	 * Setelah itu nodenya kita ganti menjadi next nodenya.
	 * Contoh.
	 * Node = {17, *next}
	 * data = 17, next* = node {5, *next}
	 * Setelah kita print, maka nodenya kita ganti menjadi variable next
	 * Node = {5,*next}
	 * Kita lakukan langkah diatas sampai dia melewati node yang NULL atau kosong.
	 */
	while(node!=NULL){
		int data = node->data;
		printf("%d\n",data);
		node = node->next;
	}
}

int main(){
	push_back(5);
	push_back(10);
	push_front(17);
	display();
}
