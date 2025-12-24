#include <stdio.h>
#include <stdlib.h>

struct n {
	int x;
	struct n * next;
	struct n * prev;
};

typedef struct n node;

// Fonksiyon Prototipleri
node * ekle_Sirali(node * r);
node * sil(node * r);
void bastir(node * r);
void ara(node * r);

int main() {
	node * r = NULL;
	int operation;

	while(1) {
		printf("\n************************************\n");
		printf("   DOUBLY CIRCULAR LINKED LIST\n");
		printf("1 - Ekle (Sirali)\n");
		printf("2 - Sil\n");
		printf("3 - Bastir (Traversal)\n");
		printf("4 - Eleman Ara (Search)\n");
		printf("0 - Cikis\n");
		printf(": ");
		scanf("%d", &operation);

		switch(operation) {
			case 1:
				r = ekle_Sirali(r);
				break;
			case 2:
				r = sil(r);
				break;
			case 3:
				bastir(r);
				break;
			case 4:
				ara(r);
				break;
			case 0:
				printf("Sistem kapatiliyor...\n");
				return 0;
			default:
				printf("Gecersiz islem!\n");
		}
	}
	return 0;
}

node * ekle_Sirali(node * r) {
	int x;
	printf("Eklenecek degeri girin: ");
	scanf("%d", &x);

	node * temp = (node *)malloc(sizeof(node));
	temp -> x = x;

	if(r == NULL) { // Liste bossa
		temp -> next = temp;
		temp -> prev = temp;
		printf("Ilk eleman eklendi!\n");
		return temp;
	}

	if(r -> x > x) { // Basa ekleme (Bas degisiyor)
		node * last = r -> prev;
		temp -> next = r;
		temp -> prev = last;
		r -> prev = temp;
		last -> next = temp;
		printf("Eleman basa eklendi!\n");
		return temp;
	}

	node * iter = r;
	// Dongu sarti: Bir tur donene kadar veya uygun yeri bulana kadar
	while(iter -> next != r && iter -> next -> x < x) {
		iter = iter -> next;
	}

	// Araya veya sona ekleme
	temp -> next = iter -> next;
	temp -> prev = iter;
	iter -> next -> prev = temp;
	iter -> next = temp;

	printf("Eleman sirali sekilde eklendi!\n");
	return r;
}

node * sil(node * r) {
	if(r == NULL) {
		printf("Liste zaten bos!\n");
		return NULL;
	}

	int x;
	printf("Silinecek degeri girin: ");
	scanf("%d", &x);

	node * temp;
	node * iter = r;

	if(r -> x == x) { // Bas elemani silme
		if(r -> next == r) { // Listede tek eleman varsa
			free(r);
			printf("Son eleman silindi, liste bos.\n");
			return NULL;
		}
		node * last = r -> prev;
		temp = r;
		r = r -> next;
		r -> prev = last;
		last -> next = r;
		free(temp);
		printf("Bas eleman silindi!\n");
		return r;
	}

	while(iter -> next != r && iter -> next -> x != x) {
		iter = iter -> next;
	}

	if(iter -> next == r) {
		printf("Sayi bulunamadi!\n");
		return r;
	}

	temp = iter -> next;
	iter -> next = temp -> next;
	temp -> next -> prev = iter;
	free(temp);
	printf("Eleman silindi!\n");
	return r;
}

void bastir(node * r) {
	if(r == NULL) {
		printf("Liste bos!\n");
		return;
	}
	node * iter = r;
	printf("Liste Durumu: ");
	do {
		printf("%d ", iter -> x);
		iter = iter -> next;
	} while(iter != r);
	printf("\n");
}

void ara(node * r) {
	if(r == NULL) {
		printf("Liste bos!\n");
		return;
	}
	int aranan, sayac = 0;
	printf("Aranacak degeri girin: ");
	scanf("%d", &aranan);

	node * iter = r;
	do {
		if(iter -> x == aranan) {
			printf("Deger listede mevcut!\n");
			return;
		}
		iter = iter -> next;
	} while(iter != r);

	printf("Deger bulunamadi!\n");
}
