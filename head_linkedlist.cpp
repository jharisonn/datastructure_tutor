#include <stdio.h>

// link : https://github.com/jharisonn/datastructure_tutor
// Dibuat dari banyak referensi lalu saya jadikan 1.


/* Struct Node atribut data yang bertipe integer dan mempunyai Node setelahnya yang kita namakan next
 */
struct Node{
	int data;
	Node* next;
};

/* Struct linked list sendiri adalah kumpulan semua Node. Tetapi kita menyimpan kepala dari linkedlist
 * Mengapa kita harus menyimpan kepala?
 * Karena pointer akan menunjuk alamat memori mana kita meletakkan Node pertama yang kita masukkan.
 * Dan secara default mereka masih himpunan yang hampa atau NULL
 */
struct linkedList{
	Node* head = NULL; //default value saat struct dibuat / diinstansiasi
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

/*
 * Fungsi push_back ini gunanya untuk menaruh data yang nanti dibungkus dengan struct Node
 * Lalu alamat Node yang baru kita buat akan kita masukkan kedalam Node yang sudah ada.
 * Ada 2 kemungkinan, contohnya
 * 1. linked list belum ada isinya atau masih kosong / NULL
 * Karena linked list masih kosong maka Node yang kita buat berisikan data yang kita passing.
 * 2. linked list sudah ada isinya
 * Maka kita traverse dari head sampai ketemu node terakhir yang belum ada isinya
 * Lalu kita masukkan Node yang sudah kita buat menjadi akhir dari urutan linked list.
 */
void push_back(int data){
	Node* new_node = new Node(); // Pertama kita instansiasi Node terlebih dahulu dengan variable new_node
	new_node->data = data; // Lalu kita masukkan data yang sudah kita passing dari int main() menjadi variable data yang ada di struct Node
	new_node->next = NULL; // Karena kita memasukkan data di belakang linked list maka sudah pasti NULL data setelahnya.

	if(linkedlist->head==NULL){ // Kita melakukan checking apakah linked list masih kosong / belum ada data
		linkedlist->head = new_node; // Jika iya Node yang kita buat akan kita jadikan head dari linked list tersebut.

		return; // Kita langsung exit jika kondisi sudah terpenuhi dan tidak terjadi traverse
				// Mengapa tidak menggunakan else?
				// Terkadang dalam dunia software engineering terlalu banyak if-else dapat membingungkan
				// Saya mengajarkan kalian clean code dalam dunia software engineering sejak dini :)
	}

	/*
	 * Disini kita buat node baru yang isinya adalah alamat dari headnya linked list
	 * Lalu kita traverse 1 per satu sampai menemukan Node terakhir yang dimana node setelahnya masih kosong / NULL
	 * Jika sudah ketemu maka kita masukkan node yang sudah kita buat diatas menjadi node terakhir dalam linked list
	 *
	 * Mengapa variable temp_node bisa mengubah node yang ada di linked list?
	 * Karena pointer itu menyimpan alamat maka kita bisa mengubah state di dalam linked list supaya berubah
	 * Contoh ada 2 Node dalam linked list.
	 * Alamat Node 1 = 0x001 -> head
	 * Alamat Node 2 = 0x002
	 *
	 * Lalu kita buat temp_node tanpa membuat alamat baru tetapi mengambil alamat dari head dari node linked list,
	 * yaitu 0x001 -> jadinya alamat temp_node = 0x001
	 * Jika kita traverse maka nanti alamat temp_node menyesuaikan alamat yang dilalui di linked list tanpa mengubah isi dari linked list
	 * Lalu nanti setelah sampai di Node 2 lalu kita tambahkan Node baru kita ambil contoh alamatnya 0x003
	 * Alamat Node 1 = 0x001 -> head, next = Node 2
	 * Alamat Node 2 = 0x002 -> next = Node 3
	 * Alamat Node 3 = 0x003 -> next = NULL
	 */
	Node* temp_node = linkedlist->head;
	while(temp_node->next != NULL){
		temp_node = temp_node->next;
	}

	temp_node->next = new_node;
}

/* Push front sendiri hampir mirip dengan push back dimana push front menambahkan data didepan head linked list
 * Step pertama tetap kita instansiasi Node baru lalu masukkan data
 * Step kedua adalah ketika kita mau memasukkan next node, kita harus check apakah linked list masih kosong?
 * Jika iya maka next nodenya kita set NULL dan kita exit dari fungsi tersebut.
 * Jika sudah terbuat next nodenya kita set menjadi head dari linked list sekarang , lalu
 * set Node yang kita buat menjadi head dari linked list.
 */
void push_front(int data){
	Node* new_node = new Node(); // Instansiasi Node
	new_node->data = data; // Masukkan data yang kita passing menjadi variable data dari Node
	new_node->next = (linkedlist->head == NULL) ? NULL : linkedlist->head;
					// Syntax seperti ini sudah banyak digunakan di bahasa pemrograman lain
					// Apa arti dari syntax diatas?
					// syntax yang berada di dalam () berarti
					// Apakah head dari linked list masih kosong?
					// setelah tanda ? berarti menunjukkan jika "TRUE" maka hasilnya NULL
					// setelah tanda : berarti menunjukkan jika "FALSE" maka hasilnya adalah linkedlist->head
					// Jadi bisa kita simpulkan
					// Next node dari Node yang kita buat akan berisi :
					// 1. NULL jika head dari linked list, jika linked list masih kosong / NULL
					// 2. head dari linked list sekarang, jika linked list sudah terisi


	linkedlist->head = new_node; // Kita set head dari linked list menjadi Node yang baru kita buat.

}


/*
 * Untuk iterasi linked list agak sedikit berbeda
 * Pertama kita buat node yang merepresentasikan dari head linked list.
 * Lalu kita iterasi sampai nodenya null
 */
void display(){
	Node* display_node = linkedlist->head; // Kita buat struct Node dengan variable node
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
	while(display_node!=NULL){
		int data = display_node->data;
		printf("%d\n",data);
		display_node = display_node->next;
	}
}

int main(){
	push_front(17);
	push_back(5);
	push_back(15);

	display();
}
